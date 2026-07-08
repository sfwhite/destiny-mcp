# Phase 0 Status - ECS Foundation

**Branch:** `ecs/phase-0-foundation`

## Update: Components Consolidated

All ECS components have been consolidated into a **single file**: `src/ecs/Components.h`.

- `BallComponents.h` has been deprecated (kept as a stub with a warning).
- The file now contains the clean, up-to-date set:
  - `TransformComponent`
  - `KinematicComponent` + `CollidableComponent` (physics split)
  - Full `BallMode` enum (matching DSTBALLMODE)
  - `BallModeComponent`, `ProximityComponent`, `OwnershipComponent`, etc.
  - `CompoundShapeComponent` (optional, for complex objects)

This matches the user's preference for a single source of truth for components.