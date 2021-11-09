#ifndef SHOOT
#define SHOOT

#include "Texture.hpp"

class Shoot {
public:
	Shoot();
	Shoot(SDL_Renderer *render);
	~Shoot();

	int placeX;
	int placeY;

	void Draw(int axisX, int axisY, int width, int height);

private:
	SDL_Renderer *renderer;

	Texture objTexture;
	SDL_Texture *textureBullet;

	SDL_Rect rect;
};

#endif // SHOOT
