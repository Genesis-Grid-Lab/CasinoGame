#pragma once
#include "Drop.h"

class Hand : public Object {
public:
    Hand(int numDrop = 4): NumDrop(numDrop){
        for(int i = 1; i <= numDrop; i++){
            Places.push_back(CreateRef<Drop>());
        }
    }

    void Update() override{
        int offset = 3;
        Vector2 tmp = Position;
        int counter = 0;
        for(auto& drop : Places){
            int dropW = CARD_WIDTH,
                dropH = CARD_HEIGHT;
            int dropP = dropW + offset;
            drop->SetPosition(tmp);

	    tmp = {tmp.x + dropW + 5, tmp.y};
        }

    }

    std::vector<Ref<Drop>>& GetPlaces() { return Places;}

    void Draw() override{
        int width = CARD_WIDTH,
            height = CARD_HEIGHT;

        int offset = 5;

        int grayPosW = (width * 4) + (offset * 4),
            grayPosH = (height * (NumDrop / 4)) + (offset * 4);

	Rectangle source = {0, 0, (float)grayPosW, (float)grayPosH};
	Rectangle dst = {Position.x - 5, Position.y - 5, (float)grayPosW, (float)grayPosH};
        // DrawRectangle(Position.x - 5, Position.y - 5, grayPosW, grayPosH, LIGHTGRAY);
	Vector2 center = {(float)grayPosW / 2, (float)grayPosH / 2};
	DrawRectanglePro(dst, Vector2Zero(), 0, LIGHTGRAY);
    }

private:
    std::vector<Ref<Drop>> Places;
    int NumDrop;
};
