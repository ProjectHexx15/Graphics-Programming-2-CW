#include "Window.h"

#include <iostream>

// manages the creation the SDL window and OpenGL context

Window::Window(int width, int height, const std::string& title) : _window(nullptr), _context(nullptr), _width(width), _height(height), _shouldClose(false)
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cerr << "Window could not be created: " << SDL_GetError() << std::endl;
		return;
	}

	SetAttributes();

	_window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL);

	if (!_window)
	{
		std::cerr << "Window could not be created: " << SDL_GetError() << std::endl;
		SDL_Quit();
		return;
	}

	CreateContext();
	InitGlew();

	glViewport(0, 0, width, height);
	glEnable(GL_DEPTH_TEST);
}

Window::~Window()
{
	SDL_GL_DeleteContext(_context);

	if (_window)
	{
		SDL_DestroyWindow(_window);
	}

	SDL_Quit();
}

void Window::SetAttributes()
{
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 5);

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
}

void Window::CreateContext()
{
	_context = SDL_GL_CreateContext(_window);

	if (!_context)
	{
		std::cerr << "Failed to creaste OpenGL context: " << SDL_GetError() << std::endl;
	}

}


void Window::InitGlew()
{
	if (glewInit() != GLEW_OK)
	{
		std::cerr << "Failed to initialize GLEW" << std::endl;
	}
}


void Window::PollEvents()
{
	SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			_shouldClose = true;
			break;

		case SDL_KEYDOWN:
			if (event.key.keysym.sym == SDLK_ESCAPE)
			{
				_shouldClose = true;
			}
			break;

		case SDL_MOUSEMOTION:
			_mouseDeltaX = event.motion.xrel;
			_mouseDeltaY = event.motion.yrel;
			break;

		case SDL_MOUSEWHEEL:
		{
			_mouseWheel = event.wheel.y;
			break;
		}

		}
	}
}

void Window::SwapBuffers()
{
	SDL_GL_SwapWindow(_window);
}

bool Window::ShouldClose()
{
	return _shouldClose;
}

SDL_Window* Window::GetWindow() const
{
	return _window;
}

SDL_GLContext Window::GetContext() const
{
	return _context;
}

int Window::GetWidth() const
{
	return _width;
}

int Window::GetHeight() const
{
	return _height;
}

int Window::GetMouseDeltaX() 
{
	int value = _mouseDeltaX;
	_mouseDeltaX = 0;
	return value;

}

int Window::GetMouseDeltaY() 
{
	int value = _mouseDeltaY;
	_mouseDeltaY = 0;
	return value;
}

int Window::GetMouseWheel()
{
	int value = _mouseWheel;
	_mouseWheel = 0;

	return value;
}
