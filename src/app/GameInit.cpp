#pragma once
#include "engine/TextureManager.h"

namespace GameInit
{
	static void loadTextures(SDL_Renderer* pRenderer)
	{
		if (!TextureManager::Instance()->load("background.png", "backgroundGame", pRenderer))
		{
			std::cerr << "Background not loaded" << std::endl;
		}
	}

	static void drawStaticImages(SDL_Renderer* pRenderer)
	{
		TextureManager::Instance()->draw("backgroundGame", 0, 0, 1920, 1080, pRenderer);
	}
};