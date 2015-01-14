#include "Action.h"

// How much damage a shot does
const int DAMAGE_PER_SHOT = 50;

Action::Action() : ended(false), health(1) {}
Action::Action(int hp) : ended(false), health(hp) {}

Action::~Action()
{
	while (!subActions.empty()) {
		delete subActions.back();
		subActions.pop_back();
	}
}

// Initiate all subActions connected to this action
void Action::init()
{
	for (unsigned int i = 0; i < subActions.size(); ++i) {
		subActions[i]->init();
	}
}

// Update all subActions connected to this action
void Action::update(int delta)
{
	for (unsigned int i = 0; i < subActions.size(); ++i) {
		subActions[i]->update(delta);
	}
}

// Render all subActions connected to this action
void Action::render(SDL_Renderer* renderer)
{
	for (unsigned int i = 0; i < subActions.size(); ++i) {
		subActions[i]->render(renderer);
	}
}

// Add a subAction to this action
void Action::addSubAction(SubAction* subAction)
{
	// Set this Action to be the parent of the added subAction
	subAction->setParentAction(this);
	subActions.push_back(subAction);
}

Entity& Action::getParentEntity()
{
	return *parentEntity;
}

void Action::setParentEntity(Entity* ent)
{
	parentEntity = ent;
}

// Check if this action has finished
bool Action::hasEnded()
{
	return ended;
}

void Action::setEnded(bool end)
{
	ended = end;
}

void Action::onCollision()
{
	health -= DAMAGE_PER_SHOT;

	if (health <= 0) {
		ended = true;
	}
}