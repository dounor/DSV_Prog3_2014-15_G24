#ifndef SUBACTION_H
#define SUBACTION_H

#include <SDL.h>

class SubAction
{
public:
	SubAction(Action* parentAction);
	~SubAction();
	void update(int delta);
	void render(SDL_Renderer* renderer)
};

#endif