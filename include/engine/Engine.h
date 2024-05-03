#pragma once

#include <string>
#include <vector>

#include "SDL.h"

#include "GameStates.h"
#include "entities/GameObject.hpp"
#include "EventHandler.h"
#include "TextureManager.h"
#include "entities/Action.h"
struct Engine
{
public:
	typedef void (*CallbackFunction)(SDL_Renderer*);
	Engine(const char* title, CallbackFunction renderCallback);
	~Engine();

	int run();

	void addGameObject(GameObject* gameObject);

	void update();
	void render();

	void addState(States state);
	void removeState();
	SDL_Renderer* getRenderer();
private:
	bool m_running;

	SDL_Window* m_window;
	SDL_Renderer* m_renderer;

	EventHandler m_eventHandler;

	States m_currentState;
	std::vector<States> m_states;

	std::vector<GameObject*> m_objects;

	CallbackFunction m_renderStaticImages;
};