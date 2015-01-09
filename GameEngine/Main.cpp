#include "Engine.h"
#include "ResourceFactory.h"
int main(int argc, char** argv) 
{
	Engine* engine = new Engine("Test", 60);

	Layer* playerLayer = new Layer();

	Player* player = new Player(0, 0, 32, 32, 0.3, engine->getResourceFactory()->getImage("C:\\Users\\Douglas\\Desktop\\head.bmp"));

	playerLayer->addPhysSprite(player);
	
	engine->addLayer(playerLayer);
	engine->setPlayer(player);


	engine->runGame();
	
	delete player;
	delete engine;

	return 0;

	
}