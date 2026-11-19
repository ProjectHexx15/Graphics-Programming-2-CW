#pragma once
#include <GL/glew.h>
#include <string>

#include <glm/glm.hpp>

class Shader
{
public:
    Shader(const char* vertexPath, const char* fragmentPath, const char* geometryPath = nullptr);

    ~Shader();

    void bind() const;
    static void unbind();

    void SetUniform1i(const std::string& name, int value) const;

    void SetUniform1f(const std::string& name, float value) const;

    void SetUniformVec3(const std::string& name, const glm::vec3& value) const;

    void SetUniformMat4(const std::string& name, const glm::mat4& value) const;

    GLuint GetID() const
    {
        return _ID;
    }

private:
    GLint GetUniformLocation(const std::string& name) const;

private:
    GLuint _ID = 0;

};