#pragma once

#include "Config.h"

class Window {
 public:
  Window(){
  }

  bool Init(int width, int height, const char* title){
    InitWindow(width, height, title);
    SetTargetFPS(144);
    return true;
  }

  bool ShouldClose(){
    return !WindowShouldClose();
  }

  ~Window(){
    CloseWindow();
  }
};
