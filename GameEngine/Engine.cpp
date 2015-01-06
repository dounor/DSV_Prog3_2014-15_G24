#include "Engine.h"
#include "EnemyController.h"
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

	render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);

	//Verify that the game renderer was correctly created, if not throw an error and exit the application
	if (render == NULL)
	{
		std::cout << "Renderer to game window could not be created! " << SDL_GetError();
		SDL_DestroyWindow(window);
		SDL_Quit();
		exit(1);
	}

	// Create a new Resource Factory
	resourceFactory = new ResourceFactory(render);

	// Set the current delta time to 0
	delta = 0;
}

void Engine::runGame()
{
	
	// Create an event object
	SDL_Event evt;

	// Create the player object
	Player* player = new Player(0, 0, 32, 32, 0.3, resourceFactory->getImage("C:\\Users\\Douglas\\Desktop\\head.bmp"));

	// Create the enemy controller
	EnemyController* enemyController = new EnemyController(SCR_WIDTH, SCR_HEIGHT, 0.4, 2);

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
			player->update(delta);
			enemyController->update(delta, resourceFactory);

			// TODO: Might change this to 0 instead (we'll see...)
			delta = 0;
		}


		// ... Render ...
		SDL_RenderClear(render);

		//Render all game objects here
		player->render(render);
		enemyController->render(render);

		SDL_RenderPresent(render);

		// Subtract current time with the time it was at the beginning of this function cycle
		delta += getCurrentMillis() - curCycleTime;
	}

	delete player;
	delete enemyController;
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
	delete resourceFactory;
	SDL_DestroyRenderer(render);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

// Return how many milliseconds that has elapsed since epoch
unsigned long Engine::getCurrentMillis() {
	return std::chrono::duration_cast<std::chrono::milliseconds>
		(std::chrono::system_clock::now().time_since_epoch()).count();
}