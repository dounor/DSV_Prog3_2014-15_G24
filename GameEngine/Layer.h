#ifndef LAYER_H
#define LAYER_H

#include <vector>
#include "PhysicalSprite.h"

class Layer
{
public:
	Layer();
	Layer(Layer* colLayer);
	~Layer();

	void addCollisionLayer(Layer* layer);
	void update(int delta);
	void render(SDL_Renderer* renderer);
private:
	std::vector<PhysicalSprite*> physSprites; // Objekten som finns i lagret
	std::vector<Layer*> collisionLayers; // De lager som v�ra objekt kommer kollidera med

};

#endif