# Phase 0 Status - ECS Foundation

**Branch:** `ecs/phase-0-foundation`

## Update: ArchetypeStorage Redesign

`ArchetypeStorage` has been redesigned to be **fully generic** from the beginning using variadic templates.

- No longer hardcodes specific component types.
- Uses `std::tuple<std::vector<Components>...>` for true Structure-of-Arrays storage.
- Designed so that any combination of components can be supported without core changes later.

This removes the need for future major refactors of the storage layer.

## Current State

- `ArchetypeStorage<Components...>` is now properly generic.
- `getComponentArray<T>()` implementation is pending (requires more template metaprogramming).
- `World` still uses a simplified approach for archetype management (to be improved).

Next focus areas:
- Complete generic component access.
- Improve entity movement between archetypes.
- Introduce a Component Registry for runtime type information.