#pragma once
#include "Scene.h"

class TestScene : public Scene{
public:
    TestScene(){

    }
    void Start() override{

    }
    Ref<Scene> Update() override{
        return nullptr;
    }
    void Draw() override{

    }
private:
};