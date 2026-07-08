// Copyright © 2026 Fenris Creations
// Phase 0 - ECS Foundation

#pragma once

#include <cstdint>
#include <memory>

namespace ecs {

struct TransformComponent;
struct PhysicsPropertiesComponent;
struct ModeComponent;

/**
 * SimulationCore - High-performance internal simulation core.
 * Owns the entity registry and will eventually own all Systems.
 */
class SimulationCore {
public:
    SimulationCore();
    ~SimulationCore();

    // Initialize the core (entity storage, default systems, etc.)
    void Initialize();

    bool IsInitialized() const { return mInitialized; }

    // Entity management
    uint64_t CreateEntity();
    void DestroyEntity(uint64_t entity);

    // Component attachment (Phase 0/1)
    void AddTransform(uint64_t entity, const TransformComponent& transform);
    void AddPhysicsProperties(uint64_t entity, const PhysicsPropertiesComponent& props);
    void AddMode(uint64_t entity, const ModeComponent& mode);

    // Main simulation step
    void Evolve(double dt);

private:
    bool mInitialized = false;
    // Future: entity registry, system list, spatial index, etc.
};

} // namespace ecs
