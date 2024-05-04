#pragma once
#include "engine/TextureManager.h"
#include "app/entities/Player.h"
#include <vector>

namespace GameInit
{
	static void loadTextures(SDL_Renderer* pRenderer)
	{
		if (!TextureManager::Instance()->load("background.png", "backgroundGame", pRenderer))
		{
			std::cerr << "Background not loaded" << std::endl;
		}
		
		if (!TextureManager::Instance()->load("player.png", "player", pRenderer))
		{
			std::cerr << "Player not loaded" << std::endl;
		}
		
	}

	static std::vector<Pawn*> getGameObjects()
	{
		std::vector<Pawn*> objects = std::vector<Pawn*>();
		objects.push_back(new Player("player"));
		return objects;
	}

	static void drawStaticImages(SDL_Renderer* pRenderer)
	{
		TextureManager::Instance()->draw("backgroundGame", 0, 0, 1920, 1080, pRenderer);
	}
};