#include "Entity.h"
#include "Decal.h"

Entity::Entity(int x, int y, int width, int height, SDL_Texture* img) : PhysicalSprite(x, y, width, height, img) {}

Entity::Entity(int x, int y, int width, int height, int colWidth, int colHeight, SDL_Texture* img) : PhysicalSprite(x, y, width, height, colWidth, colHeight, img) {}
Entity::~Entity()
{
	while (!actionList.empty()) {
		delete actionList.back();
		actionList.pop_back();
	}
}

void Entity::addAction(Action* action) 
{
	action->setParentEntity(this);
	actionList.push_back(action);
}

void Entity::update(int delta)
{
	if (actionList.front()->hasEnded()) {
		delete actionList.front();
		actionList.pop_front();
	}

	actionList.front()->update(delta);
	PhysicalSprite::update(delta);
}
void Entity::render(SDL_Renderer* renderer)
{
	actionList.front()->render(renderer);
	PhysicalSprite::render(renderer);
}

void Entity::onCollision()
{

}