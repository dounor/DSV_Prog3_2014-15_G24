#ifndef LAYER_H
#define LAYER_H

#include <list>
#include <vector>

#include "PhysicalSprite.h"

class Layer
{
public:
	Layer();
	Layer(Layer* colLayer);
	~Layer();

	void addCollisionLayer(Layer* layer);
	void addPhysSprite(PhysicalSprite* sprite);
	bool collidesWithLayer(PhysicalSprite& sprite);
	void update(int delta);
	void render(SDL_Renderer* renderer);
private:
	std::list<PhysicalSprite*> physSprites; // Objekten som finns i lagret
	std::vector<Layer*> collisionLayers; // De lager som våra objekt kommer kollidera med

};

#endif