#include "Shader.h"

Shader::Shader(const char* vertexPath, const char* fragmentPath)
{
	_ID = ShaderLoader::LoadShader(vertexPath, fragmentPath);
}

Shader::~Shader()
{
	glDeleteProgram(_ID);
}

void Shader::bind() const
{
	glUseProgram(_ID);
}


void Shader::SetUniform1i(const std::string& name, int value) const
{

}

void Shader::SetUniform1f(const std::string& name, float value) const
{

}
void Shader::setUniformVec3(const std::string& name, float x, float y, float z) const
{

}

void Shader::setUniformMat4(const std::string& name, const float* value) const
{

}


void Unbind()
{

}

void CheckCompileErrors(GLuint shader, std::string type)
{

}
