// Copyright © 2026 sfwhite
// https://github.com/sfwhite
// Phase 0 - ECS Foundation

#include "ArchetypeStorage.h"

namespace ecs {

ArchetypeStorage::ArchetypeStorage(const Archetype& archetype)
    : mArchetype(archetype) {}

void ArchetypeStorage::AddEntity(uint64_t entity,
                                   const TransformComponent& transform,
                                   const PhysicsPropertiesComponent& physics,
                                   const ModeComponent& mode) {
    mEntities.push_back(entity);
    mTransforms.push_back(transform);
    mPhysicsProperties.push_back(physics);
    mModes.push_back(mode);
}

} // namespace ecs
