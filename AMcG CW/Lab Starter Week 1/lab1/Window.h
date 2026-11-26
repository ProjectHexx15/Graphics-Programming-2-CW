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

    int GetMouseDeltaX();
    int GetMouseDeltaY();
    int GetMouseWheel();

    bool IsEPressed();

private:
    SDL_Window* _window;
	SDL_GLContext _context;


    int _width;
    int _height;

    int _mouseWheel = 0;

    int _mouseDeltaX = 0;
    int _mouseDeltaY = 0;

    bool _ePressed = false;
    bool _shouldClose = false;

    void SetAttributes();
    void CreateContext();
    void InitGlew();
};
