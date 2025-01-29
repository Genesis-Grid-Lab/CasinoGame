#pragma once

#include "Window.h"

class Application {
 public:
  Application(){
    if(!mWindow.Init(387, 688, "Casino")){
      printf("Failed to init window!");
    }
  }

  void Start(){
    
  }

  void Update(){
    
  }

  void Render(){
    BeginDrawing();
    ClearBackground(DARKGREEN);
    

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

};
