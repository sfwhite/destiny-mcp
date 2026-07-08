# Phase 0 Status - ECS Foundation

**Branch:** `ecs/phase-0-foundation`

## Update: Generic ArchetypeStorage

`ArchetypeStorage` has been upgraded to a fully variadic template version with working `getComponentArray<T>()`.

- Uses `std::tuple<std::vector<Components>...>` for SoA storage.
- `getComponentArray<T>()` is now implemented using compile-time `index_of` metaprogramming.
- The class is now properly generic and does not hardcode any specific component types.

This fulfills the requirement to design the storage layer correctly from the beginning.

## Next on the List

2. Improve `World` to manage multiple `ArchetypeStorage<...>` instantiations properly.