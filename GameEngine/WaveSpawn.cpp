#include "WaveSpawn.h"

#include "Layer.h"
#include "Entity.h"

WaveSpawn::WaveSpawn(int waitTime, Layer& toLayer) :waitUntilSpawn(waitTime), layerToSendWave(toLayer), currentTime(0), sentWave(false) {}
WaveSpawn::~WaveSpawn()
{
	// If the wave hasn't been passed onto a layer before destruction...
	if (!sentWave) {
		// ...Destroy all entity objects
		while (!waveEnts.empty())
		{
			delete waveEnts.back();
			waveEnts.pop_back();
		}
	}
}
void WaveSpawn::addEntity(Entity* entity)
{
	waveEnts.push_back(entity);
}

void WaveSpawn::update(int delta)
{
	currentTime += delta;

	if (currentTime >= waitUntilSpawn) {
		for (auto ent : waveEnts) {
			layerToSendWave.addPhysSprite(ent);
		}

		sentWave = true;
	}
}