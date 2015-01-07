#ifndef ACTION_H
#define ACTION_H

#include<SDL.h>
#include <vector>

class Action 
{
public:
	Action();
	Action(int hp);
	~Action();

	void update(int delta);
	void render(SDL_Renderer* renderer);

private:
	std::vector<SubAction*> subActions;
	int health;

};

#endif