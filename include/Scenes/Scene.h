#pragma once

#include "Config.h"
//
#include <memory>

class Scene {
public:
    virtual ~Scene() = default;

    virtual void Start() {}

    virtual std::shared_ptr<Scene> Update();

    virtual void Draw();

private:

};
