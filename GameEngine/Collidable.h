#ifndef COLLIDABLE_H
#define COLLIDABLE_H

#include <SDL.h>

class Collidable 
{
public:
	Collidable(int width, int height);
	Collidable(SDL_Rect* rect);

	virtual void onCollision() = 0;
	bool checkCollision(const SDL_Rect& otherRect);
	SDL_Rect* getCollisionRectangle();
	void updateCollisionRect(const SDL_Rect* displayRect);
	~Collidable();
private:
	bool isOwnRect;
	SDL_Rect* collRect;
};

#endif