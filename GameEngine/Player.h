#ifndef PLAYER_H
#define PLAYER_H

#include "PhysicalSprite.h"
#include <SDL_ttf.h>

class Player : public PhysicalSprite 
{
public:
	Player(int x, int y, int width, int height, double spd, SDL_Texture* img);
	~Player();
	void update(int delta) override;
	void render(SDL_Renderer* renderer) override;
	void handleInput(SDL_Event& evt);
	void onCollision() override;
private:
	unsigned int score;
	bool invisible;
	SDL_Event* evt;

	double speed;

	bool leftHeld;
	bool rightHeld;
	bool upHeld;
	bool downHeld;

	TTF_Font* fnt;
	SDL_Color defaultColor;
	SDL_Rect scoreRectangle;
};

#endif