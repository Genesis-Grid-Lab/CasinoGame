#pragma once

#include "Scene.h"

class Casino : public Scene {
public:
    Casino();
    ~Casino() override;

    void Update() override;

    void Draw() override;
};