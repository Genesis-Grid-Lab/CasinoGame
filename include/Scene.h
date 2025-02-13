#pragma once

#include "Config.h"

class Object;

class Scene {
public:
    virtual ~Scene() = default;

  virtual void Start() {}

    virtual Ref<Scene> Update();

    virtual void Draw();

    void AddObject(Ref<Object> object);

private:
    std::list<Ref<Object>> Objects;
};
