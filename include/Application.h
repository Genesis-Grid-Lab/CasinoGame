#pragma once

#include "Object.h"
#include "Window.h"
#include "Scene.h"
#include "Resources.h"
#include "TestScene.h"

class Application {
 public:
  Application(){
    if(!mWindow.Init(SCREEN_WIDTH, SCREEN_HEIGHT, "Casino")){
      printf("Failed to init window!");
    }

    // camera.target = Vector2{SCREEN_WIDTH/2, SCREEN_HEIGHT/2};
    camera.zoom = 1.0f;
  }

  void Start(){
    currentScene = ResourcesManager::loadScene<TestScene>("MainMenu");
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
    BeginMode2D(camera);
    for(auto& object : ResourcesManager::GetObjects()){
      object.second->Draw();
    }

    for(auto it = ResourcesManager::GetObjects().begin(); it != ResourcesManager::GetObjects().end(); it++){
      // it->second->Draw();      
    }
    currentScene->Draw();
    EndMode2D();
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
  Camera2D camera = {0};
  Ref<Scene> currentScene;
};
