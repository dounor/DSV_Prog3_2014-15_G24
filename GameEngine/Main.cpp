#include "Engine.h"
#include "ResourceFactory.h"
int main(int argc, char** argv) {
	Engine* engine = new Engine("Test", 60);

	engine->runGame();
	
	delete engine;

	return 0;

	
}//Test comment commit