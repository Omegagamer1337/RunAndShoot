//
//  TextureManager.cpp
//  SDL Game Programming Book
//
//  Created by shaun mitchell on 31/12/2012.
//  Copyright (c) 2012 shaun mitchell. All rights reserved.
// 
// Modified with STB_image instead of SDL_image
//

#define STB_IMAGE_IMPLEMENTATION

#include "engine/TextureManager.h"

TextureManager* TextureManager::s_pInstance = 0;

bool TextureManager::load(std::string fileName, std::string id, SDL_Renderer* renderer)
{
	std::string filePath = std::string("../../../../resources/img/") + fileName;

	int width, height, channels;
	unsigned char* image_data = stbi_load(filePath.c_str(), &width, &height, &channels, STBI_rgb_alpha);
	if (image_data == nullptr)
	{
		std::cerr << "Failed to load image: " << stbi_failure_reason() << std::endl;
		return false;
	}

	SDL_Texture* pTexture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA32, SDL_TEXTUREACCESS_STATIC, width, height);
	if (pTexture == nullptr)
	{
		std::cerr << "Failed to create texture: " << SDL_GetError() << std::endl;
		return false;
	}

	if (!pTexture)
	{
		stbi_image_free(image_data);
		SDL_DestroyTexture(pTexture);
		return false;
	}

	SDL_UpdateTexture(pTexture, nullptr, image_data, width * 4);

	stbi_image_free(image_data);
	m_textureMap[id] = pTexture;
	return true;
}

void TextureManager::draw(std::string id, int x, int y, int width, int height, SDL_Renderer* pRenderer, SDL_FlipMode flip)
{
	SDL_FRect srcRect;
	SDL_FRect destRect;

	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.w = destRect.w = width;
	srcRect.h = destRect.h = height;
	destRect.x = x;
	destRect.y = y;

	SDL_RenderTexture(pRenderer, m_textureMap[id], &srcRect, &destRect);
}

void TextureManager::drawFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame, double angle, int alpha, SDL_Renderer* pRenderer, SDL_FlipMode flip)
{
	SDL_FRect srcRect;
	SDL_FRect destRect;
	srcRect.x = width * currentFrame;
	srcRect.y = height * currentRow;
	srcRect.w = destRect.w = width;
	srcRect.h = destRect.h = height;
	destRect.x = x;
	destRect.y = y;

	SDL_SetTextureAlphaMod(m_textureMap[id], alpha);
	SDL_RenderTextureRotated(pRenderer, m_textureMap[id], &srcRect, &destRect, angle, 0, flip);
}

void TextureManager::drawTile(std::string id, int margin, int spacing, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* pRenderer)
{
	SDL_FRect srcRect;
	SDL_FRect destRect;
	srcRect.x = margin + (spacing + width) * currentFrame;
	srcRect.y = margin + (spacing + height) * currentRow;
	srcRect.w = destRect.w = width;
	srcRect.h = destRect.h = height;
	destRect.x = x;
	destRect.y = y;

	SDL_RenderTextureRotated(pRenderer, m_textureMap[id], &srcRect, &destRect, 0, 0, SDL_FLIP_NONE);
}


void TextureManager::clearTextureMap()
{
	m_textureMap.clear();
}

void TextureManager::clearFromTextureMap(std::string id)
{
	m_textureMap.erase(id);
}
