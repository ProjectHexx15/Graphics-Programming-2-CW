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
	void unbind() const;

	void setUniform1i(const std::string& name, int value) const;
	void setUniform1f(const std::string& name, float value) const;
	void setUniformMatrix4fv(const std::string& name, const float* value) const;

private:
	unsigned int _ID;
	ShaderLoader _ShaderLoader;
};

};
