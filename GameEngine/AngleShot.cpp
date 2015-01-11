#include "AngleShot.h"
#include "Entity.h"
#include "SubAction.h"
#include <math.h>

AngleShot::AngleShot(int degreeToFire, int delayBetweenBullets, double speed, 
					 int bltWidth, int bltHeight, SDL_Texture* bltImg, Layer* bltLayer) : delay(delayBetweenBullets), 
																						  bulletWidth(bltWidth), 
																						  bulletHeight(bltHeight), 
																						  bulletImage(bltImg), 
																						  bulletLayer(bltLayer),
																						  currentTime(0)
{
	// Calculate x and y velocity from the angle given
	velX = speed * std::cos(degreeToFire * M_PI / 180.0);
	velY = speed * std::sin(degreeToFire);
}
AngleShot::~AngleShot() {}

void AngleShot::render(SDL_Renderer* renderer) {/* Snazzy bullet effects? */}
void AngleShot::update(int delta)
{
	currentTime += delta;

	if (currentTime >= delay) {
		const SDL_Rect& entRect = getParentAction().getParentEntity().getRect();
		PhysicalSprite* spr = new PhysicalSprite((entRect.x + entRect.w / 2), (entRect.y + entRect.h), bulletWidth, bulletHeight, bulletImage);
		spr->setVelX(velX);
		spr->setVelY(velY);

		bulletLayer->addPhysSprite(spr);
		currentTime = 0;
	}
}