#include "Card.h"
#include "Resources.h"

//--------------------- Cards------------------------------------
Card::Card(){

}

Card::~Card(){

}

void Card::Init(int value, CardSuit suit, std::string tex){
    Tex = TextureManager::loadTexture(tex);
    Value = value;
    Suit = suit;
}

void Card::Draw(){
    Rectangle source = {0,0, (float)Tex.width, (float)Tex.height};    
    Vector2 center = {(float)Tex.width / 2, (float)Tex.height / 2};        
    DrawTexturePro(Tex, source, GetScreenRect(), center, 0, WHITE);
}


//--------------------------- Deck ------------------------------------
Deck::Deck(){

}

Deck::~Deck(){

}

void Deck::Init(Vector2& pos){
    Position = pos;
    std::string resourcePath = "Resources/individuals/";
    std::string name, filePath;

    Tex = TextureManager::loadTexture("Resources/individuals/card_back/card_back.png");

    for(int i = 1; i <= 13; i++){
        name = "club/" + std::to_string(i) + "_club.png";
        filePath = resourcePath + name;
        Cards.emplace_back(ResourcesManager::CreateObject<Card>(RandomU64()));
        Cards.front()->Init(i, CardSuit::Club, filePath);

        name = "diamond/" + std::to_string(i) + "_diamond.png";
        filePath = resourcePath + name;
        Cards.emplace_back(ResourcesManager::CreateObject<Card>(RandomU64()));
        Cards.front()->Init(i, CardSuit::Diamond, filePath);

        name = "heart/" + std::to_string(i) + "_heart.png";
        filePath = resourcePath + name;
        Cards.emplace_back(ResourcesManager::CreateObject<Card>(RandomU64()));
        Cards.front()->Init(i, CardSuit::Heart, filePath);

        name = "spade/" + std::to_string(i) + "_spade.png";
        filePath = resourcePath + name;
        Cards.emplace_back(ResourcesManager::CreateObject<Card>(RandomU64()));
        Cards.front()->Init(i, CardSuit::Spades, filePath);
    }

    for(auto& card : Cards){
        card->SetPosition(Position);
    }
}

void Deck::Draw(){
    Rectangle source = {0,0, (float)Tex.width, (float)Tex.height};
    Vector2 center = {(float)Tex.width / 2, (float)Tex.height / 2};      
    DrawTexturePro(Tex, source, GetScreenRect(), center, 90, WHITE);
}