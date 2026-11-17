#pragma once
#include <string>
#include <GL\glew.h>
#include <iostream>
#include <sstream>
#include <fstream>

class ShaderLoader
{

public:
	static unsigned int LoadShader(const char* vertexPath, const char* fragmentPath, const char* geometryPath = nullptr);


private:
	static std::string ReadFile(const char* path);
	static unsigned int compileShader(unsigned int type, const char* source);


};
