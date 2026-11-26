#pragma once

#include <vector>
#include <string>

#include <GL/glew.h>

class EnvironmentMap
{
public:

    explicit EnvironmentMap(const std::vector<std::string>& faces);

    ~EnvironmentMap();

    GLuint GetCubemap() const;

private:

    GLuint _cubemap = 0;
};