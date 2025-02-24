#pragma once

#include "Object.h"
#include "Resources.h"

class Drop : public Object{
public:
    Drop(){
        Tex = TextureManager::loadTexture("Resources/individuals/card_back/card_back.png");
    }
    ~Drop(){

    }
    void Draw() override{
      Rectangle source = {0,0, (float)Tex.width, (float)Tex.height};
      Rectangle dst = {Position.x, Position.y, CARD_WIDTH, CARD_HEIGHT};
      Vector2 center = {(float)Tex.width / 2, (float)Tex.height / 2};
      // DrawRectangleRec(GetScreenRect(),GREEN);
      DrawRectanglePro(dst, center, 0,GREEN);
      // DrawTexturePro(*Tex, source, dst, Vector2Zero(), 0, WHITE);
    }
};
