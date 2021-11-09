#include "Menu.hpp"

Menu::Menu() {

}

Menu::Menu(SDL_Renderer *render) {
	renderer = render;

	tNewGame = bNewGame.OutTexture(renderer, "assets/buttonNewGame.png");
	tQuit = bQuit.OutTexture(renderer, "assets/buttonQuit.png");

	isDownNG = false;
	isDownQ = false;
}

Menu::~Menu() {
	SDL_DestroyTexture(tNewGame);
	SDL_DestroyTexture(tQuit);
}

void Menu::newGameDraw(int axisX, int axisY, int width, int height) {

	rectNewGame.x = axisX;
	rectNewGame.y = axisY;
	rectNewGame.w = width;
	rectNewGame.h = height;

	SDL_RenderCopy(renderer, tNewGame, NULL, &rectNewGame);
}

void Menu::quitDraw(int axisX, int axisY, int width, int height) {

	rectQuit.x = axisX;
	rectQuit.y = axisY;
	rectQuit.w = width;
	rectQuit.h = height;

	SDL_RenderCopy(renderer, tQuit, NULL, &rectQuit);
}

bool Menu::buttonNewGame(SDL_Event *event, int mousX, int mousY) {
	bool compareX = (rectNewGame.x <= mousX) && ((rectNewGame.w + rectNewGame.x) >= mousX);
	bool compareY = (rectNewGame.y <= mousY) && ((rectNewGame.h + rectNewGame.y) >= mousY);

	if ((event->button.button == SDL_BUTTON_LEFT) && (compareX && compareY)) {
		isDownNG = true;
	}

	return isDownNG;
}

bool Menu::buttonQuit(SDL_Event *event, int mousX, int mousY) {
	bool compareX = (rectQuit.x <= mousX) && ((rectQuit.w + rectQuit.x) >= mousX);
	bool compareY = (rectQuit.y <= mousY) && ((rectQuit.h + rectQuit.y) >= mousY);

	if ((event->button.button == SDL_BUTTON_LEFT) && (compareX && compareY)) {
		isDownQ = true;
	}

	return isDownQ;
}