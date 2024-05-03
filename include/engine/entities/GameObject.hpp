#pragma once

#include "Vector2D.hpp"
#include <string>

struct GameObject
{
public:
	virtual void update() = 0;
	virtual void render() = 0;

    bool isAlive() const {
        return m_alive;
    }

    void setAlive(bool alive) {
        m_alive = alive;
    }

    float getAcceleration() const {
        return m_acceleration;
    }

    void setAcceleration(float acceleration) {
        m_acceleration = acceleration;
    }

    float getSpeed() const {
        return m_speed;
    }

    void setSpeed(float speed) {
        this->m_speed = speed;
    }

    const std::string& getTextureId() const {
        return m_textureId;
    }

    void setTextureId(const std::string& textureId) {
        m_textureId = textureId;
    }

    const Vector2D& getDirection() const {
        return m_direction;
    }

    void setDirection(const Vector2D& direction) {
        m_direction = direction;
    }

    const Vector2D& getPosition() const {
        return m_position;
    }

    void setPosition(const Vector2D& position) {
        m_position = position;
    }

protected:
	bool m_alive;
	float m_acceleration;
	float m_speed;
    std::string m_textureId;
	Vector2D m_direction;
	Vector2D m_position;
};