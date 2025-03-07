#pragma once

#include "Config.h"

class Window {
 public:
  Window(){
  }

  inline bool Init(int width, int height, const char* title){
    InitWindow(width, height, title);
    SetTargetFPS(144);
    return true;
  }

  inline bool ShouldClose(){
    return !WindowShouldClose();
  }

  ~Window(){
    CloseWindow();
  }
};
