#include "BezierMovement.h"
#include "Action.h"
#include "Entity.h"

/* A SubAction that moves an entity over a bezier curve and ends the current action when the movement finishes
 */
BezierMovement::BezierMovement(int contX, int contY, int endingX, int endingY, double secondsToEnd) : controlX(contX), controlY(contY), 
																									  endX(endingX), endY(endingY), 
																									  secondsToEndPoint(secondsToEnd), bezierTime(0) {}

// Init the SubAction
void BezierMovement::init()
{
	// Get the current position of the entity and set them as the start values for the curve
	const SDL_Rect& startPos = getParentAction().getParentEntity().getRect();
	startX = startPos.x;
	startY = startPos.y;
}
void BezierMovement::update(int delta)
{
	bezierTime += delta / (1000.0 * secondsToEndPoint);

	double posX = (((1 - bezierTime)*(1 - bezierTime)) * startX) + (2 * bezierTime * (1 - bezierTime) * controlX) + ((bezierTime * bezierTime) * endX);
	double posY = (((1 - bezierTime)*(1 - bezierTime)) * startY) + (2 * bezierTime * (1 - bezierTime) * controlY) + ((bezierTime * bezierTime) * endY);
	getParentAction().getParentEntity().setPos(posX, posY);

	if (bezierTime >= 1)
	{
		getParentAction().setEnded(true);
	}
}