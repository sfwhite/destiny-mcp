// Copyright © 2026 sfwhite
// https://github.com/sfwhite
// Phase 0 - ECS Foundation (modified)

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
    mInitialized = true;
}

bool SimulationCore::IsInitialized() const { return mInitialized; }

World& SimulationCore::GetWorld() { return *mWorld; }
const World& SimulationCore::GetWorld() const { return *mWorld; }

uint64_t SimulationCore::CreateEntity() { return mWorld->CreateEntity(); }
void SimulationCore::DestroyEntity(uint64_t entity) { mWorld->GetEntityManager().DestroyEntity(entity); }

void SimulationCore::AddTransform(uint64_t entity, const TransformComponent& transform) { mWorld->AddTransform(entity, transform); }
void SimulationCore::AddPhysicsProperties(uint64_t entity, const PhysicsPropertiesComponent& props) { mWorld->AddPhysicsProperties(entity, props); }
void SimulationCore::AddMode(uint64_t entity, const ModeComponent& mode) { mWorld->AddMode(entity, mode); }

void SimulationCore::Evolve(double dt) {}

} // namespace ecs
