#ifndef WAVESPAWN_H
#define WAVESPAWN_H

#include <vector>

class Entity;
class Layer;
/* WaveSpawn is a spawner of entities that sends all entities
 * defined within the wave to a defined layer to "start" them.
 * The time to spawn is defined as the amount of milliseconds from the
 * start of a level.
 */
class WaveSpawn 
{
public:
	WaveSpawn(int waitTime, Layer& toLayer);
	~WaveSpawn();
	void addEntity(Entity* entity);

	void update(int delta);
private:
	bool sentWave;
	unsigned int waitUntilSpawn;
	unsigned int currentTime;
	Layer& layerToSendWave;
	std::vector<Entity*> waveEnts;
};


#endif