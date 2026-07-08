# Phase 0 Status - ECS Foundation

**Branch:** `ecs/phase-0-foundation`

## Update: Collision Shape Primitives Added

Added dedicated components for Mini* collision shapes:

- `SphereComponent` (MiniBall)
- `BoxComponent` (MiniBox)
- `CapsuleComponent` (MiniCapsule)

These allow entities to have complex or compound collision geometry in addition to the base `CollidableComponent`.

All components remain in the single `Components.h` file as requested.