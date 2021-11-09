#ifndef PLAYER
#define PLAYER

#include "SDL.h"

#include "Shoot.hpp"

class Player {
public:
	Player();
	Player(SDL_Renderer* render);
	~Player();

	int axisX;
	int axisY;

	void move();
	bool leftBM(SDL_Event *event);
	void Draw(int axisX, int axisY, int width, int height);

private:
	SDL_Renderer* renderer;

	Texture objTexture;
	SDL_Texture* texturePlayer;

	SDL_Rect rect;

	const Uint8 *getKeyboard;
	Uint32 getMouse;

	Shoot bullet;
};

#endif // PLAYER
