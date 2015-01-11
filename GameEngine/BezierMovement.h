#ifndef BEZIERMOVEMENT_H
#define BEZIERMOVEMENT_H

#include "SubAction.h"

/* A subAction that moves an enemy along a smooth bezier curve using the entities
 * current position as a start point and moving to the end point through a control
 * point. 
 * The time this takes is
 */
class BezierMovement : public SubAction
{
public:
	BezierMovement(int contX, int contY, int endingX, int endingY, double secondsToEnd);

	void init() override;
	void update(int delta) override;
private:
	int startX, startY, controlX, controlY, endX, endY;
	double bezierTime;
	double secondsToEndPoint;
};

#endif