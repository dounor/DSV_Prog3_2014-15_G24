#include "Engine.h"
#include "Entity.h"
#include "Action.h"
#include "AngleShot.h"
#include "ResourceFactory.h"
#include "BezierMovement.h"
#include <time.h>
#include <random>

int main(int argc, char** argv) 
{
	srand(time(NULL));

	// Initialize engine objects
	Engine* engine = new Engine("Test", 100);

	Layer* playerLayer = new Layer();
	Layer* enemyLayer = new Layer();

	Player* player = new Player(250, 0, 32, 32, 0.3, engine->getResourceFactory()->getImage("spacecraft.png"));

	Entity* ent = new Entity(250, 400, 128, 128, engine->getResourceFactory()->getImage("angry.png"));

	// Generate a mass of movement actions for the "super evil" monster
	for (int i = 0; i < 10000; ++i)
	{
		Action* act = new Action(200);
		BezierMovement* bez = new BezierMovement(std::rand()%640, std::rand()%480, std::rand()%640, std::rand()%480, 1);
		AngleShot* shot = new AngleShot(0, 400, 0.21, 20, 20, engine->getResourceFactory()->getImage("happy.png"), enemyLayer);
		act->addSubAction(bez);
		act->addSubAction(shot);
		ent->addAction(act);
	}

	// Add to playerLayer
	playerLayer->addPhysSprite(player);
	enemyLayer->addPhysSprite(ent);

	playerLayer->addCollisionLayer(enemyLayer);

	// Add to enemyLayer
	
	// Add layers to engine
	engine->addLayer(playerLayer);
	engine->addLayer(enemyLayer);

	// Set the player object
	engine->setPlayer(player);


	engine->runGame();

	delete engine;

	return 0;

	
}