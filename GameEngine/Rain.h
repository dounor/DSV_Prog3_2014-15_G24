#ifndef RAIN_H
#define RAIN_H
#include "SubAction.h"

class Layer;

class Rain : public SubAction {
public:
	Rain(int dela, SDL_Texture* tex, Layer* layer);

	void update(int delta);

private:
	int delay;
	int currentTime;
	SDL_Texture* texture;
	Layer* rainLayer;
};

#endif