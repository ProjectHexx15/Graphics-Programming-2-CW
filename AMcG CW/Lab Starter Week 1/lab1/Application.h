#pragma once

#include <memory>

class Window;
class Scene;


class Application
{

private:
	std::unique_ptr<Window> _window;
	Scene* _scene =  nullptr;

	bool _isRunning;

	float _deltaTime = 0.0f;


public:
	Application();
	~Application();


	void Init();
	void Run();
	void Shutdown();

	void Input();
	void Update();
	void Render();

	Window* GetWindow() const;

	bool IsRunning() const;
	void Stop();
};
