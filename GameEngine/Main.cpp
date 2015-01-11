#include "Engine.h"
#include "Entity.h"
#include "Action.h"
#include "AngleShot.h"
#include "ResourceFactory.h"
#include "BezierMovement.h"

int main(int argc, char** argv) 
{
	// Initialize engine objects
	Engine* engine = new Engine("Test", 100);

	Layer* playerLayer = new Layer();
	Layer* enemyLayer = new Layer();

	Player* player = new Player(0, 0, 32, 32, 0.3, engine->getResourceFactory()->getImage("C:\\Users\\Dogge\\Desktop\\head.bmp"));

	Entity* ent = new Entity(100, 100, 128, 128, engine->getResourceFactory()->getImage("C:\\Users\\Dogge\\Desktop\\head.bmp"));
	Action* act = new Action(200);
	AngleShot* angle = new AngleShot(90, 300, 0.50, 20, 20, engine->getResourceFactory()->getImage("C:\\Users\\Dogge\\Desktop\\head.bmp"), enemyLayer);

	BezierMovement* bez = new BezierMovement(300, 200, 100, 450, 2);
	

	act->addSubAction(angle);
	act->addSubAction(bez);
	ent->addAction(act);

	// Add to playerLayer
	playerLayer->addPhysSprite(player);
	enemyLayer->addPhysSprite(ent);

	enemyLayer->addCollisionLayer(playerLayer);

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