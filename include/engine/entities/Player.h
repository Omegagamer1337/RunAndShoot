#include "GameObject.hpp"

class Player : public GameObject
{
public: 
	Player() = default;
	~Player() = default;

	void update();
	void render();
};