#include "engine/entities/Pawn.h"

Pawn::Pawn(const std::string& textureId): GameObject(textureId), m_alive(true), m_acceleration(0), m_speed(0)
{
    m_direction = Vector2D();
    m_position = Vector2D();
}

bool Pawn::isAlive() const {
    return m_alive;
}

void Pawn::setAlive(bool alive) {
    m_alive = alive;
}

float Pawn::getAcceleration() const {
    return m_acceleration;
}

void Pawn::setAcceleration(float acceleration) {
    m_acceleration = acceleration;
}

float Pawn::getSpeed() const {
    return m_speed;
}

void Pawn::setSpeed(float speed) {
    this->m_speed = speed;
}

const Vector2D& Pawn::getDirection() const {
    return m_direction;
}

void Pawn::setDirection(const Vector2D& direction) {
    m_direction = direction;
}

const Vector2D& Pawn::getPosition() const {
    return m_position;
}

void Pawn::setPosition(const Vector2D& position) {
    m_position = position;
}