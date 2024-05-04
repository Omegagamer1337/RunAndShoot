#pragma once

#include <string>
#include <vector>

#include "SDL.h"

#include "GameStates.h"
#include "entities/Pawn.h"
#include "TextureManager.h"
#include "EventHandler.h"
#include "entities/Action.h"

struct Engine
{
public:
	typedef void (*CallbackFunction)(SDL_Renderer*);
	Engine(const char* title, CallbackFunction renderCallback);
	~Engine();

	int run();

	void addGameObject(std::vector<Pawn*> gameObjects);

	void update();
	void render();

	void addState(States state);
	void removeState();
	SDL_Renderer* getRenderer();
private:
	bool m_running;

	SDL_Window* m_window;
	SDL_Renderer* m_renderer;

	States m_currentState;
	std::vector<States> m_states;

	std::vector<Pawn*> m_objects;

	CallbackFunction m_renderStaticImages;
};