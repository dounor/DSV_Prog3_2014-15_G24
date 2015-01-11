#include "BezierMovement.h"
#include "Action.h"
#include "Entity.h"

BezierMovement::BezierMovement(int contX, int contY, int endingX, int endingY, double secondsToEnd) : controlX(contX), controlY(contY), 
																									  endX(endingX), endY(endingY), 
																									  secondsToEndPoint(secondsToEnd), bezierTime(0) {}

void BezierMovement::init()
{
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