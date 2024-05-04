#include "app/entities/Player.h"

Player::Player(const std::string& textureId) : Pawn(textureId)
{
	m_position.setX((1920 - 156) / 2);
	m_position.setY((1080 - 103) / 2);
}

void Player::update()
{
	calculateTargetAngle();
	calculateAngle();
}

void Player::render(SDL_Renderer* pRenderer)
{
	if (m_alive)
	{
		TextureManager::Instance()->drawFrame(m_textureId, m_position.getX(), m_position.getY(), 156, 103, 0, 0, m_currentAngle, 255, pRenderer);
	}
}

void Player::calculateAngle()
{
	const double rotationSpeed = 15.0; // Adjust rotation speed as needed
	double angleDiff = m_targetAngle - m_currentAngle;
	// Ensure angle difference is between -180 and 180 degrees
	if (angleDiff > 180.0)
		angleDiff -= 360.0;
	else if (angleDiff < -180.0)
		angleDiff += 360.0;
	double angleChange = rotationSpeed * std::copysign(1.0, angleDiff);
	if (std::abs(angleChange) > std::abs(angleDiff))
		angleChange = angleDiff;
	m_currentAngle += angleChange;
}

void Player::calculateTargetAngle()
{
	bool up = EventHandler::Instance()->isPressed(Action::UP);
	bool down = EventHandler::Instance()->isPressed(Action::DOWN);
	bool right = EventHandler::Instance()->isPressed(Action::RIGTH);
	bool left = EventHandler::Instance()->isPressed(Action::LEFT);

	if (right)
	{
		m_position.setX(m_position.getX() + 10);
		m_targetAngle = 0.0;
	}

	if (left)
	{
		m_position.setX(m_position.getX() - 10);
		m_targetAngle = 180.0;
	}

	if (up)
	{
		m_position.setY(m_position.getY() - 10);

		if (right)
		{
			m_targetAngle = 315.0;
		}
		else if (left)
		{
			m_targetAngle = 225.0;
		}
		else
		{
			m_targetAngle = 270.0;
		}
	}

	if (down)
	{
		m_position.setY(m_position.getY() + 10);

		if (right)
		{
			m_targetAngle = 45.0;
		}
		else if (left)
		{
			m_targetAngle = 135.0;
		}
		else
		{
			m_targetAngle = 90.0;
		}
	}
	std::cout << m_position.getY() << std::endl;

	if (m_position.getX() >= 1920 - 156)
	{
		m_position.setX(1920 - 156);
	}
	else if (m_position.getX() <= 0)
	{
		m_position.setX(0);
	}

	if (m_position.getY() >= 1080 - 103)
	{
		m_position.setY(1080 - 103);
	}
	else if (m_position.getY() <= 0)
	{
		m_position.setY(0);
	}
}