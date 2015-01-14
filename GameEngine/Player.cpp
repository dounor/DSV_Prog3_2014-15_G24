#include "Player.h"
#include "Engine.h"

// A player is a physical sprite that the player can interact with using the keyboard
Player::Player(int x, int y, int width, int height, double spd, SDL_Texture* img) : score(0), invisible(false), PhysicalSprite(x, y, width, height, img), leftHeld(false), rightHeld(false), upHeld(false), downHeld(false), speed(spd) 
{
	fnt = TTF_OpenFont("tuffy.ttf", 22); // Load a font into fnt

	defaultColor = { 255, 255, 255 }; // White is the default color
	scoreRectangle.x = 150;
	scoreRectangle.y = 330;
	scoreRectangle.w = 300;
	scoreRectangle.h = 200;
}

Player::~Player()
{
	TTF_CloseFont(fnt);
}

void Player::update(int delta)
{
	// Update score
	if (invisible != true)
		score += delta;

	// Check all movement bools and set the velocity to the
	// direction held
	if (leftHeld)
		velX -= speed;

	if (rightHeld)
		velX += speed;

	if (upHeld)
		velY -= speed;

	if (downHeld)
		velY += speed;

	PhysicalSprite::update(delta);

	// Make the player stay within the game window
	if (rectangle->x < 0)
		rectangle->x = 0;
	if (rectangle->x > Engine::SCR_WIDTH - rectangle->w)
		rectangle->x = Engine::SCR_WIDTH - rectangle->w;
	if (rectangle->y < 0)
		rectangle->y = 0;
	if (rectangle->y > Engine::SCR_HEIGHT - rectangle->w)
		rectangle->y = Engine::SCR_HEIGHT - rectangle->w;

	// Reset the velocity after each loop, we don't want the player to continue moving
	// forever without interaction from the user
	velX = 0;
	velY = 0;
}

void Player::handleInput(SDL_Event& evt)
{
	// Check what button has been held down and react to that information
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

void Player::render(SDL_Renderer* renderer)
{
	// Set the score display
	SDL_Surface* scoreMsg = TTF_RenderText_Solid(fnt, ("Score: " + std::to_string(score)).c_str(), defaultColor);
	SDL_Texture* texScoreMsg = SDL_CreateTextureFromSurface(renderer, scoreMsg);

	SDL_FreeSurface(scoreMsg);
	SDL_RenderCopy(renderer, texScoreMsg, NULL, &scoreRectangle);
	SDL_DestroyTexture(texScoreMsg);

	if (invisible != true)
		Decal::render(renderer);
}

void Player::onCollision()
{
	// If the player is hit, make him invisible
	invisible = true;
}