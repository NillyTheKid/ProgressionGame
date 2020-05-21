#include "InputManager.h"

InputManager::InputManager()
{
}

InputManager::~InputManager()
{
}

void InputManager::HandleKeyPress(SDL_Keycode keyCode)
{
	HandleInput(_OnPressedFunctions, keyCode);
}

void InputManager::HandleKeyRelease(SDL_Keycode keyCode)
{
	HandleInput(_OnReleasedFunctions, keyCode);
}

void InputManager::RegisterInput(input_callback inputFunction, SDL_Keycode input, bool firedOnRelease)
{
	if (firedOnRelease)
	{
		_OnReleasedFunctions.emplace(input, inputFunction);
	}
	else
	{
		_OnPressedFunctions.emplace(input, inputFunction);
	}
}

void InputManager::HandleInput(const std::multimap<SDL_Keycode, input_callback>& functionMap, SDL_Keycode keyCode)
{
	auto range = functionMap.equal_range(keyCode);

	for (auto it = range.first; it != range.second && it != functionMap.end(); it++)
	{
		(*it).second();
	}
}
