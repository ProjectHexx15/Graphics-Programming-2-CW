#pragma once
#include <string>
#include <GL\glew.h>
#include <iostream>
#include <sstream>
#include <fstream>

class ShaderLoader
{

public:
	static GLuint LoadShader(const char* vertexPath, const char* fragmentPath, const char* geometryPath = nullptr);

private:
	static std::string ReadFile(const std::string& filepath);
	static GLuint CompileShader(GLenum type, const std::string& source);
	static unsigned int CompileShader(unsigned int type, const char* source);
	static void CheckCompileErrors(GLuint object, const std::string& type);


};
