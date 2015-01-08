#include "AngleShot.h"
#include <math.h>

AngleShot::AngleShot(int degreeToFire, int delayBetweenBullets, double speed, 
					 int bltWidth, int bltHeight, SDL_Texture* bltImg, Layer* bltLayer) : delay(delayBetweenBullets), 
																						  bulletWidth(bltWidth), 
																						  bulletHeight(bltHeight), 
																						  bulletImage(bltImg), 
																						  bulletLayer(bltLayer),
																						  currentTime(0),
																						  SubAction()
{
	// Calculate x and y velocity from the angle given
	velX = speed * std::cos(degreeToFire);
	velY = speed * std::sin(degreeToFire);
}
AngleShot::~AngleShot() {}

void AngleShot::render(SDL_Renderer* renderer) { /* Snazzy bullet effects? */}
void AngleShot::update(int delta)
{
	currentTime += delta;

	if (currentTime >= delay) {
		SDL_Rect* entRect = parentAction->getParentEntity()->getRect();
		bulletLayer->addPhysSprite(new PhysicalSprite((entRect->x + entRect->w / 2), (entRect->y + entRect->h), bulletWidth, bulletHeight, bulletImage));
		currentTime = 0;
	}
}