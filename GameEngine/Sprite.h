#ifndef SPRITE_H
#define SPRITE_H

#include <SDL.h>
#include <string>

class Sprite 
{
public:
	virtual ~Sprite();
	virtual void update(int delta) = 0;
	virtual void render(SDL_Renderer* renderer) = 0;
	const SDL_Rect& getRect();
protected:
	Sprite(int x, int y, int width, int height, SDL_Texture* img);
	SDL_Texture* image;
	SDL_Rect* rectangle;
};

#endif