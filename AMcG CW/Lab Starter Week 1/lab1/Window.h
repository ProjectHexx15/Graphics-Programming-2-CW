#pragma once

#include <iostream>
#include <string>
#include <SDL/SDL.h>
#include <GL/glew.h>


class Window
{
public:
    Window(int width, int height, const std::string& title);
    ~Window();

    void PollEvents();
    void SwapBuffers();

    bool ShouldClose();

    SDL_Window* GetWindow() const;
    SDL_GLContext GetContext() const;

    int GetWidth() const;
    int GetHeight() const;

private:
    SDL_Window* _window;
	SDL_GLContext _context;

    int _width;
    int _height;

    bool _shouldClose = false;

    void SetAttributes();
    void CreateContext();
    void InitGlew();
};
