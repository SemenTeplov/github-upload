#include "Game.hpp"

Game::Game() {
	heightWindow = 768;
	widthWindow = 1024;

	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow("Project", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
		                      widthWindow, heightWindow, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	mEvent = new SDL_Event();

	pPosX == NULL;
	pPosY == NULL;
}

Game::~Game() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	delete mEvent;
}

void Game::run() {
	Background backgrond(renderer);
	Shoot bullet(renderer);
	Enemy enemy(renderer);
	Player player(renderer);
	Menu menu(renderer);

	while ((mEvent->type != SDL_QUIT) && (menu.buttonQuit(mEvent, cPosX, cPosY) == false)) {
		SDL_Delay(1000 / 120);
		SDL_PollEvent(mEvent);
		SDL_RenderClear(renderer);

		if (menu.buttonNewGame(mEvent, cPosX, cPosY)) {
			backgrond.drawBackg(0, 0, widthWindow, heightWindow);
			player.Draw(player.axisX, player.axisY, 64, 64);
			enemy.Draw(enemy.PlaceX, enemy.PlaceY, 64, 64);

			enemy.move(player.axisX, player.axisY);
			enemy.restart(player.axisX, player.axisY,
				          bullet.placeX, bullet.placeY, menu.isDownNG);
			player.move();

			if (player.leftBM(mEvent)) {
				pPosX = player.axisX;
				pPosY = player.axisY;

				SDL_GetMouseState(&cPosX, &cPosY);
			}

			if ((pPosX != NULL) && (pPosY != NULL)) {
				bullet.Draw(pPosX, pPosY, 16, 16);

				if (pPosX < cPosX) {
					pPosX++;
				}
				else if (pPosX > cPosX) {
					pPosX--;
				}
				if (pPosY < cPosY) {
					pPosY++;
				}
				else if (pPosY > cPosY) {
					pPosY--;
				}
			}

			if ((pPosX == cPosX) && (pPosY == cPosY)) {
				pPosX = NULL;
				pPosY = NULL;
			}
		}
		else {
			SDL_GetMouseState(&cPosX, &cPosY);

			menu.newGameDraw(400, 250, 200, 80);
			menu.quitDraw(400, 400, 200, 80);
		}

		SDL_RenderPresent(renderer);
	}
}