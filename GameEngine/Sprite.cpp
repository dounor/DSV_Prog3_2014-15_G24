#include "Sprite.h"

/* A simple sprite that has a texture and a rectangle describing it's size and position
 */
Sprite::Sprite(int x, int y, int width, int height, SDL_Texture* img) : image(img)
{
	rectangle = new SDL_Rect();

	rectangle->x = x;
	rectangle->y = y;
	rectangle->w = width;
	rectangle->h = height;
}

const SDL_Rect& Sprite::getRect()
{
	return *rectangle;
}

Sprite::~Sprite()
{
	delete rectangle;
}