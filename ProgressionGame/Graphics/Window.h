#pragma once
#include "GraphicIncludes.h"
#include "../Structs/Structs.h"
#include <string>

using namespace std;

class Window
{
public:
	Window();
	~Window();
	Window(const Window& other) = delete;
	Window& operator=(const Window& other) = delete;
	Window(Window&& other) = delete;
	Window& operator=(Window&& other) = delete;

	void Create(string title, Float2 dimensions);
	void Destroy();
	void ClearBackground();

private:
	SDL_Window* _pWindow;
	SDL_GLContext _glContext;
	Float2 _dimensions;
	string _title;
};