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
            int dropW = drop->GetTexture()->width,
                dropH = drop->GetTexture()->height;
            int dropP = dropW + offset;
            drop->SetPosition(tmp);
            if(counter == 3){
                tmp = {tmp.x - (dropP * 3), tmp.y + (dropH + offset) };
            }
            else if(counter == 7){
                tmp = {tmp.x - (dropP * 3), tmp.y + (dropH + offset) };
            }
            else if (counter == 11){
                tmp = {tmp.x - (dropP * 3), tmp.y + (dropH + offset) };
            }
            else
                tmp = {tmp.x + dropP, tmp.y };
            counter = counter + 1;
        }

    }

    std::vector<Ref<Drop>>& GetPlaces() { return Places;}

    void Draw() override{
        int width = Places.front()->GetTexture()->width,
            height = Places.front()->GetTexture()->height;

        int offset = 5;

        int grayPosW = (width * 4) + (offset * 4),
            grayPosH = (height * (NumDrop / 4)) + (offset * 4);
        DrawRectangle(Position.x - 5, Position.y - 5, grayPosW, grayPosH, LIGHTGRAY);
    }

private:
    std::vector<Ref<Drop>> Places;
    int NumDrop;
};
