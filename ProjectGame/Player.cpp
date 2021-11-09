#include "Player.hpp"
#include <iostream>

Player::Player() {
	
}

Player::Player(SDL_Renderer *render) {
	renderer = render;

	texturePlayer = objTexture.OutTexture(renderer, "assets/hero.png");

	getKeyboard = SDL_GetKeyboardState(NULL);
	getMouse = SDL_GetMouseState(NULL, NULL);

	axisX = 512;
	axisY = 384;
}

Player::~Player() {
	SDL_DestroyTexture(texturePlayer);
	SDL_DestroyRenderer(renderer);
}

void Player::move() {
	if (getKeyboard[SDL_SCANCODE_W]) {
		axisY--;
	}
	else if (getKeyboard[SDL_SCANCODE_S]) {
		axisY++;
	}
	else if (getKeyboard[SDL_SCANCODE_A]) {
		axisX--;
	}
	else if (getKeyboard[SDL_SCANCODE_D]) {
		axisX++;
	}

	if (axisX == 1025) {
		axisX = 0;
	}
	else if (axisX == -1) {
		axisX = 1024;
	}

	if (axisY == 769) {
		axisY = 0;
	}
	else if (axisY == -1) {
		axisY = 768;
	}
}

bool Player::leftBM(SDL_Event *event) {
	bool isShoot = false;

	if ((event->button.button == SDL_BUTTON_LEFT)) {
        isShoot = true;
	}

	return isShoot;
}

void Player::Draw(int axisX, int axisY, int width, int height) {

	rect.x = axisX;
	rect.y = axisY;
	rect.w = width;
	rect.h = height;

	SDL_RenderCopy(renderer, texturePlayer, NULL, &rect);

}