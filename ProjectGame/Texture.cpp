#include "Texture.hpp"

SDL_Texture *Texture::OutTexture(SDL_Renderer *renderer, const char *image) {
	SDL_Surface *surface = IMG_Load(image);
	SDL_Texture *InTexture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);

	return InTexture;
}