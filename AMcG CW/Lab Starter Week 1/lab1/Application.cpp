#include "Application.h"

#include "Window.h"
#include "Scene.h"

Application::Application()
{
}

Application::~Application()
{
	Shutdown();
}


void Application::Init()
{
	_window = std::make_unique<Window>(1280, 720, "Amie's Coursework Scene");

	_scene = new Scene();
	_scene->Init();

	_isRunning = true;
}

void Application::Run()
{
	Init();

	while (_isRunning)
	{
		Input();
		Update();
		Render();
	}

	Shutdown();
}

void Application::Input()
{
	_window->PollEvents();

	_scene->ProcessMouseMotion(_window->GetMouseDeltaX(), _window->GetMouseDeltaY());

	_scene->ProcessMouseWheel(_window->GetMouseWheel());

	if (_window->ShouldClose())
	{
		_isRunning = false;
	}
}

void Application::Update()
{
	_scene->Update(_deltaTime);
}

void Application::Render()
{
	_scene->Render();
	_window->SwapBuffers();
}


void Application::Shutdown()
{
	_isRunning = false;

	delete _scene;
	_scene = nullptr;

	_window.reset();
}

Window* Application::GetWindow() const
{
	return _window.get();
}

bool Application::IsRunning() const
{
	return _isRunning;
}

void Application::Stop()
{
	_isRunning = false;
}


