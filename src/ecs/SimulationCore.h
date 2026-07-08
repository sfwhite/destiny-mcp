// Copyright © 2026 sfwhite
// https://github.com/sfwhite
// Phase 0 - ECS Foundation (modified)

#pragma once

#include <cstdint>
#include <memory>

namespace ecs {

class World;
struct TransformComponent;
struct PhysicsPropertiesComponent;
struct ModeComponent;

class SimulationCore {
public:
    SimulationCore();
    ~SimulationCore();

    void Initialize();
    bool IsInitialized() const;

    World& GetWorld();
    const World& GetWorld() const;

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
