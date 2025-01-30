#pragma once

#include "Scene.h"

class MainMenu : public Scene{
public:
    MainMenu();
    ~MainMenu() override;
    void Start() override;

    Ref<Scene> Update() override;

    void Draw() override;
private:
    bool Clicked;
};
