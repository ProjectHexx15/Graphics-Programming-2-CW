#include "Application.h"

void Application::Run()
{
	Init();

	while (IsRunning())
	{
		Update();
		Render();
	}
}

void Application::Init()
{
	Window window(800, 600, "Amie's Awesome Coursework Scene!");
}

void Application::Update()
{

}

void Application::Render()
{

}

void Application::Shutdown()
{
	
}

void Application::Input()
{}

void Application::PreDraw()
{}

void Application::Draw()
{}
