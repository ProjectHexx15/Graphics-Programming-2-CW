#pragma once
#include <iostream>

class Application
{

public:
	Application();
	~Application();
	void Run();

private:
	void Init();
	void Update();
	void Render();
	void Shutdown();
};
