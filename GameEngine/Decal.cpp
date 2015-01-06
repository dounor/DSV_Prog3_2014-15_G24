#include "Decal.h"
#include "Engine.h"

// A simple decal class for displaying an image
Decal::Decal(int x, int y, int width, int height, SDL_Texture* image) : Sprite(x, y, width, height, image) {}

void Decal::render(SDL_Renderer* renderer)
{
	SDL_RenderCopy(renderer, image, NULL, rectangle);
}

void Decal::update(int delta) {}