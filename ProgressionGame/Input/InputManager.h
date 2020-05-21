#pragma once
#include <map>
#include <SDL.h>

typedef void (*input_callback)();

class InputManager
{
public:
	InputManager();
	~InputManager();

	InputManager(const InputManager& other) = delete;
	InputManager& operator=(const InputManager& other) = delete;
	InputManager(InputManager&& other) = delete;
	InputManager& operator=(InputManager&& other) = delete;


	void HandleKeyPress(SDL_Keycode keyCode);
	void HandleKeyRelease(SDL_Keycode keyCode);

	void RegisterInput(input_callback inputFunction, SDL_Keycode input, bool firedOnRelease);

private:

	void HandleInput(const std::multimap<SDL_Keycode, input_callback>& functionMap, SDL_Keycode keyCode);

	std::multimap<SDL_Keycode, input_callback> _OnPressedFunctions;
	std::multimap<SDL_Keycode, input_callback> _OnReleasedFunctions;
};