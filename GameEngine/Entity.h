#ifndef ENTITY_H
#define ENTITY_H

#include "PhysicalSprite.h"
#include "Action.h"
#include <vector>
/*
 * An entity is a physical sprite that gets its behaviour from actions.
 * Those actions could be anything from simple movement to more complex patterns.
 */
class Entity : public PhysicalSprite {
public:
	Entity(int x, int y, int width, int height, SDL_Texture* img);
	Entity(int x, int y, int width, int height, int colWidth, int colHeight, SDL_Texture* img);
	~Entity();

	void addAction(Action* action);

	void update(int delta) override;
	void render(SDL_Renderer* render) override;

	void onCollision() override;

protected:
	std::vector<Action*> actionList;
};


#endif