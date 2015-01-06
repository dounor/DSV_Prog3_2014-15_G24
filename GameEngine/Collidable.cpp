#include "Collidable.h"

// A simple class that handles all collision between objects that 
// is extended by this class
Collidable::Collidable(int width, int height) : isOwnRect(true) {
	collRect = new SDL_Rect();
	collRect->x = 0;
	collRect->y = 0;
	collRect->w = width;
	collRect->h = height;
}
Collidable::Collidable(SDL_Rect* rect) : isOwnRect(false) {
	collRect = rect;
}

// We could use SDL_HasIntersection to do our collision
// check, but we've decided to create a simple one ourselves
bool Collidable::checkCollision(SDL_Rect& otherRect) 
{
	// Check if any of our rect sides is outside of the other rect
	// If any of them are then we are not intersecting the other rect
	if ((collRect->y + collRect->h) <= otherRect.y)
		return false;

	if (collRect->y >= (otherRect.y + otherRect.h))
		return false;

	if ((collRect->x + collRect->w) <= otherRect.x)
		return false;

	if (collRect->x >= (otherRect.x + otherRect.w))
		return false;

	return true;
}

void Collidable::updateCollisionRect(const SDL_Rect* displayRect)
{
	if (isOwnRect == false) {
		int dispCenterX = displayRect->x + (displayRect->w / 2);
		int dispCenterY = displayRect->y + (displayRect->h / 2);

		collRect->x = dispCenterX - (collRect->w / 2);
		collRect->y = dispCenterY - (collRect->h / 2);
	}
}

// We only want to delete the collisionRectangle if this collidable
// class has created it, otherwise let the class that owns the
// rectangle handle the deletion
Collidable::~Collidable() 
{
	if (isOwnRect)
		delete collRect;
}