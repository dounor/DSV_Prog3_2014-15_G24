#include "Player.h"

Player::Player(int x, int y, int width, int height, double spd, SDL_Texture* img) : PhysicalSprite(x, y, width, height, img), leftHeld(false), rightHeld(false), upHeld(false), downHeld(false), speed(spd) {}

void Player::update(int delta)
{
	if (leftHeld)
		velX -= speed;

	if (rightHeld)
		velX += speed;

	if (upHeld)
		velY -= speed;

	if (downHeld)
		velY += speed;

	PhysicalSprite::update(delta);

	velX = 0;
	velY = 0;
}

void Player::handleInput(SDL_Event& evt)
{
	if (evt.type == SDL_KEYDOWN)
	{
		// ... Check all events ...
		switch (evt.key.keysym.sym) {
		case SDLK_LEFT:
			leftHeld = true;
			break;
		case SDLK_RIGHT:
			rightHeld = true;
			break;
		case SDLK_UP:
			upHeld = true;
			break;
		case SDLK_DOWN:
			downHeld = true;
			break;
		default:
			break;
		}
	}
	else if (evt.type == SDL_KEYUP) {
		// ... Check all events ...
		switch (evt.key.keysym.sym) {
		case SDLK_LEFT:
			leftHeld = false;
			break;
		case SDLK_RIGHT:
			rightHeld = false;
			break;
		case SDLK_UP:
			upHeld = false;
			break;
		case SDLK_DOWN:
			downHeld = false;
			break;
		default:
			break;
		}
	}

}

/*
void Player::onDeath()
{

}*/