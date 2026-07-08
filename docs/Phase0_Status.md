# Phase 0 Status - ECS Foundation

**Branch:** `ecs/phase-0-foundation`
**Status:** In Progress

## Current Structure (`src/ecs/`)

```
src/ecs/
├── Components.h
├── EntityManager.h          # Creates/destroys entity IDs
├── EntityManager.cpp
├── World.h                  # Central ECS container (owns EntityManager)
├── World.cpp
├── SimulationCore.h         # Owns World, will manage Systems
├── SimulationCore.cpp
└── Ballpark_NewCore.h
└── Ballpark_NewCore.cpp
```

## Completed

- [x] Feature flag
- [x] Components
- [x] EntityManager
- [x] World (owns EntityManager)
- [x] SimulationCore now owns a World
- [x] Ballpark_NewCore helper

## Next Steps
- Wire `Ballpark_NewCore` into main `Ballpark`
- Add component storage to `World`
- Define basic System interface
