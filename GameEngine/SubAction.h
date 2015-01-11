#ifndef SUBACTION_H
#define SUBACTION_H

#include <SDL.h>

class Action;

class SubAction
{
public:
	virtual ~SubAction() {};
	virtual void init() {};
	virtual void update(int delta) = 0;
	virtual void render(SDL_Renderer* renderer) {};
	void setParentAction(Action* action);

	Action& getParentAction();
protected:
	SubAction();

private:
	Action* parentAction; // The action this subaction is connected to
};

#endif