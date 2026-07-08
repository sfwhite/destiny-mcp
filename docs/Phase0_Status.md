# Phase 0 Status - ECS Foundation

**Branch:** `ecs/phase-0-foundation`
**Status:** In Progress

## Current Structure

All ECS pieces now have basic working functionality:

- `EntityManager`: Creates entity IDs
- `World`: Owns EntityManager + basic component storage (maps for now)
- `SimulationCore`: Owns World, can create entities and add components

## Completed

- [x] EntityManager
- [x] World with component storage
- [x] SimulationCore wired to World
- [x] Basic working flow: CreateEntity → AddComponent

## Next Priorities (before wiring to Ballpark)

- Make `Evolve()` do something meaningful (e.g. simple movement integration)
- Add a simple test or usage example
- Improve component access (maybe templated GetComponent later)
- Prepare clean API for `Ballpark_NewCore` to use
