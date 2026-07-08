# Phase 0 Status - ECS Foundation

**Branch:** `ecs/phase-0-foundation`
**Status:** In Progress

## Completed in Phase 0

- [x] Created feature flag `DESTINY_USE_NEW_CORE` in `src/DestinyConfig.h`
- [x] Created initial component structs in `src/ecs/Components.h`
- [x] Created `SimulationCore` stub (`SimulationCore.h` + `.cpp`)
- [x] Established `src/ecs/` directory structure

## Next in Phase 0

- Extend benchmarking harness in `tools/benchmark/`
- Prepare dual-implementation path in `Ballpark`
- Add basic entity/component storage prototype
- Set up side-by-side determinism comparison harness

## Notes

All changes are behind the feature flag and do not affect the legacy path or any external interfaces.
