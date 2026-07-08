# Phase 0 Status - ECS Foundation

**Branch:** `ecs/phase-0-foundation`

## Current State

- All components are consolidated in a single file: `src/ecs/Components.h`
- Deprecated `BallComponents.h` has been removed
- `World` and `SimulationCore` have been updated to use the new component names (`KinematicComponent`, `CollidableComponent`, `BallModeComponent`)
- `ArchetypeStorage` is fully generic (variadic template)

The ECS foundation is now in a clean, consistent state with one source of truth for components.