#pragma once

#include "Config.h"

class Object{
 public:
  virtual ~Object() = default;

  virtual void Draw(){}

  virtual void Update() {}

  inline void SetPosition(Vector2& Pos){
      Position = Pos;
  }

  inline Vector2 GetPosition(){ return Position;}

  inline Rectangle GetScreenRect(){
   	return Rectangle{ Position.x , Position.y, (float)Tex->width, (float)Tex->height };
  }

  inline bool PointIn(const Vector2& pos){
	return CheckCollisionPointRec(pos, GetScreenRect());
  }

  inline Ref<Texture>& GetTexture() { return Tex;}
 protected:
  Vector2 Position = {0};
  Ref<Texture> Tex = nullptr;
};
