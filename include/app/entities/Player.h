#pragma once
#include "engine/entities/Pawn.h"
#include "engine/TextureManager.h"
#include "engine/EventHandler.h"
#include "engine/entities/Action.h"

class Player : public Pawn
{
public: 
	Player(const std::string& textureId);
	~Player() = default;

	void update() override;
	void render(SDL_Renderer* pRenderer) override;
private:
	void calculateAngle();
	void calculateTargetAngle();
private:
	double m_targetAngle = 0.0;
	double m_currentAngle = 0.0;
};
