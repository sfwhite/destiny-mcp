// Copyright © 2026 Fenris Creations
// Phase 0 - ECS Foundation

#pragma once

#include <cstdint>
#include <memory>

namespace ecs {

class World;
struct TransformComponent;
struct PhysicsPropertiesComponent;
struct ModeComponent;

/**
 * SimulationCore - High-level coordinator.
 * Owns the ECS World and will manage Systems.
 */
class SimulationCore {
public:
    SimulationCore();
    ~SimulationCore();

    void Initialize();
    bool IsInitialized() const { return mInitialized; }

    World& GetWorld() { return *mWorld; }
    const World& GetWorld() const { return *mWorld; }

    uint64_t CreateEntity();
    void DestroyEntity(uint64_t entity);

    void AddTransform(uint64_t entity, const TransformComponent& transform);
    void AddPhysicsProperties(uint64_t entity, const PhysicsPropertiesComponent& props);
    void AddMode(uint64_t entity, const ModeComponent& mode);

    void Evolve(double dt);

private:
    bool mInitialized = false;
    std::unique_ptr<World> mWorld;
};

} // namespace ecs
