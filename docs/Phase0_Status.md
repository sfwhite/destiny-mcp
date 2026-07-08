# Phase 0 Status - ECS Foundation

**Branch:** `ecs/phase-0-foundation`

## Step 3: Basic Component Registry

Added a simple `ComponentRegistry` class.

- Assigns stable runtime IDs to component types using `std::type_index`.
- Provides `registerComponent<T>()` and `getComponentId<T>()`.
- This is the foundation for making archetype management and storage more generic in future steps.

This is still minimal but provides the runtime type identification needed for a proper generic ECS.

## Progress

- [x] 1. Implement getComponentArray<T>()
- [x] 2. Improve World
- [x] 3. Add basic Component Registry
- [ ] 4. Start handling archetype transitions