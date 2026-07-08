# Phase 0 Status - ECS Foundation

**Branch:** `ecs/phase-0-foundation`

## Step 4: Beginning Archetype Transitions

We have started implementing archetype transition support in `World`.

- Added `MoveEntityToArchetype()` method.
- Component addition methods now call into the transition logic when the entity's component set changes.
- Entity signature tracking (`mEntityToSignature`) is actively used.

**Current Limitations (documented):**
- Actual component data is not yet copied/moved between `ArchetypeStorage` instances when an entity changes archetypes.
- Removal from the old storage is not yet implemented.
- This is intentional scaffolding to establish the architecture correctly.

## Overall Progress

- [x] 1. `getComponentArray<T>()`
- [x] 2. Improve `World` management
- [x] 3. Basic Component Registry
- [x] 4. Start archetype transitions (foundation laid)

The core pieces are now in place. Future work can focus on completing data migration and integrating with `SimulationCore` and `Ballpark`.