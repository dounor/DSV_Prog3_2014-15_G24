#include "SubAction.h"
#include "Action.h"

SubAction::SubAction() {}
void SubAction::setParentAction(Action* action)
{
	parentAction = action;
}

Action& SubAction::getParentAction()
{
	return *parentAction;
}
