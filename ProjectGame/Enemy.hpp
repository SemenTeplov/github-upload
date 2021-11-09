#ifndef ENEMY
#define ENEMY

#include "Texture.hpp"
#include "Player.hpp"

class Enemy {
public:
	Enemy();
	Enemy(SDL_Renderer *render);
	~Enemy();

	int PlaceX;
	int PlaceY;

	void move(int placePlayerX, int placePlayerY);
	void restart(int placePlayerX, int placePlayerY, 
		         int placeBulletX, int placeBulletY, bool &menu);
	void Draw(int axisX, int axisY, int width, int height);

private:
	SDL_Renderer *renderer;

	Texture objTexture;
	SDL_Texture *textureEnemy;

	SDL_Rect rect;

};

#endif // ENEMY
