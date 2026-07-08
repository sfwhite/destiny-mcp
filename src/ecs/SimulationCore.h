// Copyright © 2026 Fenris Creations
// Phase 0 - ECS Foundation

#pragma once

#include <cstdint>

namespace ecs {

// Forward declarations
struct TransformComponent;
struct PhysicsPropertiesComponent;
struct ModeComponent;

/**
 * SimulationCore - High-performance internal simulation core.
 * This will eventually replace the heavy Ball + Partition logic inside Ballpark.
 * Phase 0: Minimal stub for foundation and benchmarking.
 */
class SimulationCore {
public:
    SimulationCore();
    ~SimulationCore();

    // Entity management (IDs only in Phase 0)
    uint64_t CreateEntity();
    void DestroyEntity(uint64_t entity);

    // Basic component attachment (Phase 0 stubs)
    void AddTransform(uint64_t entity, const TransformComponent& transform);
    void AddPhysicsProperties(uint64_t entity, const PhysicsPropertiesComponent& props);
    void AddMode(uint64_t entity, const ModeComponent& mode);

    // Minimal evolve step (will grow significantly)
    void Evolve(double dt);

private:
    // Internal registry / storage will be implemented in later phases
    // For now this is a stub to allow compilation and benchmarking setup
};

} // namespace ecs
