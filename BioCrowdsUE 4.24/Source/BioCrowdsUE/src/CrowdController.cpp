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
    tempo = 0.0f;
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
    UE_LOG(LogTemp, Warning, TEXT("%d"), regions.Num());
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
    int actualNumAgents = 0; // numero de agentes
    //random goal setup
    if (regsVacant.Num() != 0) {
        for (int i = 0; i < numAgents; i++) {
            //pick quad
            if (LocalNumberOfAgents >= scene.text[line].getNumberOf()) {
                LocalNumberOfAgents = 0;
                line++;
            }
            LocalNumberOfAgents++;
            //int idx = FMath::RandRange(0, regsVacant.Num() - 1);
            //UE_LOG(LogTemp, Warning, TEXT("Quadrante inicial: %d"), Locais[scene.text[line].getRegionName().c_str()]);
            int idx;
            FString regionName = scene.text[line].getRegionName().c_str();
            if (regionName.ToLower().Contains("random")) {
                FString region_flag = "Place";
                FString left;
                if (regionName.Contains(" ")) {
                   regionName.Split(TEXT(" "), &left, &region_flag);
                    
                }
                UE_LOG(LogTemp, Warning, TEXT("Quadrante inicial: %s"), *region_flag);
                TArray<int> indexes;
                for (int j = 0; j < regsVacant.Num(); j ++) {
                    ARegionBox* atual = regsVacant[j];
                    if (atual->Flags.Contains(region_flag)) {
                        indexes.Add(j);
                    }
                }
                idx = indexes[FMath::RandRange(0, indexes.Num() - 1)];
            }
            else {
                idx = Locais[regionName];
            }
            //UE_LOG(LogTemp, Warning, TEXT("Quadrante inicial: %s"), *regsVacant[idx]->GetName());
            FBox quad = regsVacant[idx]->box;
            regsVacant[idx]->numAgents++;
            //GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("NUM AGENTS = %i"), regsVacant[idx]->numAgents));

            //FBox quad = regs[0]->box;

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
                ATextRenderActor* Text = GetWorld()->SpawnActor<ATextRenderActor>(ATextRenderActor::StaticClass(), FVector(loc.Location.X, loc.Location.Y, loc.Location.Z + 200), FRotator(0.f));
                Text->GetTextRender()->SetText(FText::FromString(TEXT("Walking")));
                Text->GetTextRender()->SetTextRenderColor(FColor::Red);
                agent->text = Text;

                agent->reg = regsVacant[idx];

                //if around percentage, remove
                //if (regsVacant[idx]->numAgents >= regsVacant[idx]->percent * numAgents) {
                    //regsFull.Add(regsVacant[idx]);
                    //regsVacant.RemoveAt(idx);
                //}

                agents.Add(agent);
                actualNumAgents++;
            }
        }

        //POTENTIALLY CHECK IF CHOOSING SAME REGION AS IN?

        for (int i = 0; i < actualNumAgents; i++) {
            //FBox q = regs[0]->box;
            //regs[0]->numAgents += 1;

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

                //if around percentage, remove from vacant
                //if (r->numAgents >= r->percent * numAgents) {
                  //  regsFull.Add(regsVacant[idx]);
                   // regsVacant.RemoveAt(idx);
                //}

                if (regsFull.Contains(agent->reg)) {
                    regsVacant.Add(agent->reg);
                    regsFull.Remove(agent->reg);
                }
                agent->reg = r;
            }

            //get activity
            int32 num = agent->reg->activities.Num();
            int32 rand = FMath::RandRange(0, num - 1);
            FString acty = agent->reg->activities[rand];

            agent->activity = acty;

            FNavLocation g; // Agent Goal
            float d1 = FVector::Distance(q.GetCenter(), FVector(q.GetCenter().X, q.Max.Y, q.GetCenter().Z));
            float d2 = FVector::Distance(q.GetCenter(), FVector(q.Min.X, q.GetCenter().Y, q.GetCenter().Z));
            navMesh->GetRandomPointInNavigableRadius(q.GetCenter(), FMath::Min(d1, d2), g);

            //FNavLocation g = navMesh->GetRandomPoint();
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

    //find all leaders
    TArray<AActor*> leads;
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), ALeader::StaticClass(), leads);
    for (int i = 0; i < leads.Num(); i++) {
        ALeader* l = Cast<ALeader>(leads[i]);
        FVector leaderloc = l->GetActorLocation();

        //DISPLAY TEXT ABOVE HEAD
        ATextRenderActor* Text = GetWorld()->SpawnActor<ATextRenderActor>(ATextRenderActor::StaticClass(), FVector(leaderloc.X, leaderloc.Y, leaderloc.Z + 200), FRotator(0.f));
        Text->GetTextRender()->SetText(FText::FromString(TEXT("Leader")));
        Text->GetTextRender()->SetTextRenderColor(FColor::Red);
        l->text = Text;

        //INITIALIZE GOAL
        //FNavLocation g = navMesh->GetRandomPoint();
        FNavLocation g;
        int idx = FMath::RandRange(0, l->points.Num() - 1);
        FVector goal = l->points[idx];
        navMesh->GetRandomPointInNavigableRadius(goal, 10, g);

        l->init(FVector(l->GetActorLocation().X, l->GetActorLocation().Y, l->GetActorLocation().Z + 90), agentV, agentR, duration, WidgetBPRef);
        l->currTarget = l->GetActorLocation();
        l->SpawnDefaultController();

        l->finalGoal = l->GetActorLocation();

        //find path to goal
        UNavigationPath* p = navSys->FindPathToLocationSynchronously(GetWorld(), l->GetActorLocation(), l->goal, NULL);
        TArray <FVector> path = p->PathPoints;
        l->path = path;
        l->goal = path[0];
        l->goal.Z += 90;
        l->path.RemoveAt(0);

        if (l->formation == EForm::EF_RANDLINE) {
            TArray<AFollower*> follows = CreateFollowers(Cast<AAgent>(l), l->GetActorLocation(), 2, navMesh, g, l->numFollowers);
            for (AFollower* created : follows) {
                l->followers.Add(created);
            }
        } else {
            AAgent* currLead = Cast<AAgent>(l);
            int numCreated = 0;
            //int noMore = 0;
            //while (numCreated < l->numFollowers && noMore < 3) {
            for (int j = 0; j < l->numFollowers; j++) {
                FNavLocation followloc;
                if (l->formation == EForm::EF_CLUMP || l->formation == EForm::EF_CLUMPLINE) {
                    FVector hm = FVector(leaderloc.X - 300, leaderloc.Y - 300, leaderloc.Z);
                    navMesh->GetRandomPointInNavigableRadius(hm, 500, followloc);
                } else if (l->formation == EForm::EF_LINE) {
                    FVector behind = FVector(leaderloc.X - (numCreated+1) * 20, leaderloc.Y - (numCreated+1) * 20, leaderloc.Z);
                    navMesh->GetRandomPointInNavigableRadius(behind, 10, followloc);
                } else if (l->formation == EForm::EF_WIDELINE) {
                    float offsetBack = -100 * (numCreated % 3);
                    float offsetRight;
                    if (i % 2 == 0) {
                        offsetRight = -100 * ((numCreated % 10) + 1);
                    } else {
                        offsetRight = 100 * ((numCreated % 10) + 1);
                    }

                    FVector behind = currLead->GetActorLocation() + (currLead->GetActorForwardVector() * offsetBack) + (currLead->GetActorRightVector() * offsetRight);

                    navMesh->GetRandomPointInNavigableRadius(behind, 20, followloc);
                }

                if (!followloc.HasNodeRef()) {
                    continue;
                }

                AFollower* agent = GetWorld()->SpawnActor<AFollower>(FVector(followloc.Location.X, followloc.Location.Y, followloc.Location.Z), FRotator::ZeroRotator);

                if (agent != nullptr) {
                    numCreated++;
                    //noMore = 0;
                    //DISPLAY TEXT ABOVE HEAD
                    ATextRenderActor* atxt = GetWorld()->SpawnActor<ATextRenderActor>(ATextRenderActor::StaticClass(), FVector(followloc.Location.X, followloc.Location.Y, followloc.Location.Z + 200), FRotator(0.f));
                    atxt->GetTextRender()->SetText(FText::FromString(TEXT("Follower")));
                    atxt->GetTextRender()->SetTextRenderColor(FColor::Red);
                    agent->text = atxt;

                    agent->init(FVector(g.Location.X, g.Location.Y, g.Location.Z + 90), agentV, agentR, duration, WidgetBPRef);
                    agent->currTarget = agent->GetActorLocation();
                    agent->SpawnDefaultController();

                    l->followers.Add(agent);
                    agent->parent = currLead;
                } else {
                    //noMore++;
                }

                //if agent wasn't created don't update new leader
                if (l->formation == EForm::EF_WIDELINE) {
                    if (numCreated % 10 == 0 && numCreated != 0) {
                        if (agent != nullptr) {
                            currLead = Cast<AAgent>(agent);
                        }
                    }
                }
            }
        }
        leaders.Add(l);
    }

    //uncomment to see markers as spheres
    /*for(unsigned int i = 0; i < sampler.samples.Num(); i++) {
     AMarkerVis* NewActor = GetWorld()->SpawnActor<AMarkerVis>(sampler.samples[i], FRotator::ZeroRotator);
     }*/

    // load profiles
    int counter = 0;
    for (auto c : scene.text) {
        if (c.getOperation() != Operation::CREATE) { break;}
        for (int i = 0; i < c.getNumberOf(); i++) {
            agents[counter]->profile_Name = c.getProfile().c_str();
            counter++;
        }
    }
}

//----------------------------------------------------------UPDATE EVERY TICK----------------------------------------------------------


// Called every frame
void ACrowdController::Tick(float DeltaTime) {
    Super::Tick(DeltaTime);

    UNavigationSystemV1* navSys = FNavigationSystem::GetCurrent<UNavigationSystemV1>(GetWorld());
    ARecastNavMesh* navMesh = navSys ? Cast<ARecastNavMesh>(navSys->GetDefaultNavDataInstance()) : nullptr;
    tempo += DeltaTime;
    for (auto c : scene.text) {
        if (c.getTime() == int(tempo)) {
            if (c.getIsAll()) {
                for (auto agent : agents) {
                    if (agent->profile_Name == c.getProfile().c_str()) {
                        if (c.getOperation() == Operation::RUN) {
                            agent->nowPlaying = FString(c.getBehaviour().c_str());
                            agent->hasSomethingToPlay = true;
                            agent->pc = 0;
                            agent->inLoop = false;
                        }
                        if (c.getOperation() == Operation::STOP) {
                            agent->goal = agents[c.getTargetID() - 1]->GetActorLocation();
                            agent->hasSomethingToPlay = false;
                        }
                        if (c.getOperation() == Operation::LOOP) {
                            agent->nowPlaying = FString(c.getBehaviour().c_str());
                            agent->hasSomethingToPlay = true;
                            agent->pc = 0;
                            agent->inLoop = true;
                        }
                    }
                }
            }
            else {
                auto atual = agents[c.getTargetID() - 1];
                if (c.getOperation() == Operation::RUN) {
                    atual->nowPlaying = FString(c.getBehaviour().c_str());
                    atual->hasSomethingToPlay = true;
                    atual->pc = 0;
                    atual->inLoop = false;
                }
                if (c.getOperation() == Operation::STOP) {
                    atual->goal = agents[c.getTargetID() - 1]->GetActorLocation();
                    atual->hasSomethingToPlay = false;
                }
                if (c.getOperation() == Operation::LOOP) {
                    atual->nowPlaying = FString(c.getBehaviour().c_str());
                    atual->hasSomethingToPlay = true;
                    atual->pc = 0;
                    atual->inLoop = true;
                }
            }
        }
    }
    for (AAgent* a : agents) {
        if (a->pc > scene.Scripts.find(string(TCHAR_TO_UTF8(*a->nowPlaying)))->second.text.size() && !a->inAction) {
            if (!a->inLoop) {
                a->hasSomethingToPlay = false;
            }
            a->pc = 0;
        }
        if (!a->inAction && a->pc < scene.Scripts.find(string(TCHAR_TO_UTF8(*a->nowPlaying)))->second.text.size() && a->hasSomethingToPlay && !a->inAnim) {

            BehaviourCommand bc = scene.Scripts.find(string(TCHAR_TO_UTF8(*a->nowPlaying)))->second.text[a->pc];
            a->inAction = true;
            if (bc.getOpcode() == Opcode::GO) {
                int idx;
                FString regionName = bc.getDestiny().c_str();
                if (regionName.ToLower().Contains("random")) {
                    FString region_flag = "Place";
                    FString left;
                    if (regionName.Contains(" ")) {
                        regionName.Split(TEXT(" "), &left, &region_flag);

                    }
                    UE_LOG(LogTemp, Warning, TEXT("Quadrante inicial: %s"), *region_flag);
                    TArray<int> indexes;
                    for (int j = 0; j < regsVacant.Num(); j++) {
                        ARegionBox* atual = regsVacant[j];
                        if (atual->Flags.Contains(region_flag)) {
                            indexes.Add(j);
                        }
                    }
                    idx = indexes[FMath::RandRange(0, indexes.Num() - 1)];
                }
                else {
                    idx = Locais[regionName];
                }
                FBox quad = regsVacant[idx]->box;
                FNavLocation loc;
                FVector center = quad.GetCenter();
                float dist1 = FVector::Distance(center, FVector(center.X, quad.Max.Y, center.Z));
                float dist2 = FVector::Distance(center, FVector(quad.Min.X, center.Y, center.Z));
                navMesh->GetRandomPointInNavigableRadius(center, FMath::Min(dist1, dist2), loc);

                FVector vaipara(loc.Location.X, loc.Location.Y, loc.Location.Z);
                a->goal = vaipara;
                a->goal.Z += 90;

                a->finalGoal = a->goal;

                UNavigationPath* p = navSys->FindPathToLocationSynchronously(GetWorld(), a->GetActorLocation(), a->goal, NULL);
                TArray <FVector> path = p->PathPoints;
                a->path = path;
                a->goal = path[0];
                a->goal.Z += 90;
                a->path.RemoveAt(0);
                a->inAction = true;
            }

            if (bc.getOpcode() == Opcode::PLAY) {
                //(LogTemp, Warning, TEXT("%s"), *bc.getDestiny().c_str());
                a->inAnim = true;
                a->playAnimation("Dance");
                UE_LOG(LogTemp, Warning, TEXT("%f"), a->Animations["Dance"]->GetPlayLength());
                UE_LOG(LogTemp, Warning, TEXT("%d"), a->inAnim);

            }
        } 
        FVector vel = a->GetVelocity();
        float dist = FVector::Distance(a->GetActorLocation(), a->finalGoal);
        if (dist < 101) {
            if(a->inAction){ 
                a->inAction = false; 
            }
            if (a->inAnim) {
                a->animtime += DeltaTime;
                if (a->animtime >= a->Animations[a->AnimName]->GetPlayLength()) {
                    a->animtime = 0.f;
                    a->inAnim = false;
                    a->MySkeleton->SetAnimInstanceClass(a->Animdefault->GeneratedClass);
                }
            }
            if (!a->inAction && !a->inAnim) {
                a->pc++;
            }
        }
    }
    //Update goals
    //gather agents done moving
    TArray<AAgent*> afinished;
    TArray<ALeader*> lfinished;
    TArray<AAgent*> finished;
    for (AAgent* a : agents) {
        if (a->showGoal) {
            DrawDebugDirectionalArrow(GetWorld(), FVector(a->GetActorLocation().X, a->GetActorLocation().Y, a->GetActorLocation().Z + 30),
                                      FVector(a->finalGoal.X, a->finalGoal.Y, a->finalGoal.Z + 30),
                                      200, FColor::Red, false);
        }

        a->text->SetActorLocation(FVector(a->GetActorLocation().X, a->GetActorLocation().Y, a->GetActorLocation().Z + 200));
        FVector vel = a->GetVelocity();
        float dist = FVector::Distance(a->GetActorLocation(), a->currTarget);
        if (dist < 5 || (FMath::Abs(vel.X) == 0 && FMath::Abs(vel.Y) == 0) /*|| minDist < 60*/) {
            afinished.Add(a);
            finished.Add(a);
            /*for(unsigned int i = 0; i < a->markers.Num(); i++) {
             AMarkerVis* newM = GetWorld()->SpawnActor<AMarkerVis>(a->markers[i]->pos, FRotator::ZeroRotator);
             }*/
        }
    }

    //gather families done moving
    for (ALeader* l : leaders) {
        //debug tools
        if (l->showGoal) {
            DrawDebugDirectionalArrow(GetWorld(), FVector(l->GetActorLocation().X, l->GetActorLocation().Y, l->GetActorLocation().Z + 30),
                                      FVector(l->finalGoal.X, l->finalGoal.Y, l->finalGoal.Z + 30),
                                      200, FColor::Red, false, -1, 0, 5.f);
        }
        for (int i = 0; i < l->markers.Num(); i++) {
            //DrawDebugSphere(GetWorld(), l->markers[i]->pos, 10, 26, FColor::Red, false);
            //DrawDebugPoint(GetWorld(), l->markers[i]->pos, 10, FColor::Red, false);
        }

        l->text->SetActorLocation(FVector(l->GetActorLocation().X, l->GetActorLocation().Y, l->GetActorLocation().Z + 200));
        FVector vel = l->GetVelocity();
        float dist = FVector::Distance(l->GetActorLocation(), l->currTarget);
        if (dist < 20 || (FMath::Abs(vel.X) == 0 && FMath::Abs(vel.Y) == 0) /*|| minDist < 60*/) {
            //finished.Add(Cast<AAgent>(l));
            //lfinished.Add(l);
        }
        for (AFollower* f : l->followers) {
            f->text->SetActorLocation(FVector(f->GetActorLocation().X, f->GetActorLocation().Y, f->GetActorLocation().Z + 200));
            //finished.Add(Cast<AAgent>(f));
            /*f->text->SetActorLocation(FVector(f->GetActorLocation().X, f->GetActorLocation().Y, f->GetActorLocation().Z + 200));
             FVector velf = f->GetVelocity();
             float distf = FVector::Distance(f->GetActorLocation(), f->currTarget);
             if (distf < 5 || (FMath::Abs(velf.X) == 0 && FMath::Abs(velf.Y) == 0)) {
             finished.Add(Cast<AAgent>(f));
             }*/
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
                    a->text->GetTextRender()->SetText(FText::FromString(a->activity));
                    a->text->GetTextRender()->SetTextRenderColor(FColor::Green);
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

                        //if agent's last reg was full
                       // if (regsFull.Contains(a->reg)) {
                        //    regsVacant.Add(a->reg);
                        //    regsFull.Remove(a->reg);
                       // }

                        a->reg = r;
                    } else {
                        int idx = FMath::RandRange(0, regsVacant.Num() - 1);
                        ARegionBox* r = regsVacant[idx];
                        q = r->box;

                        //increase and decrease num agents
                        r->numAgents++;
                        a->reg->numAgents--;

                        //if around percentage, remove from vacant
                        //if (r->numAgents >= r->percent * numAgents) {
                        //    regsFull.Add(regsVacant[idx]);
                         //   regsVacant.RemoveAt(idx);
                       // }

                        if (regsFull.Contains(a->reg)) {
                            regsVacant.Add(a->reg);
                            regsFull.Remove(a->reg);
                        }
                        a->reg = r;
                    }

                    //get activity
                    int32 num = a->reg->activities.Num();
                    int32 rand = FMath::RandRange(0, num - 1);
                    FString acty = a->reg->activities[rand];

                    a->activity = acty;

                    FNavLocation g;
                    float d1 = FVector::Distance(q.GetCenter(), FVector(q.GetCenter().X, q.Max.Y, q.GetCenter().Z));
                    float d2 = FVector::Distance(q.GetCenter(), FVector(q.Min.X, q.GetCenter().Y, q.GetCenter().Z));
                    navMesh->GetRandomPointInNavigableRadius(q.GetCenter(), FMath::Min(d1, d2), g);

                    a->goal = a->GetActorLocation();
                    a->goal.Z += 90;

                    a->finalGoal = a->goal;

                    UNavigationPath* p = navSys->FindPathToLocationSynchronously(GetWorld(), a->GetActorLocation(), a->goal, NULL);
                    TArray <FVector> path = p->PathPoints;
                    a->path = path;
                    a->goal = path[0];
                    a->goal.Z += 90;
                    a->path.RemoveAt(0);


                    a->text->GetTextRender()->SetText(FText::FromString(TEXT("Walking")));
                    a->text->GetTextRender()->SetTextRenderColor(FColor::Red);
                    a->ticks = 0;

                } else {
                    a->ticks++;
                }
            }
        }
    }

    for (ALeader* l : lfinished) {
        FVector leaderloc = l->GetActorLocation();
        /*DrawDebugDirectionalArrow(GetWorld(), leaderloc,
                                  leaderloc + (100 * l->GetActorForwardVector()),
                                  200, FColor::Blue, false);
        DrawDebugDirectionalArrow(GetWorld(),leaderloc,
                                  leaderloc + (100 * l->GetActorRightVector()),
                                  200, FColor::Blue, false);*/

        float dist = FVector::Distance(l->GetActorLocation(), l->goal);
        if (dist > 100) {
            AAIController* ac = Cast<AAIController>(l->GetInstigatorController());

            FVector m = l->currTarget;

            ac->MoveToLocation(l->currTarget, -1, false);
        } else {
            if (l->path.Num() > 0) {
                l->goal = l->path[0];
                l->goal.Z += 90;
                l->path.RemoveAt(0);
            } else {
                //FNavLocation g = navMesh->GetRandomPoint();

                //get goal specified
                FNavLocation g;
                int idx = FMath::RandRange(0, l->points.Num() - 1);
                FVector goal = l->points[idx];
                navMesh->GetRandomPointInNavigableRadius(goal, 10, g);

                l->goal = l->GetActorLocation();
                l->goal.Z += 90;

                l->finalGoal = l->goal;

                UNavigationPath* p = navSys->FindPathToLocationSynchronously(GetWorld(), l->GetActorLocation(), l->goal, NULL);
                TArray <FVector> path = p->PathPoints;
                l->path = path;
                l->goal = path[0];
                l->goal.Z += 90;
                l->path.RemoveAt(0);
            }
        }

        //update followers
        //for line formation
        AFollower* prev = nullptr;
        for (AFollower* f: l->followers) {
            FVector target;

            if(l->formation == EForm::EF_CLUMP) {
                FNavLocation jittered;
                navMesh->GetRandomPointInNavigableRadius(l->GetActorLocation(), 50, jittered);

                target = jittered.Location;
                target.Z += 90;
            } else if (l->formation == EForm::EF_CLUMPLINE) {
                target = l->GetActorLocation();
            } else if (l->formation == EForm::EF_LINE) {
                if (prev == nullptr) {
                    target = l->GetActorLocation();
                } else {
                    target = prev->GetActorLocation();
                }
                prev = f;
            } else if (l->formation == EForm::EF_RANDLINE) {
                AAgent* parent = f->parent;
                target = parent->GetActorLocation() /*+(parent->GetActorForwardVector() * f->offsetBack)*/ + (parent->GetActorRightVector() * (f->offsetRight / 2));
            } else if (l->formation == EForm::EF_WIDELINE) {
                AAgent* parent = f->parent;
                target = parent->GetActorLocation();
            }

            if (f->showGoal) {
                DrawDebugDirectionalArrow(GetWorld(), FVector(f->GetActorLocation().X, f->GetActorLocation().Y, f->GetActorLocation().Z + 30),
                                          FVector(target.X, target.Y, target.Z + 30),
                                          200, FColor::Red, false, -1, 0, 5.f);
            }

            AAIController* ac = Cast<AAIController>(f->GetInstigatorController());

            ac->MoveToLocation(target, -1, false);
        }
    }
}

/*void ACrowdController::OnSelected(AActor* TouchedActor, FKey ButtonPressed) {
 GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Cyan, FString("EEEEEEEEEEEEEEEEE"));
 //showGoal = !showGoal;
 //showMarkers = !showMarkers;
 //UUserWidget* WidgetInstance = CreateWidget<UUserWidget>(GetWorld(), WidgetBPReference);
 //WidgetInstance->AddToViewport();
 }*/
