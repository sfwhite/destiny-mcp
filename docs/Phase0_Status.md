# Phase 0 Status - ECS Foundation

**Branch:** `ecs/phase-0-foundation`

## Step 2: Improving World

`World` has been updated to better track entity-to-archetype relationships and manage `ArchetypeStorage` instances.

Key improvements:
- Added `mEntityToSignature` map to track which archetype each entity belongs to.
- Introduced `IArchetypeStorage` base class + `ArchetypeStorageWrapper` for type-erased storage management.
- Component addition now updates the entity's current signature.

Note: Full archetype transitions (moving component data between storages) are still simplified. This will be addressed in Step 4.

## Progress on the List

- [x] 1. Implement getComponentArray<T>()
- [x] 2. Improve World archetype management
- [ ] 3. Add a basic Component Registry
- [ ] 4. Start handling archetype transitions