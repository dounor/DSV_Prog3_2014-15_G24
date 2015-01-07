#include "Action.h"

Action::Action() : health(1) {}
Action::Action(int hp) : health(hp) {}

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
		// Update subactions here
	}
}
void Action::render(SDL_Renderer* renderer)
{
	for (int i = 0; i < subActions.size(); ++i)
	{
		// Render subactions here
	}
}