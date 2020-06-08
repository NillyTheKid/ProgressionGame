#define SDL_MAIN_HANDLED

#include <ctime>
#include <vld.h>

#include <iostream>
#include <string>

#include "../Graphics/Window.h"
#include "../Input/InputManager.h"

using namespace std;

void PrintF1()
{
	cout << "F key was pressed" << endl;
}

void PrintF2()
{
	cout << "F key was released" << endl;
}

void PrintSpace1()
{
	cout << "SPACE BAR was pressed" << endl;
}

void PrintSpace2()
{
	cout << "SPACE BAR was released" << endl;
}

int main()
{
	InputManager inputManager{};

	inputManager.RegisterInput(PrintF1, SDLK_f, false);
	inputManager.RegisterInput(PrintF2, SDLK_f, true);
	inputManager.RegisterInput(PrintSpace1, SDLK_SPACE, false);
	inputManager.RegisterInput(PrintSpace2, SDLK_SPACE, true);

	SDL_Event event;
	bool isRunning = true;
	Window window{};

	window.Create("Progression Game", Float2(1080, 720));

	while (isRunning)
	{
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_KEYDOWN:
			{
				if (!event.key.repeat)
				{
					inputManager.HandleKeyPress(event.key.keysym.sym);
				}
			} break;
			case SDL_KEYUP:
			{
				if (!event.key.repeat)
				{
					inputManager.HandleKeyRelease(event.key.keysym.sym);
				}
			} break;
			case SDL_QUIT:
			{
				isRunning = false;
			} break;
			}
		}

		window.ClearBackground();
	}

	window.Destroy();
}