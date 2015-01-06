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

}

void Layer::addCollisionLayer(Layer* colLayer)
{
	collisionLayers.push_back(colLayer);
}

// Uppdatera samtliga objekt i lagret
void Layer::update(int delta) 
{

}

// Rita samtliga objekt i lagret
void Layer::render(SDL_Renderer* renderer)
{

}