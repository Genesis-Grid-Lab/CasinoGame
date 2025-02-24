#include "Casino.h"
#include "MenuScene.h"
#include "raygui.h"
#include "Resources.h"

Casino::Casino(){

}

void Casino::Start(){
    mMenuClicked = false;
    tObject = ResourcesManager::CreateObject<Deck>(RandomU64());
    Vector2 pos = {100,100};
    // tObject->SetPosition(pos);
    tObject->Init(pos);
}

Ref<Scene> Casino::Update(){
    if(mMenuClicked){
        Ref<Menu> res = ResourcesManager::loadScene<Menu>("Menu");
        res->Start();
      return res;
    }

    // if()
    return nullptr;
}

void Casino::Draw(){
    ClearBackground(GREEN);
        if (GuiButton(Rectangle{(float)(GetScreenWidth() - 30),30,30,30}, GuiIconText(ICON_FILE_SAVE_CLASSIC, ""))) { mMenuClicked = true; }
}