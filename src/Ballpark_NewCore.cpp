// Copyright © 2026 Fenris Creations
// Phase 0 - ECS Foundation

#include "Ballpark_NewCore.h"

#if DESTINY_USE_NEW_CORE

namespace Destiny {

Ballpark_NewCore::Ballpark_NewCore() = default;
Ballpark_NewCore::~Ballpark_NewCore() = default;

void Ballpark_NewCore::InitializeNewCore() {
    if (!mSimulationCore) {
        mSimulationCore = std::make_unique<ecs::SimulationCore>();
        mSimulationCore->Initialize();
    }
}

} // namespace Destiny

#endif // DESTINY_USE_NEW_CORE
