#pragma once

#include "Vector2D.hpp"
#include <string>
#include "SDL.h"

struct GameObject
{
public:
    GameObject(const std::string& textureId) : m_textureId(textureId) {};
	virtual void update() = 0;
	virtual void render(SDL_Renderer* pRenderer) = 0;

    const std::string& getTextureId() const {
        return m_textureId;
    }

    void setTextureId(const std::string& textureId) {
        m_textureId = textureId;
    }

protected:
    std::string m_textureId;
};