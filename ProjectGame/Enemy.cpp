#include "Enemy.hpp"
#include <iostream>

Enemy::Enemy() {

}

Enemy::Enemy(SDL_Renderer* render) {
	renderer = render;

	textureEnemy = objTexture.OutTexture(renderer, "assets/enemy.png");

	PlaceX = 10;
	PlaceY = 10;
}

Enemy::~Enemy() {
	SDL_DestroyTexture(textureEnemy);
}

void Enemy::move(int placePlayerX, int placePlayerY) {
	if (PlaceX < placePlayerX) {
		PlaceX++;
	}
	else if (PlaceX > placePlayerX) {
		PlaceX--;
	}

	if (PlaceY < placePlayerY) {
		PlaceY++;
	}
	else if (PlaceY > placePlayerY) {
		PlaceY--;
	}
}

void Enemy::restart(int placePlayerX, int placePlayerY,
	                int placeBulletX, int placeBulletY, bool &menu) {
	bool comparePlayerX = (PlaceX <= placePlayerX) && ((PlaceX + 64) >= placePlayerX);
	bool comparePlayerY = (PlaceY <= placePlayerY) && ((PlaceY + 64) >= placePlayerY);
	bool compareBulletX = (PlaceX <= placeBulletX) && ((PlaceX + 64) >= placeBulletX);
	bool compareBulletY = (PlaceY <= placeBulletY) && ((PlaceY + 64) >= placeBulletY);

	if (compareBulletX && compareBulletY) {
		PlaceX = 10;
		PlaceY = 10;
	}

	if (comparePlayerX && comparePlayerY) {
		menu = false;
	}
}

void Enemy::Draw(int axisX, int axisY, int width, int height) {

	rect.x = axisX;
	rect.y = axisY;
	rect.w = width;
	rect.h = height;

	SDL_RenderCopy(renderer, textureEnemy, NULL, &rect);

}