#pragma once

#include "Object.h"
#include "Resources.h"

enum class CardSuit
{
	Club,
	Diamond,
	Heart,
	Spades,
};

class Card : public Object{
public:
    Card(int value,CardSuit suit, std::string tex): Value(value), Suit(suit){
        Tex = TextureManager::loadTexture(tex);
    }
   ~Card(){
   }

   void Draw() override{
       DrawTextureV(*Tex, Position, WHITE);
       // DrawTextureRec(*Tex, GetScreenRect(), Position, WHITE);
   }

   int GetValue(){ return Value;}
   CardSuit GetSuit() { return Suit;}
private:
    int Value;
    CardSuit Suit;
};


class Deck : public Object{
public:
    Deck(Vector2& pos){
        Position = pos;
        std::string resourcePath = "Resources/Cards/";
        std::string name, filepath;
        Tex = TextureManager::loadTexture("Resources/Cards/back1.png");

        for(int i = 1; i <= 13; i++){
            name = "c" + std::to_string(i) + ".png";
            filepath = resourcePath + name;
            Cards.emplace_back(CreateRef<Card>(i, CardSuit::Club, filepath));
            name = "d" + std::to_string(i) + ".png";
            filepath = resourcePath + name;
            Cards.emplace_back(CreateRef<Card>(i, CardSuit::Diamond, filepath));
            name = "h" + std::to_string(i) + ".png";
            filepath = resourcePath + name;
            Cards.emplace_back(CreateRef<Card>(i, CardSuit::Heart, filepath));
            name = "s" + std::to_string(i) + ".png";
            filepath = resourcePath + name;
            Cards.emplace_back(CreateRef<Card>(i, CardSuit::Spades, filepath));
        }

        for(auto& card : Cards){
            card->SetPosition(Position);
        }
    }

    void Draw() override {
        DrawTextureV(*Tex,Position, WHITE);
    }

    std::vector<Ref<Card>>& GetCards() { return Cards;}

private:
    std::vector<Ref<Card>> Cards;
};
