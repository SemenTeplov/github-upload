#include "Background.hpp"

Background::Background() {

}

Background::Background(SDL_Renderer *render) {
	renderer = render;

	textureGrass = texture.OutTexture(renderer, "assets/grass.png");
}

Background::~Background() {
	SDL_DestroyTexture(textureGrass);
	SDL_DestroyRenderer(renderer);
}

void Background::drawBackg(int axisX, int axisY, int width, int height) {
	source.x = 0;
	source.y = 0;
	source.h = height;
	source.w = width;

	SDL_RenderCopy(renderer, textureGrass, NULL, &source);
}