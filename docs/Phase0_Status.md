# Phase 0 Status - ECS Foundation

**Branch:** `ecs/phase-0-foundation`

## Major Update

Following feedback, `ArchetypeStorage` is being redesigned as a **variadic template** to support generics from the beginning, rather than hardcoding specific components.

This aligns with the goal of avoiding major refactors later.

Current approach:
- `ArchetypeStorage<Components...>` uses `std::tuple<std::vector<Components>...>` for SoA storage.
- `World` will manage different template instantiations of `ArchetypeStorage`.

Note: Full generic component access (`getComponent<T>()`) will require additional metaprogramming, which will be added incrementally.