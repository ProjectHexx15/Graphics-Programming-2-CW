#include "Shader.h"
#include "ShaderLoader.h"

#include <iostream>
#include <glm/gtc/type_ptr.hpp>

Shader::Shader(const char* vertexPath, const char* fragmentPath, const char* geometryPath)
{
    _ID = ShaderLoader::LoadShader(vertexPath, fragmentPath, geometryPath);
}

Shader::~Shader()
{
    if (_ID != 0)
    {
        glDeleteProgram(_ID);
    }
}

void Shader::bind() const
{
    glUseProgram(_ID);
}

void Shader::unbind()
{
    glUseProgram(0);
}

GLint Shader::GetUniformLocation(const std::string& name) const
{
    GLint location = glGetUniformLocation(_ID, name.c_str());

    if (location == -1)
    {
        std::cerr << "Uniform not found: " << name << std::endl;
    }

    return location;
}

void Shader::SetUniform1i(const std::string& name, int value) const
{
    glUniform1i(GetUniformLocation(name), value);
}

void Shader::SetUniform1f(const std::string& name, float value) const
{
    glUniform1f(GetUniformLocation(name), value);
}

void Shader::SetUniformVec3(const std::string& name, const glm::vec3& value) const
{
    glUniform3f(GetUniformLocation(name), value.x, value.y, value.z);
}

void Shader::SetUniformMat4(const std::string& name, const glm::mat4& value) const
{
    glUniformMatrix4fv(GetUniformLocation(name), 1, GL_FALSE, glm::value_ptr(value));
}