#ifndef ENTITY_H
#define ENTITY_H

#include "PhysicalSprite.h"
#include "Action.h"
#include <queue>
/*
 * An entity is a physical sprite that gets its behaviour from actions.
 * Those actions could be anything from simple movement to more complex patterns.
 */
class Entity : public PhysicalSprite 
{
public:
	Entity(int x, int y, int width, int height, SDL_Texture* img);
	Entity(int x, int y, int width, int height, int colWidth, int colHeight, SDL_Texture* img);
	~Entity();

	void addAction(Action* action);

	void update(int delta) override;
	void render(SDL_Renderer* renderer) override;

	void onCollision() override;

	void setPos(int x, int y);

protected:
	bool currentActionStarted;
	std::queue<Action*> actionList;
};


#endif