#pragma once

#include <string>
#include <GL/glew.h>

#include "ShaderLoader.h"


class Shader
{

public:
	Shader(const char* vertexPath, const char* fragmentPath);
	~Shader();

	void bind() const;
	static void unbind();

	void SetUniform1i(const std::string& name, int value) const;
	void SetUniform1f(const std::string& name, float value) const;
	void setUniformVec3(const std::string& name, float x, float y, float z) const;
	void setUniformMat4(const std::string& name, const float* value) const;

	void CheckCompileErrors(GLuint shader, std::string type);

	unsigned int GetID() const { return _ID; }

private:
	unsigned int _ID;
	ShaderLoader _ShaderLoader;

	int GetUniformLocation(const std::string& name) const;
};

