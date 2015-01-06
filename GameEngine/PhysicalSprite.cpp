#include "PhysicalSprite.h"
// A sprite that is able to display itself as well as
// collide with other game objects
PhysicalSprite::PhysicalSprite(int x, int y, int width, int height, SDL_Texture* img) : Decal(x, y, width, height, img), velX(0), velY(0), Collidable(rectangle) {}
PhysicalSprite::PhysicalSprite(int x, int y, int width, int height, int colWidth, int colHeight, SDL_Texture* img) : Decal(x, y, width, height, img), velX(0), velY(0), Collidable(colWidth, colHeight) {}

void PhysicalSprite::update(int delta) {
	rectangle->x += (velX * delta);
	rectangle->y += (velY * delta);

	updateCollisionRect(rectangle);

	Decal::update(delta);
}

const double PhysicalSprite::getVelX() { return velX; }
const double PhysicalSprite::getVelY() { return velY; }

void PhysicalSprite::setVelX(const double x) { velX = x; }
void PhysicalSprite::setVelY(const double y) { velY = y; }

void PhysicalSprite::onCollision() { /*Does nothing (default behaviour)*/ }