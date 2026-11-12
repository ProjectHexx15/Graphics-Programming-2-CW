#pragma once
#include <string>
#include <GL\glew.h>
#include <iostream>
#include <fstream>

class ShaderLoader
{

public:
	ShaderLoader();
	~ShaderLoader();

	unsigned int loadShader(const char* vertexPath, const char* fragmentPath);


private:
	unsigned int compileShader(unsigned int type, const char* source);


};
