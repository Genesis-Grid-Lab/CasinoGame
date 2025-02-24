#pragma once

#include "Config.h"

class Scene {
public:
    virtual ~Scene() = default;

    virtual void Start() {}

    virtual Ref<Scene> Update();

    virtual void Draw();

private:

};
