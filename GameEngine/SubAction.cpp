#include "SubAction.h"
#include "Action.h"

SubAction::SubAction() {}
void SubAction::setParentAction(Action* action)
{
	parentAction = action;
}
