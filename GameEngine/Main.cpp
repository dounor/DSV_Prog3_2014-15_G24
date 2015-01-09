#include "Engine.h"
#include "Entity.h"
#include "Action.h"
#include "AngleShot.h"
#include "ResourceFactory.h"

int main(int argc, char** argv) 
{
	// Initialize engine objects
	Engine* engine = new Engine("Test", 60);

	Layer* playerLayer = new Layer();

	Player* player = new Player(0, 0, 32, 32, 0.3, engine->getResourceFactory()->getImage("C:\\Users\\Dogge\\Desktop\\head.bmp"));

	Entity* ent = new Entity(100, 100, 128, 128, engine->getResourceFactory()->getImage("C:\\Users\\Dogge\\Desktop\\head.bmp"));
	Action* act = new Action();
	AngleShot* angle = new AngleShot(90, 300, 0.50, 20, 20, engine->getResourceFactory()->getImage("C:\\Users\\Dogge\\Desktop\\head.bmp"), playerLayer);

	act->addSubAction(angle);
	ent->addAction(act);

	// Add to playerLayer
	playerLayer->addPhysSprite(player);
	playerLayer->addPhysSprite(ent);
	// Add layers to engine
	engine->addLayer(playerLayer);

	// Set the player object
	engine->setPlayer(player);


	engine->runGame();

	delete engine;

	return 0;

	
}