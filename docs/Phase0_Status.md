# Phase 0 Status - ECS Foundation

**Branch:** `ecs/phase-0-foundation`

## Cleanup: Strict Sourcing Applied

`Components.h` has been cleaned up to only contain fields that exist in the original Destiny code.

Every attribute now has an explicit comment showing its source (primarily from `Ball.h`, `ProximitySensor`, Mini* shapes, spatial partitioning, and related Ballpark structures).

Invented or generalized attributes have been removed.