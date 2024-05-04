#include "engine/Engine.h"

Engine::Engine(const char* title, CallbackFunction renderCallback)
{
	m_window = SDL_CreateWindow(title, 1920, 1050, 0);
	m_renderer = SDL_CreateRenderer(m_window, NULL, 0);

	m_renderStaticImages = renderCallback;

	m_currentState = START_SCEEN;
	m_running = true;
}

Engine::~Engine()
{
	SDL_DestroyRenderer(m_renderer);
}

int Engine::run()
{
	float startFrame, endFrame;

	while (m_running)
	{
		startFrame = SDL_GetTicks();
		EventHandler::Instance()->checkEvents();
		this->update();
		this->render();
		endFrame = SDL_GetTicks();
		float elapsedMS = (endFrame - startFrame) / 1000.0f;
		SDL_Delay(floor(16.666f - elapsedMS));
	}
	return 0;
}

void Engine::addGameObject(std::vector<Pawn*> gameObjects)
{
	for (auto* object : gameObjects)
	{
		m_objects.push_back(object);
	}
}

void Engine::update()
{
	m_running = !EventHandler::Instance()->isPressed(Action::QUIT);

	m_objects.erase(
		std::remove_if(
			m_objects.begin(), 
			m_objects.end(),
			[](const auto* object) { return !object->isAlive(); }
		),
		m_objects.end()
	);

	for (auto* object : m_objects)
	{
		object->update();
	}

}

void Engine::render()
{
	SDL_RenderClear(m_renderer);
	m_renderStaticImages(m_renderer);

	for (auto* object : m_objects)
	{
		object->render(m_renderer);
	}
	SDL_RenderPresent(m_renderer);
}

void Engine::addState(States state)
{
	m_states.push_back(state);
}

void Engine::removeState()
{
	m_states.pop_back();
}

SDL_Renderer* Engine::getRenderer()
{
	return m_renderer;
}