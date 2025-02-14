#pragma once

#include "Object.h"
#include "Window.h"
#include "Scene.h"
#include "MainMenuScene.h"
#include "Resources.h"
#include "Casino.h"

class Application {
 public:
  Application(){
    if(!mWindow.Init(387, 688, "Casino")){
      printf("Failed to init window!");
    }
  }

  void Start(){
    ResourcesManager<Casino>::loadScene("Casino");
    currentScene = ResourcesManager<MainMenu>::loadScene("MainMenu");
    currentScene->Start();
  }

  void Update(){
    // printf("%i\n", (int)ObjectManager::GetObjects().size());
    for(auto const& [id, object] : ResourcesManager<Card>::GetObjects()){
      object->Update();
    }
    auto nextScene = currentScene->Update();
    if(nextScene){
        nextScene->Start();
        currentScene = nextScene;
    }
  }

  void Render(){
    BeginDrawing();
    for(auto& object : ResourcesManager<Card>::GetObjects()){
      // object.second->Draw();
    }

    for(auto it = ResourcesManager<Card>::GetObjects().begin(); it != ResourcesManager<Card>::GetObjects().end(); it++){
      // it->second->Draw();      
    }
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
