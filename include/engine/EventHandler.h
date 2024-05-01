#pragma once
#include "SDL.h"
#include "engine/entities/Action.h"
#include "engine/entities/InputState.h"

struct EventHandler
{
public:
	void checkEvents();
	bool isPressed(const Action action);
private:
	void keyDownEvents(const SDL_Keycode key);
	void keyUpEvents(const SDL_Keycode key);
private:
	InputState m_inputState;
};