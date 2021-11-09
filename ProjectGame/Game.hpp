#ifndef GAME
#define GAME

#include "SDL.h"

#include "Background.hpp"
#include "Player.hpp"
#include "Shoot.hpp"
#include "Enemy.hpp"
#include "Menu.hpp"

class Game {
public:
	Game();
	~Game();

	void run();

private:
	int heightWindow;
	int widthWindow;

	SDL_Window *window;
	SDL_Renderer *renderer;

	SDL_Event *mEvent;

	int pPosX;
	int pPosY;
	int cPosX;
	int cPosY;
};

#endif // GAME
