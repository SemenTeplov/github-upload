#ifndef BACKGROUND
#define BACKGROUND

#include "Texture.hpp"

class Background {
public:
	Background();
	Background(SDL_Renderer* render);
	~Background();

	void drawBackg(int axisX, int axisY, int width, int height);

private:
	SDL_Renderer *renderer;
	Texture texture;
	SDL_Texture *textureGrass;

	SDL_Rect source;
};

#endif // BACKGROUND
