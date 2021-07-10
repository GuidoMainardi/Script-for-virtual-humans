#include "CrowdController.h"
#include "NavigationSystem.h"
#include "MarkerVis.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/TextRenderComponent.h"
#include "Engine/TextRenderActor.h"
#include "Kismet/GameplayStatics.h"
#include "DrawDebugHelpers.h"


//----------------------------------------------------------FUNCTIONS FOR SETUP----------------------------------------------------------

ACrowdController::ACrowdController() : sampler() {
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;
}

//checks if nav tile is valid
bool TileIsValid(const ARecastNavMesh* NavMesh,int32 TileIndex) {
    if(!NavMesh) return false;
    const FBox TileBounds = NavMesh->GetNavMeshTileBounds(TileIndex);
    return TileBounds.IsValid != 0;
}

//generates samples for navmesh polygons
void ACrowdController::CreateSamples() {
    //get world and navmesh
    UNavigationSystemV1* navSys = FNavigationSystem::GetCurrent<UNavigationSystemV1>(GetWorld());
    ARecastNavMesh* navMesh = navSys ? Cast<ARecastNavMesh>(navSys->GetDefaultNavDataInstance()) : nullptr;

    TArray<FNavPoly> EachPolys;
    if (navMesh == nullptr) {
        return;
    }

    for(int32 v = 0; v < navMesh->GetNavMeshTilesCount(); v++)  {
        if(!TileIsValid(navMesh,v)) { continue; }
        navMesh->GetPolysInTile(v, EachPolys);
    }

    TArray<NavNodeRef> Polys;
    for(int32 v = 0; v < EachPolys.Num(); v++) {
        TArray<NavNodeRef> n;
        navMesh->GetPolyNeighbors(EachPolys[v].Ref, n);
        if (n.Num() != 0) {
            Polys.Add(EachPolys[v].Ref);
        }
    }

    TArray<TArray<FVector>> Verts;
    for (int32 i = 0; i < Polys.Num(); i++) {
        TArray<FVector> OutVerts;
        navMesh->GetPolyVerts(Polys[i], OutVerts);
        Verts.Add(OutVerts);
    }

    sampler.generateSamples(numSamples, Verts);
}

//builds kd-tree to store generated samples
void ACrowdController::BuildKDT() {
    TArray<FVector*> particlePtrs;
    for(int i = 0; i < sampler.samples.Num(); i++) {
        particlePtrs.Add(&(sampler.samples[i]));
    }

    kdt.build(particlePtrs);
}

//----------------------------------------------------------BIOCROWDS----------------------------------------------------------


//weighting function for algorithm
float ACrowdController::f(FVector x, FVector y) {
    float first = 1.f / (1.f + y.Size());

    float second = 1.f + (FVector::DotProduct(x, y) / x.Size() * y.Size());

    return first * second;
}

//for each agent, search in radius for markers and reassign to agent
//if already has agent, check which is closer
void ACrowdController::reassignMarkers(TArray<AAgent*> finished) {
    //clear markers for agents that need updating
    for (AAgent* i : finished) {
        for (BMarker* mark : i->markers) {
            mark->agent = nullptr;
        }
        i->markers.Empty();
    }


    for (AAgent* i : finished) {
        FVector pos = i->GetActorLocation();
        pos.Z -= 44;
        TArray<BMarker*> ms = kdt.particlesInSphere(pos, i->radius);

        for (BMarker* m : ms) {

            //GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Distance: %f"), FVector::Distance(pos, m->pos)));


            //also check if the agent is finished??
            if (m->agent != nullptr) {
                if (finished.Contains(m->agent)) {
                    if (FVector::Distance(m->pos, m->agent->GetActorLocation()) > FVector::Distance(m->pos, i->GetActorLocation())) {
                        //remove marker from prev agent's list
                        m->agent->markers.Remove(m);
                        m->agent = i;
                        i->markers.Add(m);
                    }
                }
            } else {
                m->agent = i;
                i->markers.Add(m);
            }
        }
    }
}

void ACrowdController::update(TArray<AAgent*> finished) {
    //fixed z differences-will need to change when add vertical movement

    //for each agent, compute weights then motion vector
    for (AAgent* i : finished) {
        FVector actP = i->GetActorLocation();
        actP.Z = 1;
        //actP.Z -= 86;

        FVector goalP = i->goal;
        goalP.Z = 1;

        //get sum of weights
        float sum = 0.f;
        for (int t = 0; t < i->markers.Num(); t++) {
            //FVector markP = i->markers[t]->pos;
            FVector markP = FVector(i->markers[t]->pos.X, i->markers[t]->pos.Y, 1);
            FVector a = goalP - actP;
            a.Normalize();
            FVector b = markP - actP;
            b.Normalize();
            sum += f(a, b);
            //sum += f(goalP - actP, markP - actP);
        }

        // GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Sum: %f"), sum));


        //compute motion vector
        FVector motv(0.f);
        for (int t = 0; t < i->markers.Num(); t++) {
            //FVector markP = i->markers[t]->pos;
            FVector markP = FVector(i->markers[t]->pos.X, i->markers[t]->pos.Y, 1);

            FVector a = goalP - actP;
            a.Normalize();
            FVector b = markP - actP;
            b.Normalize();

            float wk = f(a, b) / FMath::Abs(sum); //unsure if sum is supposed to be absolute, but agents move weird otherwise FMath::Abs(sum)


            FVector dir = (markP - actP);
            //dir.Normalize();
            motv += wk * dir;
        }

        //compute velocity
        motv.Z = 0;

        //GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Motv Size: %f"), motv.Size()));

        float s = FMath::Min(motv.Size(), i->maxV);
        FVector v = s * (motv / motv.Size());

        //GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("V Size: %f"), v.Size()));


        /*if (v.X < 0) {
         v.X += i->GetSimpleCollisionRadius();
         } else {
         v.X -= i->GetSimpleCollisionRadius();
         }

         if (v.Y < 0) {
         v.Y += i->GetSimpleCollisionRadius();
         } else {
         v.Y -= i->GetSimpleCollisionRadius();
         }*/

        //update pos
        i->GetCharacterMovement()->MaxWalkSpeed =  100; //v.Size();
        i->currTarget = i->GetActorLocation() + v;
    }
}

TArray<AFollower*> ACrowdController::CreateFollowers(AAgent* lead, FVector leaderloc, int numFollow, ARecastNavMesh* navMesh, FNavLocation g, int depth) {
    if (depth == 0) {
        return TArray<AFollower*>();
    }

    TArray<AFollower*> follows;
    for (int i = 0; i < numFollow; i++) {
        FNavLocation followloc;

        float offsetBack = -100 * depth;
        float offsetRight;
        if (i % 2 == 0) {
            offsetRight = -100 * depth * (i+1);
        } else {
            offsetRight = 100 * depth * (i);
        }

        FVector behind = leaderloc + (lead->GetActorForwardVector() * offsetBack) + (lead->GetActorRightVector() * offsetRight);

        navMesh->GetRandomPointInNavigableRadius(behind, 1, followloc);

        AFollower* agent = GetWorld()->SpawnActor<AFollower>(FVector(followloc.Location.X, followloc.Location.Y, followloc.Location.Z), FRotator::ZeroRotator);
        //GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("HI")));

        if (agent != nullptr) {
            GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("HELLO")));

            //DISPLAY TEXT ABOVE HEAD
            ATextRenderActor* atxt = GetWorld()->SpawnActor<ATextRenderActor>(ATextRenderActor::StaticClass(), FVector(followloc.Location.X, followloc.Location.Y, followloc.Location.Z + 200), FRotator(0.f));
            atxt->GetTextRender()->SetText(FText::FromString(TEXT("Follower")));
            atxt->GetTextRender()->SetTextRenderColor(FColor::Red);
            agent->text = atxt;
            // set agent goal
            agent->init(FVector(g.Location.X, g.Location.Y, g.Location.Z + 90), agentV, agentR, duration, WidgetBPRef);
            agent->currTarget = agent->GetActorLocation();
            agent->SpawnDefaultController();

            //for random lines
            agent->parent = lead;
            agent->offsetBack = offsetBack;
            agent->offsetRight = offsetRight;

            follows.Add(agent);

            AAgent* casted = Cast<AAgent>(agent);
            if (casted != nullptr) {
                TArray<AFollower*> nextFollows = CreateFollowers(casted, followloc, 1, navMesh, g, depth - 1);
                for (AFollower* af : nextFollows) {
                    follows.Add(af);
                }
            }
        }
    }
    return follows;
}

//----------------------------------------------------------SETUP ON BEGIN PLAY----------------------------------------------------------


// Called when the game starts or when spawned
void ACrowdController::BeginPlay() {
    Super::BeginPlay();
    scene = Scenario();
    //numAgents = 2;
    numAgents = scene.load();
    time = 0.0f;
    int line = 0;
    int LocalNumberOfAgents = 0;
    //set up the space with markers
    CreateSamples();
    BuildKDT();

    UNavigationSystemV1* navSys = FNavigationSystem::GetCurrent<UNavigationSystemV1>(GetWorld());
    ARecastNavMesh* navMesh = navSys ? Cast<ARecastNavMesh>(navSys->GetDefaultNavDataInstance()) : nullptr;
    FBox bounds =  navMesh->GetNavMeshBounds();
    FVector c = bounds.GetCenter();
    FVector max = bounds.Max;
    FVector min = bounds.Min;


    //find all regions and store
    TArray<AActor*> regions;
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), ARegionBox::StaticClass(), regions);
    FString RegionName;
    for (int i = 0; i < regions.Num(); i++) {
        ARegionBox* r = Cast<ARegionBox>(regions[i]);
        regsVacant.Add(r);
        const FTransform world = r->MyPtr->GetComponentTransform();
        FBoxSphereBounds bsb = r->MyPtr->CalcBounds(world);
        r->box = bsb.GetBox();
        RegionName = regions[i]->GetName();
        Locais.Add(RegionName, i);
    }


    int actualNumAgents = 0;
    //random goal setup
    if (regsVacant.Num() != 0) {
        for (int i = 0; i < numAgents; i++) {
            //pick quad
            if (LocalNumberOfAgents >= scene.text[line].getNumberOf()) {
                LocalNumberOfAgents = 0;
                line++;
            }
            LocalNumberOfAgents++;
            int idx = get_LocationIndex(scene.text[line].getRegionName().c_str());
            ARegionBox* addinbox = regsVacant[idx];
            addinbox->ProfilesInThisPlace.Add(scene.text[line].getProfile().c_str());
            FBox quad = regsVacant[idx]->box;
            regsVacant[idx]->numAgents++;

            FNavLocation loc;
            FVector center = quad.GetCenter();
            float dist1 = FVector::Distance(center, FVector(center.X, quad.Max.Y, center.Z));
            float dist2 = FVector::Distance(center, FVector(quad.Min.X, center.Y, center.Z));
            navMesh->GetRandomPointInNavigableRadius(center, FMath::Min(dist1, dist2), loc);

            //FNavLocation loc = navMesh->GetRandomPoint();
            // =================================================================================================================
            AAgent* agent = GetWorld()->SpawnActor<AAgent>(FVector(loc.Location.X, loc.Location.Y, loc.Location.Z + 90), FRotator::ZeroRotator); // spawn agent
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Location: x: %f, y: %f, z: %f"),
				loc.Location.X,
				loc.Location.Y,
				loc.Location.Z));

            if (agent != nullptr) {
                //DISPLAY TEXT ABOVE HEAD
                //ATextRenderActor* Text = GetWorld()->SpawnActor<ATextRenderActor>(ATextRenderActor::StaticClass(), FVector(loc.Location.X, loc.Location.Y, loc.Location.Z + 200), FRotator(0.f));
                //Text->GetTextRender()->SetText(FText::FromString(TEXT("Walking")));
                //Text->GetTextRender()->SetTextRenderColor(FColor::Red);
                //agent->text = Text;

                agent->reg = regsVacant[idx];
                agents.Add(agent);
                actualNumAgents++;
            }
        }

        //POTENTIALLY CHECK IF CHOOSING SAME REGION AS IN?

        for (int i = 0; i < actualNumAgents; i++) {
            AAgent* agent = agents[i];
            FBox q;

            //if none vacant, choose from full
            if (regsVacant.Num() == 0) {
                //pick quad
                int idx = FMath::RandRange(0, regsFull.Num() - 1);
                ARegionBox* r = regsFull[idx];
                q = r->box;

                //increase and decrease num agents
                r->numAgents++;
                agent->reg->numAgents--;

                //if agent's last reg was full
                if (regsFull.Contains(agent->reg)) {
                    regsVacant.Add(agent->reg);
                    regsFull.Remove(agent->reg);
                }

                agent->reg = r;
            } else {
                int idx = FMath::RandRange(0, regsVacant.Num() - 1);
                ARegionBox* r = regsVacant[idx];
                q = r->box;

                //increase and decrease num agents
                r->numAgents++;
                agent->reg->numAgents--;

                if (regsFull.Contains(agent->reg)) {
                    regsVacant.Add(agent->reg);
                    regsFull.Remove(agent->reg);
                }
                agent->reg = r;
            }

            //get activity
            //int32 num = agent->reg->activities.Num();
            //int32 rand = FMath::RandRange(0, num - 1);
            //FString acty = "Test";// agent->reg->activities[rand];

            //agent->activity = acty;

            FNavLocation g; // Agent Goal
            float d1 = FVector::Distance(q.GetCenter(), FVector(q.GetCenter().X, q.Max.Y, q.GetCenter().Z));
            float d2 = FVector::Distance(q.GetCenter(), FVector(q.Min.X, q.GetCenter().Y, q.GetCenter().Z));
            navMesh->GetRandomPointInNavigableRadius(q.GetCenter(), FMath::Min(d1, d2), g);

            // set Goal
            agent->init(FVector(agent->GetActorLocation().X, agent->GetActorLocation().Y, agent->GetActorLocation().Z + 90), agentV, agentR, duration, WidgetBPRef);
            agent->currTarget = agent->GetActorLocation();
            agent->SpawnDefaultController();

            agent->finalGoal = agent->GetActorLocation();

            //find path to goal
            UNavigationPath* p = navSys->FindPathToLocationSynchronously(GetWorld(), agent->GetActorLocation(), agent->goal, NULL);
            TArray <FVector> path = p->PathPoints;
            agent->path = path;
            agent->goal = path[0];
            agent->goal.Z += 90;
            agent->path.RemoveAt(0);
        }
    }

    // load profiles
    
    int counter = 0;
    while (scene.text[scene.pc].getOperation() == Operation::CREATE || scene.text[scene.pc].getOperation() == Operation::WHEN){
        ScriptCommand c = scene.text[scene.pc];
        if (c.getOperation() == Operation::CREATE) {
            for (int i = 0; i < c.getNumberOf(); i++) {
                if (counter < agents.Num()) {
                    agents[counter]->profile_Name = c.getProfile().c_str();
                    agents[counter]->CurrentLocation = c.getRegionName().c_str();
                    // check if has model
                    if (c.gethasModel()) {
                        agents[counter]->setNewModel(c.getModel().c_str());
                        agents[counter]->modelName = c.getModel().c_str();
                    }
                    counter++;
                
                }
            }
        }else if (c.getOperation() == Operation::WHEN) {
            FString condition = c.getRegionName().c_str();
            condition += " ";
            condition += c.getProfile().c_str();
            if (!conditionsEvents.Contains(condition)) {
                conditionsEvents.Add(condition);
            }
            conditionsEvents[condition].Add(*c.getEvent());
        }
        else { break; }
        if (scene.pc + 1 >= scene.text.size()) {
            scene.pc++;
            break;
        }
        scene.pc++;
    }
}

// random location funcition
int ACrowdController::get_LocationIndex(FString regionName) {
    int idx;
    if (regionName.ToLower().Contains("random")) {
        FString region_flag = "Place";
        FString left;
        if (regionName.Contains(" ")) {
            regionName.Split(TEXT(" "), &left, &region_flag);

        }
        TArray<int> indexes;
        for (int j = 0; j < regsVacant.Num(); j++) {
            ARegionBox* atual = regsVacant[j];
            if (atual->Flags.Contains(region_flag)) {
                indexes.Add(j);
            }
        }
        if (indexes.Num()) {
            idx = indexes[FMath::RandRange(0, indexes.Num() - 1)];
        }
        else {
            UE_LOG(LogTemp, Warning, TEXT("RegionBox Not Found! : %s"), *regionName);
            idx = get_LocationIndex("Random");
        }
        
    }
    else {
        if (Locais.Contains(regionName)) {
            idx = Locais[regionName];
        }
        else {
            UE_LOG(LogTemp, Warning, TEXT("RegionBox Not Found! : %s"), *regionName);
            idx = get_LocationIndex("Random");
        }
    }
    return idx;
}

// Playing Main Script funcions

//play script command
void ACrowdController::Run_MainScriptCommand(ScriptCommand command) {
    
    if (command.getIsAll()) { // all profile operations
        for (auto agent : agents) {
            if (agent->profile_Name == command.getProfile().c_str()) {
                Run_SimpleOperation(command, agent);
            }
        }
    }
    else { // simple profile operation
        auto agent = agents[command.getTargetID() - 1];
        Run_SimpleOperation(command, agent);
    }
    
    
}

// run operation
void ACrowdController::Run_SimpleOperation(ScriptCommand command, AAgent* agent) {
    
    if (command.getOperation() == Operation::RUN) {
        Run_OperationRUN(command, agent);
    }
    else if (command.getOperation() == Operation::STOP) {
        Run_OperationSTOP(command, agent);
    }
    else if (command.getOperation() == Operation::LOOP) {
        Run_OperationLOOP(command, agent);
    }
    else {
        UE_LOG(LogTemp, Warning, TEXT("Dangerous area!"));
    }
}

// run run hehe
void ACrowdController::Run_OperationRUN(ScriptCommand command, AAgent* agent) {
    agent->nowPlaying = FString(command.getBehaviour().c_str());
    agent->hasSomethingToPlay = true;
    agent->pc = 0;
    agent->inLoop = false;
    agent->inAction = false;
    agent->inAnim = false;

}

// run stop
void ACrowdController::Run_OperationSTOP(ScriptCommand command, AAgent* agent) {
    agent->nowPlaying = "";
    agent->goal = agent->GetActorLocation();
    agent->hasSomethingToPlay = false;
    agent->inLoop = false;
    agent->inAction = false;
    agent->inAnim = false;
}

// run loop
void ACrowdController::Run_OperationLOOP(ScriptCommand command, AAgent* agent) {
    agent->nowPlaying = FString(command.getBehaviour().c_str());
    agent->hasSomethingToPlay = true;
    agent->pc = 0;
    agent->inLoop = true;
    agent->inAction = false;
    agent->inAnim = false;
}

// behaviour script functions
void ACrowdController::Run_AgentBehaviour(AAgent* agent, float DeltaTime)  {

    int number_script_instructions = scene.Scripts.find(string(TCHAR_TO_UTF8(*agent->nowPlaying)))->second.text.size();
    bool isAgentFree = !agent->inAction && !agent->inAnim;
    
    if (agent->pc >= number_script_instructions && isAgentFree) {
        Run_EndScript(agent);
    } 
    if (isAgentFree && agent->pc < number_script_instructions && agent->hasSomethingToPlay) {
        Run_BehaviourOperation(agent);     
    }
    Run_EndAction(agent, DeltaTime);
}

// check script end  and finish all actions
void ACrowdController::Run_EndScript(AAgent* agent) {
    // if agent not in loop end the run section
    if (!agent->inLoop) { 
        agent->hasSomethingToPlay = false;
    }
    agent->pc = 0; 
}

// run simple behaviour operation
void ACrowdController::Run_BehaviourOperation(AAgent* agent) {
    BehaviourCommand bc = scene.Scripts.find(string(TCHAR_TO_UTF8(*agent->nowPlaying)))->second.text[agent->pc];
    agent->inAction = true;

    if (bc.getOpcode() == Opcode::GO) {
        Run_OpCodeGo(agent, bc.getDestiny().c_str());
    }

    if (bc.getOpcode() == Opcode::PLAY) {
        Run_OpCodePlay(agent, bc.getDestiny().c_str());
    }
}

// run go to behaviour
void ACrowdController::Run_OpCodeGo(AAgent* agent, FString Destiny) {
    // reseting animation
    agent->animtime = 0.f;
    agent->inAnim = false;
    agent->MySkeleton->SetAnimInstanceClass(agent->DefaultAnims[agent->modelName]->GeneratedClass);
    agent->waiting_time = 0;

    UNavigationSystemV1* navSys = FNavigationSystem::GetCurrent<UNavigationSystemV1>(GetWorld());
    ARecastNavMesh* navMesh = navSys ? Cast<ARecastNavMesh>(navSys->GetDefaultNavDataInstance()) : nullptr;
    // remove agent in old regionbox
    int idx = NewPositions(agent, Destiny);

    // get target region box
    FBox quad = regsVacant[idx]->box;
    FNavLocation loc;
    //get regionbox's region
    FVector center = quad.GetCenter();
    float dist1 = FVector::Distance(center, FVector(center.X, quad.Max.Y, center.Z));
    float dist2 = FVector::Distance(center, FVector(quad.Min.X, center.Y, center.Z));
    // get a random regionbox's point
    navMesh->GetRandomPointInNavigableRadius(center, FMath::Min(dist1, dist2), loc);

    // positionate the goal
    FVector goal(loc.Location.X, loc.Location.Y, loc.Location.Z);
    agent->goal = goal;
    agent->goal.Z += 90;

    //setgoal
    agent->finalGoal = agent->goal;

    //find path to goal
    UNavigationPath* p = navSys->FindPathToLocationSynchronously(GetWorld(), agent->GetActorLocation(), agent->goal, NULL);
    TArray <FVector> path = p->PathPoints;
    agent->path = path;
    agent->goal = path[0];
    agent->goal.Z += 90;
    agent->path.RemoveAt(0);
    agent->inAction = true;

}

// run play behaviour
void ACrowdController::Run_OpCodePlay(AAgent* agent, FString animation) {
    //reseting goal
    agent->goal = agent->GetActorLocation();

    agent->inAnim = true;
    agent->playAnimation(animation);
}

// end the action the agent is playing and go to the next one
void ACrowdController::Run_EndAction(AAgent* agent, float DeltaTime) {
    float dist = FVector::Distance(agent->GetActorLocation(), agent->finalGoal);
    FVector vel = agent->GetVelocity();
    if (FMath::Abs(vel.X) == 0 && FMath::Abs(vel.Y) == 0) {
        agent->waiting_time += DeltaTime;
    }
    if (dist < 90 || agent->waiting_time > 3.f){
        if (agent->inAction) {
            agent->inAction = false;
        }
        if (agent->inAnim) {
            agent->animtime += DeltaTime;
            if (agent->animtime >= agent->Animations[agent->AnimName]->GetPlayLength()) {
                agent->animtime = 0.f;
                agent->inAnim = false;
                agent->MySkeleton->SetAnimInstanceClass(agent->DefaultAnims[agent->modelName]->GeneratedClass);
            }
        }
        if (!agent->inAction && !agent->inAnim) {
            agent->pc++;
        }
    }
    
}

// event handler
void ACrowdController::EventHandler() {

    for (auto Event : conditionsEvents) {
        FString profile;
        FString place;
        Event.Key.Split(TEXT(" "), &place, &profile);
        int idx = get_LocationIndex(place);
        ARegionBox* placeBox = regsVacant[idx];
        if (placeBox->ProfilesInThisPlace.Contains(profile)) {
            placeBox->ProfilesInThisPlace.Remove(profile);
            for (auto command : Event.Value) {
                FString comando = command.toString().c_str();
                //UE_LOG(LogTemp, Warning, TEXT("Cheguei aqui com o comando: %s"), *comando);
                Run_MainScriptCommand(command);
            }
            
        }
    }
}

int ACrowdController::NewPositions(AAgent* agent, FString Destiny) {
    // get atual region box
    int idx = get_LocationIndex(agent->CurrentLocation);
    ARegionBox* currentbox = regsVacant[idx];
    // remove from atualregion box
    currentbox->ProfilesInThisPlace.Remove(agent->profile_Name);
    

    // add agent in new regionbox
    idx = get_LocationIndex(Destiny);
    ARegionBox* newbox = regsVacant[idx];
    newbox->ProfilesInThisPlace.Add(agent->profile_Name);
    if (!agent->CurrentLocation.Equals(Destiny)) {
        EventHandler();
    }
    agent->CurrentLocation = newbox->GetName();
    return idx;
}

//----------------------------------------------------------UPDATE EVERY TICK----------------------------------------------------------
// Called every frame
void ACrowdController::Tick(float DeltaTime) {
    Super::Tick(DeltaTime);

    UNavigationSystemV1* navSys = FNavigationSystem::GetCurrent<UNavigationSystemV1>(GetWorld());
    ARecastNavMesh* navMesh = navSys ? Cast<ARecastNavMesh>(navSys->GetDefaultNavDataInstance()) : nullptr;
    time += DeltaTime;
    // play every fuction in main script (otimization - make a program counter to know wich command execute / cons program need to be in order of time
    if (scene.pc < scene.text.size()) {
        while (scene.text[scene.pc].getTime() <= int(time)) {
            if (scene.pc < scene.text.size()) {
                ScriptCommand command = scene.text[scene.pc];
                Run_MainScriptCommand(command);
            }
            else { break;  }
            scene.pc++;
        }
    }
    // for each agent, play the detinated behavour
    for (AAgent* agent : agents) {
        Run_AgentBehaviour(agent, DeltaTime);
    }
    // ============================================  Script code ends here =========================================================
   
    //Update goals
    //gather agents done moving
    TArray<AAgent*> afinished;
    TArray<AAgent*> finished;
    for (AAgent* a : agents) {
        
        /*if (a->showGoal) {
            DrawDebugDirectionalArrow(GetWorld(), FVector(a->GetActorLocation().X, a->GetActorLocation().Y, a->GetActorLocation().Z + 30),
                                      FVector(a->finalGoal.X, a->finalGoal.Y, a->finalGoal.Z + 30),
                                      200, FColor::Red, false);
        }*/

        //a->text->SetActorLocation(FVector(a->GetActorLocation().X, a->GetActorLocation().Y, a->GetActorLocation().Z + 200));
        FVector vel = a->GetVelocity();
        float dist = FVector::Distance(a->GetActorLocation(), a->currTarget);
        if (dist < 5 || (FMath::Abs(vel.X) == 0 && FMath::Abs(vel.Y) == 0)) {
            afinished.Add(a);
            finished.Add(a);
        }
    }


    reassignMarkers(finished);
    update(finished);

    for (AAgent* a : afinished) {
        float dist = FVector::Distance(a->GetActorLocation(), a->goal);
        if (dist > 100) {
            AAIController* ac = Cast<AAIController>(a->GetInstigatorController());

            FVector m = a->currTarget;

            ac->MoveToLocation(a->currTarget, -1, false);
        } else {
            if (a->path.Num() > 0) {
                a->goal = a->path[0];
                a->goal.Z += 90;
                a->path.RemoveAt(0);
            } else {
                if (a->ticks == 0) {
                    //a->text->GetTextRender()->SetText(FText::FromString(a->activity));
                    //a->text->GetTextRender()->SetTextRenderColor(FColor::Green);
                    a->ticks++;
                } else if (a->ticks >= a->duration) {
                    FBox q;
                    //if none vacant, choose from full
                    if (regsVacant.Num() == 0) {
                        //pick quad
                        int idx = FMath::RandRange(0, regsFull.Num() - 1);
                        ARegionBox* r = regsFull[idx];
                        q = r->box;

                        //increase and decrease num agents
                        r->numAgents++;
                        a->reg->numAgents--;


                        a->reg = r;
                    } else {
                        int idx = FMath::RandRange(0, regsVacant.Num() - 1);
                        ARegionBox* r = regsVacant[idx];
                        q = r->box;

                        //increase and decrease num agents
                        r->numAgents++;
                        a->reg->numAgents--;

                        if (regsFull.Contains(a->reg)) {
                            regsVacant.Add(a->reg);
                            regsFull.Remove(a->reg);
                        }
                        a->reg = r;
                    }
                } else {
                    a->ticks++;
                }
            }
        }
    }
}
