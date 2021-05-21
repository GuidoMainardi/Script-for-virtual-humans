# Comportamento Scriptado de Humanos Virtuais para Testes de Hipóteses Antropológicas

## Dependencies
  - [x] Unreal 4.26
  - [x] Visual Studio (with support for Unreal)


## New Project

Before starting to use the scripts it is necessary to create and map the environment that will be used in the project, for this tutorial it was chosen a simple house that will be modeled and used to demonstrate the existing commands.

![House](https://user-images.githubusercontent.com/48321393/118320533-c5d2f200-b4d2-11eb-9c2d-42ba912bad04.jpg)


### Initial scenario

The first step is to create the scenario and add a navmesh to it, so that it helps us to find our path from one point to another.

![Cenario](https://user-images.githubusercontent.com/48321393/118320557-cd929680-b4d2-11eb-8f95-68a2b3723561.png)

Once you have the initial scenario, you need to map it using the RegionBox. Each RegionBox will fill a place on the stage and will represent the area of that place. In the house's case, we have the kitchen, the living room, the bedroom and the bathroom, for each of these rooms we will create a RegionBox with the room's name.

![ReginBoxes](https://user-images.githubusercontent.com/48321393/118320564-d1beb400-b4d2-11eb-9c9c-f1d9f4dab4cb.png)

With the place created and mapped there is a last configuration that may or may not be done, in each RegionBox there is an attribute called "flags", which can be added new values in it, by default all RegionBox are initialized as "Place", but you can add new flags, so that it is possible to limit the commands referring to random places.

![Flags](https://user-images.githubusercontent.com/48321393/118320579-d6836800-b4d2-11eb-8c0e-77bf644e3bda.png)

### Models

In order to be able to use new models it is necessary to insert them in the project first and make a small state machine to define the animations of standing, walking and running. In addition, it is also necessary to create the collision regions of this model that will be used.

![Maquina de estados](https://user-images.githubusercontent.com/48321393/118320597-db481c00-b4d2-11eb-82af-138a032ddcd6.png)

It also needs to be added in the code "Agent.cpp" the path of each thing created by the new model and add to the map with the name you want to use when referring to them in the scripts.

![Modelo Referencia](https://user-images.githubusercontent.com/48321393/118320620-e438ed80-b4d2-11eb-9d26-875670bcbc2c.png)
![references AgentCpp](https://user-images.githubusercontent.com/48321393/118320643-e7cc7480-b4d2-11eb-9660-d0fbc12a2bec.png)


### Animations

To add animations the process is similar to the models in the section above, you need to add the animation to the project and then put its path in "Agent.cpp" saving it on the map with the name that will be used in the script. One thing to take care of is that the animations are linked to the model, so each model must have its own animation and have a different name on the map, for example the "dance" and "macarenaDance" animations, which are the same, however for different models.

![anim references Agentcpp](https://user-images.githubusercontent.com/48321393/118320664-ee5aec00-b4d2-11eb-9dc8-9303ec9e1e06.png)

## Profile

Profile is the main way to distinguish agents, when they are created they are given a profile and are called by it. For example, when I create an agent with the "walker" profile, it will respond to commands that tell all walkers to follow some behavior and will trigger predicted events when a walker goes to a RegionBox. Agents of the same profile can have different models and follow the same instructions when they are ordered to the group (profile) for example "All Walker ...". The name of each profile is decided by whoever is writing the scripts and cannot use the reserved words of the language as profile names, for example (All, go, create, default ...)

## Comands

With the whole scenario set up, you can start writing the scripts to command the agents. There are two types of Scripts, the main one, which has the initialization and event commands, and the behavioral ones, which describe sequences of actions that will be executed one after the other ends. The main script must be called "Main.txt", since the behavior scripts can have arbitrary names. The names of the behavior scripts will be used to reference them in the main script.

![Exemplo Scripts](https://user-images.githubusercontent.com/48321393/118320677-f1ee7300-b4d2-11eb-8f63-964e0eac6e7b.png)

### Random

Random is not a command, but rather a way of referring to regionBox, when using the word Random instead of the name of the region box, the target location will be some random regionBox, if it is not desired that all regionBox are the target of this command. You can use Random together with a flag, for example "Random South", so it will use some random regionBox, which has "South" as an element in the "flags" attribute. 

### Main Script

in the main script there are two types of commands, timeless (which must go at the beginning of the script) and temporal (which must come after timeless and follow a chronological order, that is, time command 2, cannot come before a time command 1).

#### Create

The Create command is a timeless command and it is used to initialize the agents, informing how many, which profile, which model and where. the most basic command is "Create *Number* *Profile* in *Place*", so it will create * Number * agents from the profile *Profile*, in the regionBox called *Place*. in this command the model is implicit, but it can also be defined, using "as" after informing the profile, as for example in "Create 2 Walker as Macarena in Random", so two agents of the "Walker" profile will be created with the model defined as "Macarena" in any regionBox. When agents are created, they are given an "id" that will be used to give commands to isolated agents, so if we have, two "Create" commands as in the example below.

![Create example](https://user-images.githubusercontent.com/48321393/118320790-177b7c80-b4d3-11eb-8bdf-88b53e8c1104.png)

The two agents of the "Walker" profile will have the id's 1 and 2 and the profile agent "Agent" will have id 3, the id is defined in order of creation, so it will increase as the agents are created, if I have 8 agents the id's will be from 1 to 8 as they were created in the code.


#### When

When is the other timeless command, it will define timeless events, when an agent of a specific profile goes to a specific place it will trigger a command, its structure is "When *Profile* in *Place* *Command*" , so whenever any agent of the *Profile* profile starts to go to the *Place* location, the *Command* command will be executed. The command *Command* is a time-type command, which will be explained below, but different from the time commands used in the rest of the script, this one will not have the "time *t*", as it will be triggered whenever an agent a certain profile goes somewhere and not when a simulation time is reached.

#### *Profile* *ID*

This command is a temporal command and defines a single agent to perform a certain behavior. This command has the structure "*Profile* *ID* time *t* run *Behavior*", so in time *t* (after *t* seconds of simulation) the agent of id *ID* will execute the behavior *Behavior*. the behavior will be described in a behavior script that will be explained in the sections below. this command has some variations, for example "All *Profile* time *t* run *Behavior*", so all agents that are in the *Profile* profile will execute the *Behavior*  script. Another possible variation is the use of a loop instead of a run, where instead of running the behavior only once, they keep repeating the actions infinitely. These commands overlap with the actions that were being executed previously, that is, if an agent was executing a behavior and a command arrives for him to execute another behavior, he stops the old execution and starts executing the new one.

### Behaviour Commands

The behavior commands are the simplest and have direct instructions, they are called within a behavior script, they are executed one after the other ends, when they are inside the same script, and can be interrupted by new commands given through the script main.

#### Go to

The go to command orders the agent to go somewhere, and it is used together with the RegionBoxes, its structure is very simple: "go to *Place*", so the agent running this command will start to go to a random point within the *Place* regionbox. The regionBox of this command can also be described as "Random" along with the flags defined by the programmer, for example "Random South".

#### play

The play command is used to start an animation, during the animation time the agent is stopped executing it. the command has the structure "play *anim*" where *anim* is the key added to the map in "Agent.cpp", it is worth mentioning that the animations are linked to the model, so if a model is ordered to run an animation that does not it belongs to him, it will be stopped in neutral position for the duration of the animation, before continuing to execute the next commands.
