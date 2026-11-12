#include "Window.h"

Window::Window(int width, int height, const std::string& title)
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cerr << "SDL could not initialize video subsystem: " << SDL_GetError() << std::endl;
		return;
	}

	_window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL);

	if (!_window)
	{
		std::cerr << "Window could not be created: " << SDL_GetError() << std::endl;
		SDL_Quit();
		return;
	}
}

Window::~Window()
{
	SDL_DestroyWindow(_window);
	SDL_GL_DeleteContext(_context);
	SDL_Quit();
}

void Window::Init()
{
	SetAttributes();
	CreateContext();
	InitGlew();
}

void Window::SetAttributes()
{
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 5);

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
}

void Window::InitGlew()
{
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
	{
		std::cerr << "Failed to initialize GLEW" << std::endl;
	}
}

void Window::PollEvents()
{



}

void Window::SwapBuffers()
{

}

bool Window::ShouldClose()
{
	return false;
}
