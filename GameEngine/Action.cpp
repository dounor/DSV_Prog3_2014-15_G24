#include "Action.h"

Action::Action(Entity* entity) : parentEntity(entity), health(1) {}
Action::Action(Entity* entity, int hp) : parentEntity(entity), health(hp) {}

Action::~Action()
{
	while (!subActions.empty()) {
		delete subActions.back();
		subActions.pop_back();
	}
}

void Action::update(int delta)
{
	for (int i = 0; i < subActions.size(); ++i)
	{
		subActions[i]->update(delta);
	}
}
void Action::render(SDL_Renderer* renderer)
{
	for (int i = 0; i < subActions.size(); ++i)
	{
		subActions[i]->render(renderer);
	}
}

void Action::addSubAction(SubAction* subAction)
{
	// Add a sub action to the list and send this action as the parent action!
}

Entity* getParentEntity()
{
	return parentEntity;
}