#include "Rain.h"
#include "PhysicalSprite.h"
#include "Engine.h"
#include "Layer.h"
#include <random>
#include <time.h>
Rain::Rain(int dela, SDL_Texture* tex, Layer* layer) : delay(dela), texture(tex), rainLayer(layer)
{}

void Rain::update(int delta)
{
	
	currentTime += delta;

	if (currentTime >= delay) {
		PhysicalSprite* spr = new PhysicalSprite(rand()%Engine::SCR_WIDTH, -50, 5, 10, texture);
		if (rand() % 2)
			spr->setVelX((double)rand() / RAND_MAX + 0.1);
		else
			spr->setVelX(-(double)rand() / RAND_MAX + 0.1);

		spr->setVelY((double)rand() / RAND_MAX + 0.1);

		rainLayer->addPhysSprite(spr);
		currentTime = 0;
	}
}