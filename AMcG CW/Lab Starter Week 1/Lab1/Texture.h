#pragma once

#include <GL/glew.h>

class Texture
{
public:
    Texture(const char* filepath);
    ~Texture();

    void Bind(unsigned int slot = 0) const;

private:
    GLuint _id = 0;
};