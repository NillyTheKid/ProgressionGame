#pragma comment(lib, "SDL2.lib")
#pragma comment(lib, "SDL2main.lib")
#pragma comment (lib,"opengl32.lib")
#pragma comment (lib,"Glu32.lib")
#pragma comment(lib, "SDL2_image.lib")  

#define SDL_MAIN_HANDLED
#include <windows.h>

#include <SDL.h>
#include <gl/GL.h>
#include <ctime>
#include <vld.h>

#include <iostream>
#include <string>

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

	SDL_Window* window = SDL_CreateWindow("Test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);

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
	}

	SDL_DestroyWindow(window);
}