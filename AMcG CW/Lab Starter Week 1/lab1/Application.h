#pragma once
#include <iostream>
#include "Window.h"


class Application
{

public:
	Application();
	~Application();
	void Run();
	bool IsRunning() const { return _isRunning; }

private:
	void Init();
	void Update();
	void Input();
	void PreDraw();
	void Draw();
	void Render();
	void Shutdown();

	bool _isRunning = true;

};
