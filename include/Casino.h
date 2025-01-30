#pragma once
#include "Scene.h"
#include "Card.h"
#include "Hand.h"

class Casino : public Scene {
public:
    Casino();
    ~Casino() override;
    void Start() override;

    Ref<Scene> Update() override;

    void Draw() override;

    void FromDeck(Ref<Deck>& deck);
    void Swap(size_t a, size_t b);
    void Shuffle(size_t factor = 4);
    void DrawCards(Ref<Hand>& player, Ref<Hand>& table);
private:
    std::vector<Ref<Card>> Cards;
    Ref<Hand> mHand;
    Ref<Hand> Table;
    Ref<Deck> mDeck;
};
