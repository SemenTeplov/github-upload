#ifndef MENU
#define MENU

#include "Texture.hpp"

class Menu {
public:
	Menu();
	Menu(SDL_Renderer* render);
	~Menu();

	void newGameDraw(int axisX, int axisY, int width, int height);
	void quitDraw(int axisX, int axisY, int width, int height);

	bool buttonNewGame(SDL_Event* event, int mousX, int mousY);
	bool buttonQuit(SDL_Event* event, int mousX, int mousY);

	bool isDownNG;
	bool isDownQ;

private:
	SDL_Renderer *renderer;

	Texture bNewGame, bQuit;
	SDL_Texture *tNewGame, *tQuit;

	SDL_Rect rectNewGame, rectQuit;
};

#endif // MENU
