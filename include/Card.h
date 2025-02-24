#pragma once

#include "Object.h"

enum class CardSuit{
    Club,
    Diamond,
    Heart,
    Spades,
};

class Card : public Object{
public:
    Card();
    ~Card();

    void Init(int value, CardSuit suit, std::string tex);
    void Draw() override;

    inline int GetValue() { return Value;}
    inline CardSuit GetSuit() { return Suit;}
private:
    int Value;
    CardSuit Suit;
};

class Deck : public Object {
public:
    Deck();
    ~Deck();

    void Init(Vector2& pos);
    void Draw() override;

    inline std::vector<Ref<Card>>& GetCards() { return Cards;}
private:
    std::vector<Ref<Card>> Cards;
};