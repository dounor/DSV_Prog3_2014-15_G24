#ifndef SUBACTION_H
#define SUBACTION_H

#include <SDL.h>

class Action;

class SubAction
{
public:
	virtual ~SubAction() {};
	virtual void update(int delta) = 0;
	virtual void render(SDL_Renderer* renderer) = 0;

	void setParentAction(Action* action);
protected:
	SubAction();
	Action* parentAction; // The action this subaction is connected to
};

#endif