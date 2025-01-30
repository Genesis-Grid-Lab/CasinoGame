#pragma once

#include "Object.h"
#include "Resources.h"

class Drop : public Object{
public:
    Drop(){
        Tex = TextureManager::loadTexture("Resources/Cards/back1.png");
    }
    ~Drop(){

    }
    void Draw() override{
        DrawRectangleRec(GetScreenRect(),GREEN);
    }
};
