#pragma once

#include "Config.h"

class Object{
 public:
  virtual ~Object() = default;

  virtual void Draw(){ printf("Drawing");}

  virtual void Update() {}

  inline void SetPosition(Vector2& Pos){
      Position = Pos;
  }

  inline Vector2 GetPosition(){ return Position;}

  inline Rectangle GetScreenRect(){
   	return Rectangle{ Position.x , Position.y, CARD_WIDTH, CARD_HEIGHT };
  }

  inline bool PointIn(const Vector2& pos){
	return CheckCollisionPointRec(pos, GetScreenRect());
  }

  inline Ref<Texture>& GetTexture() { return Tex;}

  inline uint64_t const GetID() { return id;}
 protected:
  Vector2 Position = {0};
  Ref<Texture> Tex = nullptr;
  uint64_t id = RandomU64();
};
