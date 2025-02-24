#include "Casino.h"
#include "MenuScene.h"
#include "Hand.h"
#include "raygui.h"
#include "raylib.h"

Casino::Casino(){

}

Casino::~Casino(){

}

void Casino::FromDeck(Ref<Deck>& deck){
    Cards.clear();
      printf("fromDeck\n");
    for(auto& card : deck->GetCards()){
      Cards.push_back(card);
    }
}
void Casino::Swap(size_t a, size_t b){
    Ref<Card> t = Cards[a];
	Cards[a] = Cards[b];
	Cards[b] = t;
}
void Casino::Shuffle(size_t factor){
    size_t count = Cards.size() * factor;

	for (size_t i = 0; i < count; i++)
	{
		size_t a = (size_t)GetRandomValue(0, (int)Cards.size() - 1);
		size_t b = (size_t)GetRandomValue(0, (int)Cards.size() - 1);

		Swap(a, b);
	}
}

void Casino::DrawCards(Ref<Hand>& player, Ref<Hand>& table){

    Vector2 pos = player->GetPlaces()[0]->GetPosition();
    Cards[0]->SetPosition(pos);
    pos = player->GetPlaces()[1]->GetPosition();
    Cards[1]->SetPosition(pos);
    pos = player->GetPlaces()[2]->GetPosition();
    Cards[2]->SetPosition(pos);
    pos = player->GetPlaces()[3]->GetPosition();
    Cards[3]->SetPosition(pos);

    // pos = table->GetPlaces()[0]->GetPosition();
    // Cards[4]->SetPosition(pos);
    // pos = table->GetPlaces()[1]->GetPosition();
    // Cards[5]->SetPosition(pos);
    // pos = table->GetPlaces()[2]->GetPosition();
    // Cards[6]->SetPosition(pos);
    // pos = table->GetPlaces()[3]->GetPosition();
    // Cards[7]->SetPosition(pos);
}

void Casino::Start(){
  printf("Casino start\n");
  mMenuClicked = false;
  Vector2 pos = { 100, 100};
  mDeck = ResourcesManager::CreateObject<Deck>(RandomU64());
  mHand = ResourcesManager::CreateObject<Hand>(RandomU64());
  Table = ResourcesManager::CreateObject<Hand>(RandomU64());
  pos = { ((float)GetScreenWidth() / 2) - 70 , (float)GetScreenHeight() - 45};
  mHand->SetPosition(pos);

  pos = { ((float)GetScreenWidth() / 2) - 70 , ((float)GetScreenHeight() / 2) - 90};
  Table->SetPosition(pos);
  FromDeck(mDeck);
  printf("done create object\n");
  Shuffle();

  pos = mHand->GetPlaces()[0]->GetPosition();
  Cards.front()->SetPosition(pos);
  printf("Casino start end\n");
}

Ref<Scene> Casino::Update(){
    Scene::Update();
    DrawCards(mHand, Table);

    if(mMenuClicked){
      return ResourcesManager::loadScene<Menu>("Menu");
    }
    return nullptr;
}

void Casino::Draw(){
    Scene::Draw();
    ClearBackground(DARKGREEN);
    if (GuiButton(Rectangle{(float)(GetScreenWidth() - 30),30,30,30}, GuiIconText(ICON_FILE_SAVE_CLASSIC, ""))) { mMenuClicked = true; }
}
