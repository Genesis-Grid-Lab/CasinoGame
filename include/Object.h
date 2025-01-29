#pragma once

#include "Config.h"

class Object{
 public:
  virtual ~Object() = default;

  virtual void Draw() = 0;
  
 private:
  Vector2 Position;
  Texture Tex;
};
