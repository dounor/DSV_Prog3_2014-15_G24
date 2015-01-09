#include "Engine.h"
#include <iostream>
#include <chrono>

const int Engine::SCR_WIDTH = 640;
const int Engine::SCR_HEIGHT = 480;

Engine::Engine(std::string gameName, int updatesPerSec) : updateInterval(1000.0 / updatesPerSec)
{
	// Try to initialize SDL, if not possible throw an error and exit the application
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		std::cerr << "Error initializing SDL! " << SDL_GetError();
		exit(1);
	}
	window = SDL_CreateWindow(gameName.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCR_WIDTH, SCR_HEIGHT, SDL_WINDOW_SHOWN);

	//Verify that the game window was correctly created, if not throw an error and exit the application
	if (window == NULL) {
		std::cout << "Game window could not be created! " << SDL_GetError();
		SDL_Quit();
		exit(1);
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);

	//Verify that the game renderer was correctly created, if not throw an error and exit the application
	if (renderer == NULL)
	{
		std::cout << "Renderer to game window could not be created! " << SDL_GetError();
		SDL_DestroyWindow(window);
		SDL_Quit();
		exit(1);
	}

	// Create a new Resource Factory
	resourceFactory = new ResourceFactory(renderer);

	// Set the current delta time to 0
	delta = 0;
}

void Engine::addLayer(Layer* layer)
{
	layers.push_back(layer);
}

void Engine::setPlayer(Player* ply)
{
	player = ply;
}

ResourceFactory* Engine::getResourceFactory()
{
	return resourceFactory;
}

void Engine::runGame()
{
	
	// Create an event object
	SDL_Event evt;

	while (running)
	{
		// Get the current time in millis
		unsigned long curCycleTime = getCurrentMillis();

		// ... Update ...
		while (delta >= updateInterval)
		{
			// ... Check all events ...
			while (SDL_PollEvent(&evt) != 0)
			{
				if (evt.type == SDL_QUIT) {
					running = false;
				}
				else if (evt.type == SDL_KEYDOWN || evt.type == SDL_KEYUP) {
					player->handleInput(evt);
				}
			}

			// ... Update all game objects here ...
			for (auto it : layers)
				it->update(delta);

			// TODO: Might change this to 0 instead (we'll see...)
			delta = 0;
		}


		// ... Render ...
		SDL_RenderClear(renderer);

		//Render all game objects here
		for (auto it : layers)
			it->render(renderer);

		SDL_RenderPresent(renderer);

		// Subtract current time with the time it was at the beginning of this function cycle
		delta += getCurrentMillis() - curCycleTime;
	}
}

/*
// Check if a collision has occured between two Physical Sprites
bool Engine::checkCollision(PhysicalSprite* firstSprite, PhysicalSprite* secondSprite)
{
	if (SDL_HasIntersection(firstSprite->getRect(), secondSprite->getRect()))
		return true;

	return false;
}*/

// Destroy the Game Engine
Engine::~Engine()
{
	while (!layers.empty()) {
		delete layers.back();
		layers.pop_back();
	}

	delete resourceFactory;
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

// Return how many milliseconds that has elapsed since epoch
unsigned long Engine::getCurrentMillis() {
	return std::chrono::duration_cast<std::chrono::milliseconds>
		(std::chrono::system_clock::now().time_since_epoch()).count();
}