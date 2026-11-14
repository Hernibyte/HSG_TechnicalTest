# TODO LIST

## Character Locomotion

- [X] Walking.
- [X] Running.
- [X] Add appropriate animations.

## Actor Interaction

- [X] Create an interactable interface in C++.
- [X] Add "interact" input action to player.

## Interactable Spawner

- [X] Create a Spawner actor with the interactable interface.
- [X] Upon interaction, pop up a UI Widget on the screen.
- [X] Add BoundingBox component or a custom ComponentVisualizer for better editor debugging.

## Spawner System

- [X] Spawns the number of actors specified by the user at random locations within a defined area.
- [X] Retains the spawned actors in the level only for the user-specified time, automatically destroying them afterward.
- [X] Add a simple actor for spawning.
- [ ] Add collision checks on spawning actors.

## UI Widget

- [X] Include an input field to enter the amount of actors to spawn.
- [X] Include an input flied to enter the lifespan/duration for the spawned actors.
- [X] Include a confirmation button to execute the action.
- [X] Move to a C++ class.
