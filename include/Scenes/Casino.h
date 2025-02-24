#pragma once
#include "Scene.h"
#include "Card.h"

class Casino : public Scene{
public:
    Casino();
    void Start() override;
    Ref<Scene> Update() override;
    void Draw() override;
private:
    Ref<Deck> tObject;
    bool mMenuClicked;
};