#ifndef ACTION_H
#define ACTION_H

#include<SDL.h>
#include <vector>
#include "SubAction.h"
#include "Entity.h"

class Action 
{
public:
	Action(Entity* entity);
	Action(Entity* entity, int hp);
	~Action();

	void update(int delta);
	void render(SDL_Renderer* renderer);
	void addSubAction(SubAction* subAction);

	Entity* getParentEntity();
	
protected:
	Entity* parentEntity;
	std::vector<SubAction*> subActions;
	int health;
	double velX;
	double velY;
};

#endif