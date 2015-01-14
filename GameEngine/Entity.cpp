#include "Entity.h"
#include "Decal.h"

/* A entity is a game object with a list of actions
 * and subactions that the game object performs.
 */
Entity::Entity(int x, int y, int width, int height, SDL_Texture* img) : PhysicalSprite(x, y, width, height, img), currentActionStarted(false){}

// If you want to specify a separate collision box for the entity
Entity::Entity(int x, int y, int width, int height, int colWidth, int colHeight, SDL_Texture* img) : PhysicalSprite(x, y, width, height, colWidth, colHeight, img) {}
Entity::~Entity()
{
	while (!actionList.empty()) {
		delete actionList.front();
		actionList.pop();
	}
}

// Add an action to this entity
void Entity::addAction(Action* action) 
{
	action->setParentEntity(this);
	actionList.push(action);
}

void Entity::update(int delta)
{
	// If an action has ended, delete that action and continue with the next one.
	if (actionList.empty() != true) {
		if (actionList.front()->hasEnded()) {
			delete actionList.front();
			actionList.pop();
			currentActionStarted = false;
		}
	}
	// If no action is left in this entity it is dead
	if (actionList.empty()) {
		dead = true;
	} else {
		// Initiate the next action in the list if it has not been started
		if (!currentActionStarted)
			if (!actionList.empty()) {
				actionList.front()->init();
				currentActionStarted = true;
			}

		// update the action
		actionList.front()->update(delta);
	}
		

	PhysicalSprite::update(delta);
}

void Entity::render(SDL_Renderer* renderer)
{
	// Render the current action
	if (!actionList.empty())
		actionList.front()->render(renderer);
	
	// Render the sprite of the entity
	PhysicalSprite::render(renderer);
}

void Entity::setPos(int x, int y)
{
	rectangle->x = x;
	rectangle->y = y;
}

void Entity::onCollision()
{
	// Pass the message on to the current action
	if (!actionList.empty() )
		actionList.front()->onCollision();
}