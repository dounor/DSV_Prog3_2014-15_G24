#ifndef ENGINE_H
#define ENGINE_H

#include <SDL.h>
#include <string>
#include <vector>
#include "ResourceFactory.h"
#include "Player.h"
#include "Layer.h"

class Engine
{
public:
	Engine(std::string gameName, int updatesPerSec);
	~Engine();
	void runGame();

	void addLayer(Layer* layer);

	void setPlayer(Player* ply);

	ResourceFactory* getResourceFactory();

	unsigned long getCurrentMillis();

	static const int SCR_WIDTH;
	static const int SCR_HEIGHT;

private:
	bool running = true;
	int delta = 0;
	double updateInterval;
	SDL_Renderer* render;
	SDL_Window* window; 
	std::vector<Layer*> layers;
	ResourceFactory* resourceFactory;
	Player* player;
};


#endif