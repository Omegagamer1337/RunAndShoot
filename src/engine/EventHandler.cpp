#include "engine/EventHandler.h"

EventHandler* EventHandler::s_pInstance = 0;

bool EventHandler::isPressed(const Action action)
{
	switch (action)
	{
	case Action::QUIT:
		return m_inputState.quit;
	case Action::ATTACK:
		return m_inputState.attack;
	case Action::DOWN:
		return m_inputState.backward;
	case Action::UP:
		return m_inputState.forward;
	case Action::LEFT:
		return m_inputState.left;
	case Action::RIGTH:
		return m_inputState.right;
	case Action::MENU:
		return m_inputState.menu;
	}
}

void EventHandler::checkEvents()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_EVENT_QUIT:
			m_inputState.quit = true;
			return;
		case SDL_EVENT_KEY_DOWN:
		{
			this->keyDownEvents(event.key.keysym.sym);
			break;
		}
		case SDL_EVENT_KEY_UP:
			this->keyUpEvents(event.key.keysym.sym);
			break;
		}
	}
}

void EventHandler::keyDownEvents(const SDL_Keycode key)
{
	switch (key)
	{
	case SDLK_w:
		m_inputState.forward = true;
		break;
	case SDLK_s:
		m_inputState.backward = true;
		break;
	case SDLK_a:
		m_inputState.left = true;
		break;
	case SDLK_d:
		m_inputState.right = true;
		break;
	case SDLK_SPACE:
		m_inputState.attack = true;
		break;
	case SDLK_ESCAPE:
		m_inputState.menu = true;
		break;
	}
}

void EventHandler::keyUpEvents(const SDL_Keycode key)
{
	switch (key)
	{
	case SDLK_w:
		m_inputState.forward = false;
		break;
	case SDLK_s:
		m_inputState.backward = false;
		break;
	case SDLK_a:
		m_inputState.left = false;
		break;
	case SDLK_d:
		m_inputState.right = false;
		break;
	case SDLK_SPACE:
		m_inputState.attack = false;
		break;
	case SDLK_ESCAPE:
		m_inputState.menu = false;
		break;
	}
}