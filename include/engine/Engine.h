#pragma once

#include <string>
#include <vector>

#include "SDL.h"

#include "GameStates.h"
#include "entities/GameObject.hpp"
#include "EventHandler.h"
#include "entities/Action.h"
struct Engine
{
public:
	Engine(const char* title);
	~Engine();

	int run();

	bool loadAsset(std::string name, std::string path);
	void addGameObject(GameObject* gameObject);

	void update();
	void render();

	void addState(States state);
	void removeState();
private:
	bool m_running;

	SDL_Window* m_window;
	SDL_Renderer* m_renderer;

	EventHandler m_eventHandler;

	States m_currentState;
	std::vector<States> m_states;

	std::vector<GameObject*> m_objects;
};