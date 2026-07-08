# ECS Conversion Execution Plan for Destiny

**Branch:** `ecs/phase-0-foundation`
**Goal:** Introduce a high-performance internal data-oriented core while preserving **100% of external interfaces** with **zero modifications required to other modules**.
**Primary Objective:** Reduce TIDI through significantly better simulation performance.

## 1. Executive Summary

This plan describes a low-risk migration to a high-performance internal simulation core (data-oriented / ECS-inspired) **entirely contained within the Destiny module**.

**Critical Constraint:** No changes are allowed (or desired) in Scheduler, networking, IO, Python server logic, database layers, or any other Carbon module. All external interfaces must remain completely unchanged.

**Core Strategy:**
- Keep `Ball` and `ClientBall` as stable, instantiable types that external code can continue to use.
- `Ballpark` acts as the internal smart factory and facade.
- When the new core is enabled, `Ball` objects function as **thin adapters** that delegate hot-path work to the new `SimulationCore`.
- All performance improvements happen internally without affecting any callers outside Destiny.

## 2. Current Problems

- `Ball` is a large, state-heavy god object with poor cache locality.
- High cost of entity creation/destruction (especially transient objects like drones and missiles).
- Difficult to parallelize the simulation loop.
- These issues contribute to TIDI under heavy load.

## 3. Architecture Overview (Updated Strategy)

**Stable Facade + Internal High-Performance Core + Compatibility Adapters**

- **`Ballpark` / `IEveBallpark`**: Remains the public interface. No signature or behavioral changes.
- **`Ball` / `ClientBall`**: Continue to exist as public types. External modules can still do `new Ball(...)` or hold `Ball*` pointers.
- **New `SimulationCore`**: Contains the high-performance data-oriented logic (components, systems, spatial queries).
- **Adapter Pattern**: When `DESTINY_USE_NEW_CORE` is enabled, `Ball` objects become lightweight adapters that forward relevant operations to the new core.

This design ensures **zero disruption** to any module that currently interacts with Destiny.

## 4. Phased Execution Plan

### Phase 0: Foundation (Current)
- Add feature flag `DESTINY_USE_NEW_CORE`.
- Create `src/ecs/` directory and initial component structs.
- Create `SimulationCore` stub.
- Establish dual-path capability inside `Ballpark` (legacy vs new core).
- Begin designing `Ball` as an adapter when the new core is active.

### Phase 1: Internal Core + Adapter Layer
- Implement basic entity management and component storage in `SimulationCore`.
- Make `Ballpark` route creation and hot-path operations through `SimulationCore` when the flag is enabled.
- Evolve `Ball` into a thin adapter (still fully functional for external code).
- Add side-by-side benchmarking.

### Phase 2: Spatial, Collision & Core Systems
- Port the hierarchical grid and collision logic to be data-oriented inside `SimulationCore`.
- Implement `EvolveSystem`, broad/narrow phase collision, and proximity as systems.
- Ensure `Ball` adapter continues to provide full compatibility.

### Phase 3: Behavioral Migration
- Move mode handling, mini-shapes, formation, etc. into the new core.
- `Ball` adapter continues to expose the same public interface.

### Phase 4: Validation & Optimization
- Comprehensive benchmarking (see section below).
- Determinism verification.
- Performance tuning of the new core.

### Phase 5: Cutover
- Make new core the default.
- Legacy path can be removed in a later cleanup phase if desired.

## 5. Interface Stability Guarantees (Strict)

**No changes required in any other module.**

- `IEveBallpark` method signatures and semantics remain identical.
- All Python bindings and Blue-exposed methods stay the same.
- `Ball` and `ClientBall` remain instantiable and usable exactly as before.
- State serialization, delta compression, and client interpolation are unchanged.
- Scheduler, networking, IO, and database layers see no difference in behavior.
- Existing Python server code continues to work without modification.

The only observable change from outside Destiny will be **better performance** under load.

## 6. Benchmark Strategy

All benchmarks will compare the legacy path vs the new core using the same `Ballpark` interface.

**Key Metrics:**
- Tick time vs entity count (primary TIDI indicator)
- Entity creation/destruction cost
- Collision and spatial query performance
- Memory usage
- Determinism (full state hash comparison)

**Success Target:** Clear, measurable improvement in simulation throughput while maintaining full compatibility.

## 7. Risks & Mitigations

- **Risk**: External code relies on direct `Ball` construction or internal `Ball` members.
  **Mitigation**: `Ball` remains a fully functional type (as adapter when new core is active). No breaking changes.
- **Risk**: Determinism differences.
  **Mitigation**: Side-by-side execution + hash comparison during development.
- **Risk**: Performance regression in early phases.
  **Mitigation**: Feature flag allows instant rollback to legacy path.

## 8. Success Criteria

- New internal core delivers measurable reduction in tick time under high load.
- **Zero modifications** required in any module outside Destiny.
- All existing interfaces and behaviors remain 100% compatible.
- Comprehensive benchmark data proves the performance advantage.
- The branch is ready for internal review by Fenris Creations.

---

**Document Version:** 2.0 (Updated for stable `Ball` adapter strategy)
**Last Updated:** Phase 0 branch
**Key Principle:** All changes are isolated to Destiny. Other modules require no modifications whatsoever.