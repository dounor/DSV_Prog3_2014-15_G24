#include "EnemyController.h"
#include "Engine.h"
#include <random>

// A simple controller that throws a lot of "enemies" at the player
EnemyController::EnemyController(int width, int height, double enemySpd, int enemyInt) : boundsWidth(width),
																						 boundsHeight(height),
																						 enemySpeed(enemySpd), 
																						 enemyInterval(enemyInt),
																						 currentTime(0) {}
void EnemyController::update(int delta, ResourceFactory* factory) 
{
	currentTime += delta;

	if (currentTime >= enemyInterval) {
		PhysicalSprite* enemy = new PhysicalSprite(rand() % boundsWidth, 0, 64, 64, factory->getImage("C:\\Users\\Douglas\\Desktop\\slowpoke.bmp"));
		enemy->setVelY(enemySpeed);
		enemies.push_back(enemy);

		currentTime = 0;
	}

	int toRemove = -1;

	for (int i = 0; i < enemies.size(); ++i) {
		PhysicalSprite* enemy = enemies[i];
		enemy->update(delta);
		// Check if the object is still within bounds
		if (enemy->getRect()->x < 0 - enemy->getRect()->w)
			toRemove = i;
		if (enemy->getRect()->x > Engine::SCR_WIDTH)
			toRemove = i;
		if (enemy->getRect()->y < 0 - enemy->getRect()->h)
			toRemove = i;
		if (enemy->getRect()->y > Engine::SCR_HEIGHT)
			toRemove = i;
	}

	if (toRemove != -1)
		enemies.erase(enemies.begin() + toRemove);
}
void EnemyController::render(SDL_Renderer* renderer)
{
	for (int i = 0; i < enemies.size(); ++i) {
		enemies[i]->render(renderer);
	}
}

EnemyController::~EnemyController() 
{
	enemies.clear();
}


std::vector<PhysicalSprite>* enemies;
	int boundsWidth;
	int boundsHeight;
	double enemySpeed;
	int enemyInterval;