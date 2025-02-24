#pragma once

#include "Scene.h"

class Menu : public Scene {
 public:
  Menu();
  ~Menu() override;

  void Start() override;

  std::shared_ptr<Scene> Update() override;
  void Draw() override;

 private:
  bool Clicked;
};