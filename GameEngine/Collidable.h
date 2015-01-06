#ifndef COLLIDABLE_H
#define COLLIDABLE_H

#include <SDL.h>

class Collidable {
public:
	Collidable(int width, int height);
	Collidable(SDL_Rect* rect);

	virtual void onCollision() = 0;
	bool checkCollision(SDL_Rect& otherRect);
	void updateCollisionRect(const SDL_Rect* displayRect);
	~Collidable();
private:
	bool isOwnRect;
	SDL_Rect* collRect;
};

#endif