#ifndef DECAL_H
#define DECAL_H
#include <SDL.h>
#include "Sprite.h"
class Decal : public Sprite {
public:
	Decal(int x, int y, int width, int height, SDL_Texture* image);
	void render(SDL_Renderer* renderer) override;
	void update(int delta) override;
};

#endif