# Phase 0 Status - ECS Foundation

**Branch:** `ecs/phase-0-foundation`

## Update: Refined Ball Component Decomposition

Updated `BallComponents.h` based on feedback:

- Removed `CompoundShapeComponent` (deferred — drones are generally non-collidable).
- Split physics data into:
  - `KinematicComponent` (mass, agility, max velocities — movement simulation parameters)
  - `CollidableComponent` (radius / bounding volume — collision participation)
- Removed boolean flags (`isFixed`, `isCollidable`, `isMassive`) in favor of component presence.
- Kept other components (`TransformComponent`, `BallModeComponent`, `ProximityComponent`, etc.).

This decomposition is now more idiomatic ECS and better suited for efficient system iteration.

## Current Goal

Enable clean, isolated testing of the ECS foundation using realistic component data from Ball.