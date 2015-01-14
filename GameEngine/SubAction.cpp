#include "SubAction.h"
#include "Action.h"

/* A SubAction is some functionality that is used by an Action.
 * Subactions can for example draw something on the screen, update some state
 * on either its own instance variables or the instance variables of the action
 * connected to it or the entity that is connected to the action that is, in turn,
 * connected to a SubAction instance
 */
SubAction::SubAction() {}
void SubAction::setParentAction(Action* action)
{
	parentAction = action;
}

Action& SubAction::getParentAction()
{
	return *parentAction;
}
