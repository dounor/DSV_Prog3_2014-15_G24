#ifndef ANGLESHOT_H
#define ANGLESHOT_H
#include "SubAction.h"
#include "Layer.h"
#include <SDL.h>
#include <vector>

class AngleShot : public SubAction
{
public:
	AngleShot(int degreeToFire, int delayBetweenBullets, double speed, int bltWidth, int bltHeight, SDL_Texture* bltImg, Layer* bltLayer);
	~AngleShot() override;

	void render(SDL_Renderer* renderer) override;
	void update(int delta) override;

private:
	Layer* bulletLayer;
	SDL_Texture* bulletImage;
	double velX;
	double velY;
	int bulletWidth;
	int bulletHeight;
	int currentTime;
	int delay;
};

#endif