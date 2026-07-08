# Phase 0 Status - ECS Foundation

**Branch:** `ecs/phase-0-foundation`

## Update: Bubble and Wreck Components Added

Added two more key components:

- `BubbleComponent` — Spatial interest management and grid partitioning regions.
- `WreckComponent` — For dead/static objects (wrecks/debris) that remain collidable.

This continues the systematic decomposition of Ballpark children into clean ECS components.

All components remain consolidated in `src/ecs/Components.h`.