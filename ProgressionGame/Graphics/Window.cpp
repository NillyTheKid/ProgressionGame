#include "Window.h"

Window::Window()
	:_pWindow{nullptr}
{
}

Window::~Window()
{
	if (_pWindow != nullptr)
	{
		SDL_DestroyWindow(_pWindow);
		_pWindow = nullptr;
	}
}

void Window::Create(string title, Float2 dimensions)
{
	_title = title;
	_dimensions = dimensions;
	_pWindow = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, int(dimensions.X), int(dimensions.Y), SDL_WINDOW_OPENGL);
	_glContext = SDL_GL_CreateContext(_pWindow);
}

void Window::Destroy()
{
	SDL_GL_DeleteContext(_glContext);
	SDL_DestroyWindow(_pWindow);
	_pWindow = nullptr;
}

void Window::ClearBackground()
{
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	SDL_GL_SwapWindow(_pWindow);
}
