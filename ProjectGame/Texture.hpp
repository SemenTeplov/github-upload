#ifndef TEXTURE
#define TEXTURE

#include "SDL.h"
#include "SDL_image.h"

class Texture {
public:
	SDL_Texture *OutTexture(SDL_Renderer *renderer, const char *image);
};

#endif // TEXTURE
