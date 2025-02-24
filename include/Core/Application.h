#pragma once
#include "Config.h"
#include "Window.h"
#include "Scene.h"

class Application {
 public:
  Application();
  ~Application();

  void Start();

  void Update();

  void Render();

  void Loop();

 private:
  Window mWindow;
  Camera2D camera = {0};
  Ref<Scene> currentScene;
};
