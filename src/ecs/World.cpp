// Copyright © 2026 Fenris Creations
// Phase 0 - ECS Foundation

#include "World.h"

namespace ecs {

World::World() {
    mEntityManager = std::make_unique<EntityManager>();
}

World::~World() = default;

void World::Initialize() {
    // TODO(Phase 1): Replace maps with proper archetype/component storage
}

uint64_t World::CreateEntity() {
    return mEntityManager->CreateEntity();
}

void World::AddTransform(uint64_t entity, const TransformComponent& component) {
    mTransforms[entity] = component;
}

TransformComponent* World::GetTransform(uint64_t entity) {
    auto it = mTransforms.find(entity);
    return (it != mTransforms.end()) ? &it->second : nullptr;
}

bool World::HasTransform(uint64_t entity) const {
    return mTransforms.count(entity) > 0;
}

void World::AddPhysicsProperties(uint64_t entity, const PhysicsPropertiesComponent& component) {
    mPhysicsProperties[entity] = component;
}

PhysicsPropertiesComponent* World::GetPhysicsProperties(uint64_t entity) {
    auto it = mPhysicsProperties.find(entity);
    return (it != mPhysicsProperties.end()) ? &it->second : nullptr;
}

void World::AddMode(uint64_t entity, const ModeComponent& component) {
    mModes[entity] = component;
}

ModeComponent* World::GetMode(uint64_t entity) {
    auto it = mModes.find(entity);
    return (it != mModes.end()) ? &it->second : nullptr;
}

} // namespace ecs
