#pragma once
#include "SDL.h"
#include "engine/entities/Action.h"
#include "engine/entities/InputState.h"

struct EventHandler
{
public:
	static EventHandler* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new EventHandler();
			return s_pInstance;
		}

		return s_pInstance;
	};
	void checkEvents();
	bool isPressed(const Action action);
private:
	void keyDownEvents(const SDL_Keycode key);
	void keyUpEvents(const SDL_Keycode key);
private:
	EventHandler() = default;
	InputState m_inputState;

	EventHandler(const EventHandler&);
	EventHandler& operator=(const EventHandler&);

	static EventHandler* s_pInstance;
};