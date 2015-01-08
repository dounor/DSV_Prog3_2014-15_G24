#include "Layer.h"

Layer::Layer() 
{

}

Layer::Layer(Layer* colLayer)
{
	addCollisionLayer(colLayer);
}

// Ta bort alla sprites som ligger i vårt lager
Layer::~Layer() 
{
	// Remove the layers
	while (!collisionLayers.empty()) {
		delete collisionLayers.back();
		collisionLayers.pop_back();
	}

	// Delete all sprites associated with this layer
	while (!physSprites.empty())
	{
		delete physSprites.back();
		physSprites.pop_back();
	}
}

void Layer::addPhysSprite(PhysicalSprite* sprite)
{
	physSprites.push_back(sprite);
}

void Layer::addCollisionLayer(Layer* colLayer)
{
	collisionLayers.push_back(colLayer);
}

bool Layer::collidesWithLayer(PhysicalSprite* sprite) 
{
	for (int i = 0; i < physSprites.size(); ++i) {
		if (SDL_HasIntersection(sprite->getRect(), /*Layer() or some such (sorry)*/ ))
			return true;
		}
	return false;
}

// Uppdatera samtliga objekt i lagret
void Layer::update(int delta) 
{

}

// Rita samtliga objekt i lagret
void Layer::render(SDL_Renderer* renderer)
{
}