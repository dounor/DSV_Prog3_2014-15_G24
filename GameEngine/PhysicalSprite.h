#ifndef COLLISION_SPRITE
#define COLLISION_SPRITE
#include <SDL.h>
#include "Decal.h"
#include "Collidable.h"

class PhysicalSprite : public Decal, public Collidable {
public:
	PhysicalSprite(int x, int y, int width, int height, SDL_Texture* img);
	PhysicalSprite(int x, int y, int width, int height, int colWidth, int colHeight, SDL_Texture* img);

	const double getVelX();
	const double getVelY();

	void setVelX(const double x);
	void setVelY(const double y);

	void update(int delta) override;
	void onCollision() override;
protected:
	double velX;
	double velY;
};


#endif