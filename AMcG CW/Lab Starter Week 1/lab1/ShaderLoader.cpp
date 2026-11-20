#include "ShaderLoader.h"

//  handles the compilation of shaders and linking them
        // SEPERATES FILE LOADING FROM SHADERS


std::string ShaderLoader::ReadFile(const std::string& filepath)
{
    std::ifstream file(filepath);

    if (!file.is_open())
    {
        std::cerr << "Failed to open shader file: " << filepath << std::endl;

        return "";
    }

    std::stringstream stream;
    stream << file.rdbuf();

    file.close();

    return stream.str();

}

GLuint ShaderLoader::CompileShader(GLenum type, const std::string& source)
{
    GLuint shader = glCreateShader(type);

    const char* src = source.c_str();

    glShaderSource(shader, 1, &src, nullptr);
    glCompileShader(shader);

    switch (type)
    {
    case GL_VERTEX_SHADER:
        CheckCompileErrors(shader, "VERTEX");
        break;

    case GL_FRAGMENT_SHADER:
        CheckCompileErrors(shader, "FRAGMENT");
        break;

    case GL_GEOMETRY_SHADER:
        CheckCompileErrors(shader, "GEOMETRY");
        break;

    }

    return shader;

}

GLuint ShaderLoader::LoadShader(const char* vertexPath, const char* fragmentPath, const char* geometryPath)
{
    std::string vertexSource = ReadFile(vertexPath);
    std::string fragmentSource = ReadFile(fragmentPath);

    GLuint vertexShader = CompileShader(GL_VERTEX_SHADER, vertexSource);
    GLuint fragmentShader = CompileShader(GL_FRAGMENT_SHADER, fragmentSource);

    GLuint geometryShader = 0;

    if (geometryPath != nullptr)
    {
        std::string geometrySource = ReadFile(geometryPath);

        geometryShader = CompileShader(GL_GEOMETRY_SHADER, geometrySource);
    }

    GLuint program = glCreateProgram();

    glAttachShader(program, vertexShader);

    if (geometryShader != 0)
    {
        glAttachShader(program, geometryShader);
    }

    glAttachShader(program, fragmentShader);
    glLinkProgram(program);

    CheckCompileErrors(program, "PROGRAM");

    glDeleteShader(vertexShader);

    if (geometryShader != 0)
    {
        glDeleteShader(geometryShader);
    }

    glDeleteShader(fragmentShader);

    return program;
}

void ShaderLoader::CheckCompileErrors(GLuint object, const std::string& type)
{
    GLint success;
    GLchar infoLog[1024];

    if (type != "PROGRAM")
    {
        glGetShaderiv(object, GL_COMPILE_STATUS, &success);

        if (!success)
        {
           glGetShaderInfoLog(object, sizeof(infoLog), nullptr, infoLog);

            std::cerr << type << " Failed to compile shader " << infoLog << std::endl;
        }
    }
    else
    {
        glGetProgramiv(object, GL_LINK_STATUS, &success);

        if (!success)
        {
            glGetProgramInfoLog(object, sizeof(infoLog), nullptr, infoLog);

            std::cerr  << "Failed to link program " << infoLog << std::endl;
        }
    }
}



