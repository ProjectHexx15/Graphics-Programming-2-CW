#pragma once

#include <GL/glew.h>
#include "Texture.h"
#include "stb_image.h"
#include <iostream>

class Texture
{
public:
    Texture(const std::string& filepath);
    ~Texture();

    void Bind(unsigned int unit = 0) const;

private:
    GLuint _id = 0;
};