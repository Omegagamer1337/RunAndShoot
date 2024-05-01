#include "engine/Engine.h"

Engine::Engine(const char* title)
{
	m_window = SDL_CreateWindow(title, 1920, 1050, 0);
	m_renderer = SDL_CreateRenderer(m_window, title, 0);

	m_currentState = START_SCEEN;
	m_running = true;
}

Engine::~Engine()
{
	SDL_DestroyRenderer(m_renderer);
}

int Engine::run()
{
	while (m_running)
	{
		this->update();
		this->render();
	}
	return 0;
}

bool Engine::loadAsset(std::string name, std::string path)
{
	return false;
}

void Engine::addGameObject(GameObject* gameObject)
{
	m_objects.push_back(gameObject);
}

void Engine::update()
{
	m_eventHandler.checkEvents();
	m_running = !m_eventHandler.isPressed(Action::QUIT);
	for (auto* object : m_objects)
	{
		object->update();
	}
}

void Engine::render()
{
	for (auto* object : m_objects)
	{
		object->render();
	}
}

void Engine::addState(States state)
{
	m_states.push_back(state);
}

void Engine::removeState()
{
	m_states.pop_back();
}
