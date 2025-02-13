#pragma once

#include "Scene.h"

class Menu : public Scene {
 public:
  Menu();
  ~Menu() override;

  void Start() override;

  Ref<Scene> Update() override;
  void Draw() override;

 private:
  bool Clicked;
};
