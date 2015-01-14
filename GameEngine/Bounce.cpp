#include "Bounce.h"
#include "Action.h"
#include "Entity.h"
#include "Engine.h"

// A simple action that bounces an entity over the screen
void Bounce::init()
{
	getParentAction().getParentEntity().setVelX(0.12);
	getParentAction().getParentEntity().setVelY(0.12);
}

void Bounce::update(int delta)
{
	Entity& ent = getParentAction().getParentEntity();
	const SDL_Rect& entPos = ent.getRect();

	// Reverse the direction if a wall is hit.
	if (entPos.x + entPos.w >= Engine::SCR_WIDTH || entPos.x <= 0)
		ent.setVelX(-ent.getVelX());

	if (entPos.y + entPos.h >= Engine::SCR_HEIGHT || entPos.y <= 0)
		ent.setVelY(-ent.getVelY());


}