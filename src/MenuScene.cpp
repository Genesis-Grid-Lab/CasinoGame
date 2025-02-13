#include "MenuScene.h"

#include "raygui.h"
#include "Casino.h"

#define TITLE_FONT_SIZE 160
#define TITLE_FONT_SPACING 10.0f
#define MENU_FONT_SIZE 40

#define BUTTON_WIDTH 280
#define BUTTON_HEIGHT 70
#define BUTTON_SPACING (BUTTON_HEIGHT + 10)

Menu::Menu() { Clicked = false; printf("Menu start\n");}

Menu::~Menu() {}

void Menu::Start() {}

Ref<Scene> Menu::Update(){
  Scene::Update();

  if(Clicked){
    printf("Debug resume\n");
    Clicked = false;
    return ResourcesManager<Casino>::loadScene("Casino");
  }
  return nullptr;
}

void Menu::Draw(){
  Scene::Draw();
  ClearBackground(BLACK);
  int sceneWidth = GetScreenWidth();
	int sceneHeight = GetScreenHeight();

	const char *title = "Menu";
	Font titleFont = GetFontDefault();
	Vector2 titleDim = MeasureTextEx(titleFont, title, TITLE_FONT_SIZE, TITLE_FONT_SPACING);

	int titleLeft = (sceneWidth - (int)titleDim.x) / 2;
	int titleTop = sceneHeight / 4 - (int)titleDim.y / 2;
	Vector2 titlePos{(float)titleLeft, (float)titleTop};
	::DrawTextEx(titleFont, title, titlePos, TITLE_FONT_SIZE, TITLE_FONT_SPACING, RED);

	int menuLeft = (sceneWidth - BUTTON_WIDTH) / 2;
	int menuTop = sceneHeight / 2;
	float currX = (float)menuLeft;
	float currY = (float)menuTop;

	GuiSetStyle(BUTTON, TEXT_ALIGNMENT, TEXT_ALIGN_CENTER);
	GuiSetStyle(DEFAULT, TEXT_SIZE, MENU_FONT_SIZE);
      
	if (GuiButton(Rectangle{ currX, currY, BUTTON_WIDTH, BUTTON_HEIGHT }, "Resume")) {
		Clicked = true;
	}
	currY += BUTTON_SPACING;
	if (GuiButton(Rectangle{ currX, currY, BUTTON_WIDTH, BUTTON_HEIGHT }, "Quit")) {
	  
	}
}
