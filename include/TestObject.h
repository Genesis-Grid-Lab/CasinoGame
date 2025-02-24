#pragma once

#include "Object.h"
#include "Resources.h"

class TestObject : public Object{
public:
    TestObject(){
        Tex = TextureManager::loadTexture("Resources/individuals/card_back/card_back.png");
        Position = {100, 100};
    }
    void Update() override{

    }
    void Draw() override{
        Rectangle source = {0,0, (float)Tex.width, (float)Tex.height};    
        Vector2 center = {(float)Tex.width / 2, (float)Tex.height / 2};        
        DrawTexturePro(Tex, source, GetScreenRect(), center, 0, WHITE);
    }
private:
};