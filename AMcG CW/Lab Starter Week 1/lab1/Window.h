#pragma once
#include <SDL/SDL.h>
#include <GL/glew.h>
#include <iostream>
#include <string>

class Window
{
public:
    Window(int width, int height, const std::string& title);
    ~Window();

    void PollEvents();
	void Init();
	void SetAttributes();
	void CreateContext();
	void InitGlew();
    void SwapBuffers();
    bool ShouldClose();

private:
    SDL_Window* _window;
	SDL_GLContext _context = nullptr;
};
