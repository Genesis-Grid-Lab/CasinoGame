#pragma once

#include "Config.h"

class Scene {
public:
    virtual ~Scene() = default;

    virtual void Update() = 0;

    virtual void Draw() = 0;
};