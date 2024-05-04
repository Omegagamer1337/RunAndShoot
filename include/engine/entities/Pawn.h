#pragma once

#include "GameObject.hpp"
#include "engine/TextureManager.h"

class Pawn : public GameObject
{
public:
	Pawn(const std::string& textureId);

	virtual void update() = 0;
	virtual void render(SDL_Renderer* pRenderer) = 0;

	bool isAlive() const;

	void setAlive(bool alive);

	float getAcceleration() const;

	void setAcceleration(float acceleration);

	float getSpeed() const;

	void setSpeed(float speed);

	const Vector2D& getDirection() const;

	void setDirection(const Vector2D& direction);

	const Vector2D& getPosition() const;

	void setPosition(const Vector2D& position);

protected:
	bool m_alive;
	float m_acceleration;
	float m_speed;

	Vector2D m_direction;
	Vector2D m_position;

};