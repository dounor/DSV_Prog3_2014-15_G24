#include "PhysicalSprite.h"
#include "Engine.h"

// A sprite that is able to display itself as well as
// collide with other game objects
PhysicalSprite::PhysicalSprite(int x, int y, int width, int height, SDL_Texture* img) : Decal(x, y, width, height, img), velX(0), velY(0), Collidable(rectangle) {}
PhysicalSprite::PhysicalSprite(int x, int y, int width, int height, int colWidth, int colHeight, SDL_Texture* img) : Decal(x, y, width, height, img), velX(0), velY(0), Collidable(colWidth, colHeight) {}

void PhysicalSprite::update(int delta) 
{
	rectangle->x += (velX * delta);
	rectangle->y += (velY * delta);

	updateCollisionRect(*rectangle);

	if (rectangle->x < 0 - rectangle->w - 100)
		dead = true;
	if (rectangle->x > Engine::SCR_WIDTH + 100)
		dead = true;
	if (rectangle->y < 0 - rectangle->h - 100)
		dead = true;
	if (rectangle->y > Engine::SCR_HEIGHT + 100)
		dead = true;

	Decal::update(delta);
}

const double PhysicalSprite::getVelX() { return velX; }
const double PhysicalSprite::getVelY() { return velY; }

void PhysicalSprite::setVelX(const double x) { velX = x; }
void PhysicalSprite::setVelY(const double y) { velY = y; }

bool PhysicalSprite::isDead() { return dead; }

void PhysicalSprite::onCollision() { /*Does nothing (default behaviour)*/ }