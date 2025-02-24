#include "Application.h"
#include "Resources.h"
#include "MainScene.h"

Application::Application(){
    if(!mWindow.Init(SCREEN_WIDTH, SCREEN_HEIGHT, "Casino")){
      printf("Failed to init window!");
    }

    // camera.target = Vector2{SCREEN_WIDTH, SCREEN_HEIGHT};
    camera.zoom = 1.0f;
}

Application::~Application(){

}

void Application::Start(){
    currentScene = ResourcesManager::loadScene<MainMenu>("MainMenu");
    currentScene->Start();
}

void Application::Update(){
    auto nextScene = currentScene->Update();
    for(auto const& [id, object] : ResourcesManager::GetObjects()){
      object->Update();
    }
    if(nextScene){
        // nextScene->Start();
        currentScene = nextScene;
    }
}

void Application::Render(){
    BeginDrawing();
    currentScene->Draw();
    BeginMode2D(camera);
    for(auto const& [id, object] : ResourcesManager::GetObjects()){
      object->Draw();
    }
    EndMode2D();
    EndDrawing();
}

void Application::Loop(){
    Start();

    while(mWindow.ShouldClose()){
      Update();
      Render();
    }

    mWindow.~Window();
}