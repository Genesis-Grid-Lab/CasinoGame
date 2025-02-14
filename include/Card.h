#pragma once

#include "Object.h"
#include "Resources.h"
#include "raymath.h"

enum class CardSuit
{
	Club,
	Diamond,
	Heart,
	Spades,
};

class Card : public Object{
public:
    Card(){        
    }
   ~Card(){
   }

  void SetUp(int value,CardSuit suit, std::string tex){
    Tex = TextureManager::loadTexture(tex);
    Value = value;
    Suit = suit;
  }

   void Draw() override{

     // Rectangle source = {0,0, (float)Tex->width, (float)Tex->height};
     // Rectangle dst = {Position.x, Position.y, CARD_WIDTH, CARD_HEIGHT};
     // Vector2 center = {(float)Tex->width / 2, (float)Tex->height / 2};
     //   // DrawTextureV(*Tex, Position, WHITE);
       DrawTextureRec(*Tex, GetScreenRect(), Position, WHITE);
     //   DrawTexturePro(*Tex, source, dst, center, 0, WHITE);
   }

   int GetValue(){ return Value;}
   CardSuit GetSuit() { return Suit;}
private:
    int Value;
    CardSuit Suit;
};


class Deck : public Object{
public:
  Deck(){
    Position = {100, 100};
    std::string resourcePath = "Resources/individuals/";
    std::string name, filepath;
    Tex = TextureManager::loadTexture("Resources/individuals/card_back/card_back.png");

        for(int i = 1; i <= 13; i++){
            name = "club/" + std::to_string(i) + "_club.png";
            filepath = resourcePath + name;
            Cards.emplace_back(ResourcesManager<Card>::CreateObject(RandomU64()));
	    Cards.front()->SetUp(i, CardSuit::Club, filepath);
            name = "diamond/" + std::to_string(i) + "_diamond.png";
            filepath = resourcePath + name;
            Cards.emplace_back(ResourcesManager<Card>::CreateObject(RandomU64()));
	    Cards.front()->SetUp(i, CardSuit::Diamond, filepath);
            name = "heart/" + std::to_string(i) + "_heart.png";
            filepath = resourcePath + name;
            Cards.emplace_back(ResourcesManager<Card>::CreateObject(RandomU64()));
	    Cards.front()->SetUp(i, CardSuit::Heart, filepath);
            name = "spade/" + std::to_string(i) + "_spade.png";
            filepath = resourcePath + name;
            Cards.emplace_back(ResourcesManager<Card>::CreateObject(RandomU64()));
	    Cards.front()->SetUp(i, CardSuit::Spades, filepath);
        }

        for(auto& card : Cards){
            card->SetPosition(Position);
        }
    }

    void Draw() override {
      Rectangle source = {0,0, (float)Tex->width, (float)Tex->height};
      Rectangle dst = {Position.x, Position.y, CARD_WIDTH, CARD_HEIGHT};
      Vector2 center = {(float)Tex->width / 2, (float)Tex->height / 2};
      // DrawTextureV(*Tex,Position, WHITE);
      DrawTexturePro(*Tex, source, dst, center, 90, WHITE);
    }

    std::vector<Ref<Card>>& GetCards() { return Cards;}

private:
    std::vector<Ref<Card>> Cards;
};
