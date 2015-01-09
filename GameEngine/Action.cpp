#include "Action.h"

Action::Action() : ended(false) {}

Action::~Action()
{
	while (!subActions.empty()) {
		delete subActions.back();
		subActions.pop_back();
	}
}

void Action::update(int delta)
{
	for (unsigned int i = 0; i < subActions.size(); ++i) {
		subActions[i]->update(delta);
	}
}
void Action::render(SDL_Renderer* renderer)
{
	for (unsigned int i = 0; i < subActions.size(); ++i) {
		subActions[i]->render(renderer);
	}
}

void Action::addSubAction(SubAction* subAction)
{
	subAction->setParentAction(this);
	subActions.push_back(subAction);
	// Add a sub action to the list and send this action as the parent action!
}

Entity* Action::getParentEntity()
{
	return parentEntity;
}

void Action::setParentEntity(Entity* ent)
{
	parentEntity = ent;
}

bool Action::hasEnded()
{
	return ended;
}

void Action::setEnded(bool end)
{
	ended = end;
}