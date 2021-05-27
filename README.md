# Comportamento Scriptado de Humanos Virtuais para Testes de Hipóteses Antropológicas

## Dependencies
  - [x] Unreal 4.26
  - [x] Visual Studio (with support for Unreal)


## New Project

Before starting to use the scripts it is necessary to create and map the environment that will be used in the project, for this tutorial it was chosen a simple house that will be modeled and used to demonstrate the existing commands.

![House](https://user-images.githubusercontent.com/48321393/118320533-c5d2f200-b4d2-11eb-9c2d-42ba912bad04.jpg)


### Initial scenario

The first step is to create the scenario and add a navmesh to it, that will help us to find our path from one point to another.

![Cenario](https://user-images.githubusercontent.com/48321393/118320557-cd929680-b4d2-11eb-8f95-68a2b3723561.png)

Once you have the initial scenario, you need to map it using the RegionBox. Each RegionBox will fill a place on the stage and will represent the area of that place. In this house we have the kitchen, the living room, the bedroom and the bathroom, for each of these rooms we will create a RegionBox with the room's name.

![ReginBoxes](https://user-images.githubusercontent.com/48321393/118320564-d1beb400-b4d2-11eb-9c9c-f1d9f4dab4cb.png)

With the place created and mapped there is a last configuration that may or may not be done. In each RegionBox there is an attribute called "flags" which can be added new values in it. By default all RegionBox are initialized as "Place" but you can add new flags, so that it is possible to limit the commands referring to random places.

![Flags](https://user-images.githubusercontent.com/48321393/118320579-d6836800-b4d2-11eb-8c0e-77bf644e3bda.png)

### Models

In order to be able to use new models it is necessary to insert them in the project first and make a small state machine to define the animations of standing, walking and running. In addition, it is also necessary to create the collision regions of this model that will be used.

![Maquina de estados](https://user-images.githubusercontent.com/48321393/118320597-db481c00-b4d2-11eb-82af-138a032ddcd6.png)

It also needs to add in the code "Agent.cpp" the path of each thing created by the new model and add to the map with the name you want to use when referring to them in the scripts.

![Modelo Referencia](https://user-images.githubusercontent.com/48321393/118320620-e438ed80-b4d2-11eb-9d26-875670bcbc2c.png)
![references AgentCpp](https://user-images.githubusercontent.com/48321393/118320643-e7cc7480-b4d2-11eb-9660-d0fbc12a2bec.png)


### Animations

To add animations the process is similar to the models in the section above. You need to add the animation to the project and then put its path in "Agent.cpp" saving it on the map with the name that will be used in the script. One thing to take care of is that the animations are linked to the model, so each model must have its own animation and a different name on the map. For example the "dance" and "macarenaDance" animations which are the same, however for different models.

![anim references Agentcpp](https://user-images.githubusercontent.com/48321393/118320664-ee5aec00-b4d2-11eb-9dc8-9303ec9e1e06.png)

## Profile

Profile is the main way to distinguish agents, when they are created we give a profile and they are called by it. For example when I create an agent with the "walker" profile, it will respond to commands that tell all walkers to follow some behavior and will trigger predicted events when a walker goes to a RegionBox. Agents of the same profile can have different models and follow the same instructions when they are required to the group (profile) for example "All Walker ...". The name of each profile is decided by whoever is writing the scripts and cannot use the reserved words of the language as profile names like *All*, *go*, *create*, *default*, ...

## Comands

With the whole scenario set up, you can start writing the scripts to command the agents. There are two types of Scripts, the main one and the behvioral ones. The first one has the initialization and event commands. The second one will describe actions that will be executed in sequence. The main script must be called "Main.txt", since the behavior scripts can have arbitrary names. The names of the behavior scripts will be used to reference them in the main script.

![Exemplo Scripts](https://user-images.githubusercontent.com/48321393/118320677-f1ee7300-b4d2-11eb-8f63-964e0eac6e7b.png)

### Random

*Random* is not a command but a way of referring to RegionBox. When using the word *Random* instead of the name of the RegionBox, the target location will be a random RegionBox. If it is not desired that all RegionBox are the target of this command you can use *Random* together with a flag. For example "Random South" will use a random RegionBox, which has "South" as an element in the "flags" attribute. 

### Main Script

In the main script there are two types of commands, timeless (which must go at the beginning of the script) and temporal (which must come after timeless and follow a chronological order, that is, a command on time 2, cannot come before a command on time 1).

#### Create

The Create command is a timeless command and it is used to initialize the agents, informing how many, which profile, which model and where. The most basic command is "Create *Number* *Profile* in *Place*" it will create *Number* agents from the profile *Profile*, in the RegionBox called *Place*. In this command the model is implicit but it can also be defined using "as" after informing the profile. Like in "Create 2 Walker as Macarena in Random", so two agents of the "Walker" profile will be created with the model defined as "Macarena" in any RegionBox. When agents are created they are given an "id" that will be used to give commands to isolated agents. So if we have two "Create" commands as in the example below.

![Create example](https://user-images.githubusercontent.com/48321393/118320790-177b7c80-b4d3-11eb-8bdf-88b53e8c1104.png)

The two agents of the "Walker" profile will have the id's 1 and 2 and the profile agent "Agent" will have id 3, the id is defined in order of creation so it will increase as the agents are created. If I have 8 agents the id's will be from 1 to 8 as they were created in the code.


#### When

"When" is the other timeless command. It will define timeless events, when an agent of a specific profile goes to a specific place it will trigger the command. The structure is "When *Profile* in *Place* *Command*" , so whenever any agent of the *Profile* starts to go to the *Place* the *Command* will be executed. The *Command* is a temporal command, which will be explained below. Different from the temporal commands used in the rest of the script, this one will not have the "time *t*" because it will be triggered whenever an agent of a certain profile goes somewhere and not when a simulation time is reached.

#### *Profile* *ID*

This command is a temporal command and defines a single agent to perform a certain behavior. This command has the structure "*Profile* *ID* time *t* run *Behavior*", so in time *t* (after *t* seconds of simulation) the agent of *ID* will execute the *Behavior*. The behavior will be described in a behavior script that will be explained in the sections below. This command has some variations. For example "All *Profile* time *t* run *Behavior*" all agents that have the *Profile* profile will execute the *Behavior* script. Another possible variation is the use of a "loop" instead of a "run". Where instead of running the behavior only once, they keep repeating the actions infinitely. These commands overlap with the actions that were being executed previously, that is, if an agent was executing a behavior and a command arrives for him to execute another behavior, he stops the old execution and starts executing the new one.

### Behaviour Commands

The behavior commands are the simplest and have direct instructions wich are called by a behavior script. They are executed one right after the other when they are inside the same script. That can be interrupted by new commands given through the main script.

#### Go to

The go to command orders the agent to go somewhere. It is used together with the RegionBox. The structure is very simple: "go to *Place*" and than the agent running this command will start to go to a random point within the *Place* RegionBox. The regionBox of this command can also be described as "Random" along with the flags defined by the programmer, for example "Random South".

#### Play

The play command is used to start an animation. The agent stop where it is before start the animation. The command has the structure "play *anim*" where *anim* is the key added to the map in "Agent.cpp". It is worth mentioning that the animations are linked to the model. So if a model is ordered to run an animation that does not it belongs to him, it will be stopped in neutral position for the duration of the animation before continuing to execute the next commands.
