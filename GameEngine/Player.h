#ifndef PLAYER_H
#define PLAYER_H
#include "PhysicalSprite.h"

class Player : public PhysicalSprite {
public:
	Player(int x, int y, int width, int height, double spd, SDL_Texture* img);

	void update(int delta) override;
	void handleInput(SDL_Event& evt);
	//virtual void onDeath();
private:
	int lives = 3;
	SDL_Event* evt;

	double speed;

	bool leftHeld;
	bool rightHeld;
	bool upHeld;
	bool downHeld;
};

#endif