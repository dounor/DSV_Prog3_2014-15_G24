#include "Engine.h"
#include "Entity.h"
#include "Action.h"
#include "AngleShot.h"
#include "ResourceFactory.h"
#include "BezierMovement.h"
#include "Bounce.h"
#include "Rain.h"
#include <time.h>
#include <random>

int main(int argc, char** argv) 
{
	srand(time(NULL));

	// Initialize engine objects
	Engine* engine = new Engine("Test", 100);

	Layer* playerLayer = new Layer();
	Layer* enemyLayer = new Layer();
	Layer* rainLayer = new Layer();

	Player* player = new Player(250, 0, 32, 32, 0.3, engine->getResourceFactory()->getImage("spacecraft.png"));

	Entity* ent = new Entity(250, 400, 128, 128, engine->getResourceFactory()->getImage("angry.png"));

	Entity* secondEnt = new Entity(50, 50, 50, 50, engine->getResourceFactory()->getImage("angry.png"));

	Entity* thirdEnt = new Entity(350, 250, 30, 30, engine->getResourceFactory()->getImage("angry.png"));

	Entity* rainEffect = new Entity(-50, -50, 2, 2, engine->getResourceFactory()->getImage("happy.png"));

	// Generate a mass of movement actions for the moving monster
	for (int i = 0; i < 10000; ++i)
	{
		Action* act = new Action(200);
		BezierMovement* bez = new BezierMovement(std::rand()%640, std::rand()%480, std::rand()%640, std::rand()%480, 1);
		act->addSubAction(bez);
		ent->addAction(act);
	}

	Action* bounceAction = new Action(200);
	Bounce* bounce = new Bounce();

	bounceAction->addSubAction(bounce);

	secondEnt->addAction(bounceAction);

	Action* secondBounceAction = new Action(200);
	Bounce* secondBounce = new Bounce();

	secondBounceAction->addSubAction(secondBounce);

	thirdEnt->addAction(secondBounceAction);

	Action* rainAction = new Action(200);
	Rain* rain = new Rain(20, engine->getResourceFactory()->getImage("rain.png"), rainLayer);

	rainAction->addSubAction(rain);

	rainEffect->addAction(rainAction);

	// Add to playerLayer
	playerLayer->addPhysSprite(player);
	
	rainLayer->addPhysSprite(rainEffect);

	enemyLayer->addPhysSprite(ent);
	enemyLayer->addPhysSprite(secondEnt);
	enemyLayer->addPhysSprite(thirdEnt);

	playerLayer->addCollisionLayer(enemyLayer);

	// Add to enemyLayer
	
	// Add layers to engine
	engine->addLayer(playerLayer);
	engine->addLayer(enemyLayer);
	engine->addLayer(rainLayer);

	// Set the player object
	engine->setPlayer(player);


	engine->runGame();

	delete engine;

	return 0;

	
}