#ifndef ACTION_H
#define ACTION_H

#include<SDL.h>
#include <vector>
#include "SubAction.h"

class Entity;

class Action 
{
public:
	Action();
	Action(int hp);
	~Action();

	void update(int delta);
	void render(SDL_Renderer* renderer);
	void addSubAction(SubAction* subAction);

	Entity* getParentEntity();
	void setParentEntity(Entity* ent);

	bool hasEnded();
	void setEnded(bool end);

	void onCollision();
	
protected:
	bool ended;
	Entity* parentEntity;
	std::vector<SubAction*> subActions;
	int health;
	double velX;
	double velY;
};

#endif