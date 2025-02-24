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
    ResourcesManager::loadScene<Casino>("Casino");
    currentScene = ResourcesManager::loadScene<MainMenu>("MainMenu");
    currentScene->Start();
  }

  void Update(){
    // printf("%i\n", (int)ObjectManager::GetObjects().size());
    for(auto const& [id, object] : ResourcesManager::GetObjects()){
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
    for(auto& object : ResourcesManager::GetObjects()){
      object.second->Draw();
    }

    for(auto it = ResourcesManager::GetObjects().begin(); it != ResourcesManager::GetObjects().end(); it++){
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
