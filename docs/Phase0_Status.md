# Phase 0 Status - ECS Foundation

**Branch:** `ecs/phase-0-foundation`
**Status:** In Progress

## Architecture Decision

Following user feedback, we are using **proper archetype-based storage from the very beginning** instead of temporary map-based storage. This avoids major refactors later.

## Current Structure (`src/ecs/`)

```
src/ecs/
├── Archetype.h              # Represents a unique set of components
├── Archetype.cpp
├── ArchetypeStorage.h       # SoA storage for one archetype
├── ArchetypeStorage.cpp
├── EntityManager.h
├── EntityManager.cpp
├── World.h                  # Manages archetypes and entity lifecycle
├── World.cpp
├── Components.h
├── SimulationCore.h
├── SimulationCore.cpp
└── Ballpark_NewCore.*
```

## Key Classes Implemented

- **Archetype**: Holds a component signature (bitmask).
- **ArchetypeStorage**: Stores entities + components in SoA layout for one archetype.
- **World**: Owns EntityManager and manages ArchetypeStorage instances.

All classes are fully documented.

## Next Steps

- Improve archetype transitions when adding components (currently simplified).
- Add System infrastructure.
- Continue making the pieces usable in isolation.
