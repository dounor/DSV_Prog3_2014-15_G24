#ifndef ENEMYCONTROLLER_H
#define ENEMYCONTROLLER_H
#include <SDL.h>
#include <vector>
#include "ResourceFactory.h"
#include "PhysicalSprite.h"
class EnemyController {
public:
	EnemyController(int width, int height, double enemySpd, int enemyInt);
	~EnemyController();
	void update(int delta, ResourceFactory* factory);
	void render(SDL_Renderer* renderer);
private:
	std::vector<PhysicalSprite*> enemies;
	int boundsWidth;
	int boundsHeight;
	double enemySpeed;
	int enemyInterval;
	int currentTime;
};

#endif