#ifndef RESOURCEFACTORY_H
#define RESOURCEFACTORY_H

#include <SDL.h>
#include <map>

class ResourceFactory
{
public:
	ResourceFactory(SDL_Renderer* renderer);
	~ResourceFactory();
	void setRenderer(SDL_Renderer* renderer);
	SDL_Texture* getImage(std::string filePath);
private:
	std::map<std::string, SDL_Texture*> images;
	SDL_Renderer* render;
};

#endif