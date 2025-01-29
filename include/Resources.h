#pragma once

#include "Scene.h"
#include "Object.h"

class Resources {
public:
    // static 
private:
    std::list<Object *> Objects;
    std::list<Scene *> Scenes;
};