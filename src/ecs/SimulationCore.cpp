// Copyright © 2026 Fenris Creations
// Phase 0 - ECS Foundation

#include "SimulationCore.h"
#include "World.h"
#include <iostream>

namespace ecs {

SimulationCore::SimulationCore() {
    mWorld = std::make_unique<World>();
}

SimulationCore::~SimulationCore() = default;

void SimulationCore::Initialize() {
    if (mInitialized) return;

    mWorld->Initialize();
    std::cout << "[SimulationCore] Initialized ECS World.\n";

    mInitialized = true;
}

uint64_t SimulationCore::CreateEntity() {
    return mWorld->GetEntityManager().CreateEntity();
}

void SimulationCore::DestroyEntity(uint64_t entity) {
    mWorld->GetEntityManager().DestroyEntity(entity);
}

void SimulationCore::AddTransform(uint64_t entity, const TransformComponent& transform) {}
void SimulationCore::AddPhysicsProperties(uint64_t entity, const PhysicsPropertiesComponent& props) {}
void SimulationCore::AddMode(uint64_t entity, const ModeComponent& mode) {}

void SimulationCore::Evolve(double dt) {
    if (!mInitialized) return;
    // TODO: Run Systems
}

} // namespace ecs
