// Copyright © 2026 Fenris Creations
// Phase 0 - ECS Foundation
// Dual-path support for new SimulationCore inside Ballpark

#pragma once

#include "DestinyConfig.h"

#if DESTINY_USE_NEW_CORE
#include "SimulationCore.h"
#include <memory>

namespace Destiny {

class Ballpark_NewCore {
public:
    Ballpark_NewCore();
    ~Ballpark_NewCore();

    void InitializeNewCore();

    ecs::SimulationCore* GetSimulationCore() { return mSimulationCore.get(); }

private:
    std::unique_ptr<ecs::SimulationCore> mSimulationCore;
};

} // namespace Destiny

#endif // DESTINY_USE_NEW_CORE
