#include "Shoot.hpp"

Shoot::Shoot() {

}

Shoot::Shoot(SDL_Renderer *render) {
    renderer = render;

	textureBullet = objTexture.OutTexture(renderer, "assets/shoot.png");

	placeX = 0;
	placeY = 0;
}

Shoot::~Shoot() {
	SDL_DestroyTexture(textureBullet);
}

void Shoot::Draw(int axisX, int axisY, int width, int height) {

	placeX = axisX;
	placeY = axisY;
	
	rect.x = axisX;
	rect.y = axisY;
	rect.w = width;
	rect.h = height;

	SDL_RenderCopy(renderer, textureBullet, NULL, &rect);
	
}

