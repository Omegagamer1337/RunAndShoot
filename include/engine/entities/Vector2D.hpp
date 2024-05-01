#pragma once

struct Vector2D
{
public: 
	float getX() { return m_x; };
	void setX(float x) { m_x = x; }
	float getY() { return m_y; };
	void setY(float y) { m_y = y; }
private:
	float m_x;
	float m_y;
};