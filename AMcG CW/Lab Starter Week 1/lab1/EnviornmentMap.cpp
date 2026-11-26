#include <iostream>

#include "EnviornmentMap.h"

#include "Shader.h"
#include "Camera.h"

#include "stb_image.h"

#include <glm/glm.hpp>


EnvironmentMap::EnvironmentMap(const std::vector<std::string>& faces)
{
    glGenTextures(1, &_cubemap);

    glBindTexture(GL_TEXTURE_CUBE_MAP, _cubemap);

    int width;
    int height;
    int channels;

    for (unsigned int i = 0; i < faces.size(); ++i)
    {
        unsigned char* data = stbi_load(faces[i].c_str(), &width, &height, &channels, 0);

        if (!data)
        {
            std::cerr << "Failed to load cubemap face: " << faces[i] << std::endl;

            continue;
        }

        GLenum format = channels == 4 ? GL_RGBA : GL_RGB;

        glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);

        stbi_image_free(data);
    }

    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R,GL_CLAMP_TO_EDGE);
}

EnvironmentMap::~EnvironmentMap()
{
    if (_cubemap)
    {
        glDeleteTextures(1, &_cubemap);
    }
}

GLuint EnvironmentMap::GetCubemap() const
{
    return _cubemap;
}