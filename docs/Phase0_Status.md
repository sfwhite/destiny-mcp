# Phase 0 Status - ECS Foundation

**Branch:** `ecs/phase-0-foundation`
**Status:** In Progress

## Completed

- [x] Feature flag `DESTINY_USE_NEW_CORE`
- [x] Initial component structs
- [x] `SimulationCore` stub + `Initialize()` method
- [x] `Ballpark_NewCore` helper (dual-path skeleton)
- [x] Updated plan document with stable `Ball` adapter strategy

## Current Focus

- Integrating dual-path logic into main `Ballpark`
- Entity manager + System initialization when new core is enabled
- Preparing for `Ball` adapter pattern

## Next Steps
- Add conditional ownership of `SimulationCore` inside main `Ballpark` class
- Wire `InitializeNewCore()` call based on feature flag
- Begin basic entity creation routing
