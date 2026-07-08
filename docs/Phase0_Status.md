# Phase 0 Status - ECS Foundation

**Branch:** `ecs/phase-0-foundation`

## Major Update: Comprehensive Ball Data Decomposition

Created `src/ecs/BallComponents.h` containing a broad set of data components extracted from the original `Ball` class.

This allows the new ECS side to be tested in isolation with realistic data structures.

Components created:
- TransformComponent
- PhysicsPropertiesComponent
- BallModeComponent
- CompoundShapeComponent
- ProximityComponent
- OwnershipComponent
- FormationComponent
- CloakComponent
- HarmonicsComponent
- SpatialPartitionComponent

These are pure data structs. Mutation logic will be moved into Systems in later steps.

## Goal

Enable standalone testing of the ECS boilerplate (`World`, `ArchetypeStorage`, `SimulationCore`, etc.) using realistic component data before any integration with the legacy `Ball` / `Ballpark` code.