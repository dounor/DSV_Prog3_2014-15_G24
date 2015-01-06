#ifndef ENGINE_H
#define ENGINE_H

#include <SDL.h>
#include <string>
#include "ResourceFactory.h"
#include "Player.h"

class Engine
{
public:
	Engine(std::string gameName, int updatesPerSec);
	~Engine();
	void runGame();
	unsigned long getCurrentMillis();

	static const int SCR_WIDTH;
	static const int SCR_HEIGHT;

private:
	bool running = true;
	int delta = 0;
	double updateInterval;
	SDL_Renderer* render;
	SDL_Window* window; 
	ResourceFactory* resourceFactory;
};


#endif