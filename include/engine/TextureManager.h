#pragma once

//
//  TextureManager.h
//  SDL Game Programming Book
//
//  Created by shaun mitchell on 31/12/2012.
//  Copyright (c) 2012 shaun mitchell. All rights reserved.
//

#include <iostream>
#include <string>
#include <map>
#include "SDL.h"
#include "stb_image.h"

struct TextureManager
{
public:
	static TextureManager* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new TextureManager();
			return s_pInstance;
		}

		return s_pInstance;
	}

	bool load(std::string fileName, std::string id, SDL_Renderer* renderer);

	void clearTextureMap();
	void clearFromTextureMap(std::string id);

	void draw(std::string id, int x, int y, int width, int height, SDL_Renderer* renderer, SDL_FlipMode flip = SDL_FLIP_NONE);
	void drawFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame, double angle, int alpha, SDL_Renderer* renderer, SDL_FlipMode flip = SDL_FLIP_NONE);
	void drawTile(std::string id, int margin, int spacing, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* renderer);

	std::map<std::string, SDL_Texture*> getTextureMap() { return m_textureMap; }

private:

	TextureManager() = default;

	TextureManager& operator=(const TextureManager&);

	std::map<std::string, SDL_Texture*> m_textureMap;

	static TextureManager* s_pInstance;
};
