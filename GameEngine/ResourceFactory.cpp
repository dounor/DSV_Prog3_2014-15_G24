#include "ResourceFactory.h"
#include <SDL_image.h>
// A class that deals with the resource management of all files in the game engine
ResourceFactory::ResourceFactory(SDL_Renderer* renderer)
{
	setRenderer(renderer);
}

// Gets an image from a file path and returns a texture of that image
SDL_Texture* ResourceFactory::getImage(std::string filePath)
{
	// Check if we've already retrieved the file before and if that is the
	// case return it directly
	if (images[filePath] != NULL)
		return images[filePath];

	//The texture to create
	SDL_Texture* newTexture = NULL;

	//Load a BMP from the specified path
	SDL_Surface* loadedSurface = IMG_Load(filePath.c_str());
	if (loadedSurface == NULL)
	{
		printf("Couldn't load image %s! SDL_image Error: %s\n", filePath.c_str(), IMG_GetError());
		return NULL;
	}
	else
	{
		//Create texture from surface
		newTexture = SDL_CreateTextureFromSurface(render, loadedSurface);
		if (newTexture == NULL)
		{
			printf("Couldn't create texture from %s! SDL Error: %s\n", filePath.c_str(), SDL_GetError());
			return NULL;
		}

		images[filePath] = newTexture;

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	return newTexture;
}

void ResourceFactory::setRenderer(SDL_Renderer* renderer)
{
	render = renderer;
}

// Remove all objects that the resource factory has created
ResourceFactory::~ResourceFactory()
{
	typedef std::map<std::string, SDL_Texture*> imgMap;

	for (imgMap::iterator it = images.begin(); it != images.end(); ++it) {
		SDL_DestroyTexture(it->second);
	}
	images.clear();
}