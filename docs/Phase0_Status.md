# Phase 0 Status - ECS Foundation

**Branch:** `ecs/phase-0-foundation`
**Status:** In Progress

## Directory Structure (All new code lives in `src/ecs/`)

```
src/ecs/
├── Components.h              # TransformComponent, PhysicsPropertiesComponent, ModeComponent
├── SimulationCore.h          # Main high-performance core (entity manager + systems entry point)
├── SimulationCore.cpp
├── Ballpark_NewCore.h        # Dual-path helper for Ballpark
└── Ballpark_NewCore.cpp
```

## Completed in Phase 0

- [x] Feature flag `DESTINY_USE_NEW_CORE` in `src/DestinyConfig.h`
- [x] Initial component structs
- [x] `SimulationCore` with `Initialize()` method
- [x] `Ballpark_NewCore` dual-path helper (moved into `ecs/`)
- [x] Updated main plan document

## Current State

All new ECS classes now live cleanly inside the `src/ecs/` directory as requested.

## Next Recommended Steps

- Integrate `Ballpark_NewCore` into the main `Ballpark` class (conditional ownership + initialization)
- Add basic entity creation routing through the new core
- Begin defining a simple System base + registration in `SimulationCore::Initialize()`
