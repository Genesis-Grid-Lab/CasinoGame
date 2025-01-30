#pragma once

#include "Window.h"
#include "Scene.h"
#include "MainMenuScene.h"

class Application {
 public:
  Application(){
    if(!mWindow.Init(387, 688, "Casino")){
      printf("Failed to init window!");
    }
  }

  void Start(){
    currentScene = CreateRef<MainMenu>();
    currentScene->Start();
  }

  void Update(){
    auto nextScene = currentScene->Update();
    if(nextScene){
        nextScene->Start();
        currentScene = nextScene;
    }
  }

  void Render(){
    BeginDrawing();
    currentScene->Draw();
    EndDrawing();
  }

  void Loop(){
    Start();

    while(mWindow.ShouldClose()){
      Update();
      Render();
    }
  }

  ~Application(){
  }

 private:
  Window mWindow;
  Ref<Scene> currentScene;
};
