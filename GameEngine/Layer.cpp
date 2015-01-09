#include "Layer.h"

Layer::Layer() {}

Layer::Layer(Layer* colLayer)
{
	addCollisionLayer(colLayer);
}

// Remove all sprites that is contained within this layer
Layer::~Layer() 
{
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
	for (auto it = physSprites.begin(); it != physSprites.end();)
	{
		if ((*it)->checkCollision(sprite->getRect()))
			return true;
	}
	return false;
}

// Uppdatera samtliga objekt i lagret
void Layer::update(int delta) 
{
	for (auto it = physSprites.begin(); it != physSprites.end();)
	{
		// Check if the current sprite is dead and no longer part of the game
		if ((*it)->isDead()) {
			delete (*it);
			it = physSprites.erase(it);
		}
		else {
			// Check if the current sprite collides with any of the collidable sprites that it should collide with
			for (auto layer : collisionLayers) {
				if (layer->collidesWithLayer((*it)))
					(*it)->onCollision();
			}

			(*it)->update(delta);
			++it;
		}
	}
}

// Rita samtliga objekt i lagret
void Layer::render(SDL_Renderer* renderer)
{
	for (auto it = physSprites.begin(); it != physSprites.end(); ++it)
	{
		(*it)->render(renderer);
	}
}