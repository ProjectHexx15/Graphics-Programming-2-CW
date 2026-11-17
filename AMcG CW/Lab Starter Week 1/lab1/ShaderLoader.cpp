#include "ShaderLoader.h"

std::string ReadFile(const char* path)
{
	std::fstream shaderFile;
	shaderFile.open(path);

	if (!shaderFile.is_open())
	{
		shaderFile.close();
		const char* msg = "NO shader found!!!!!!!";
		// find some way to send an error message
	}

	std::stringstream shaderStream;
	shaderStream << shaderFile.rdbuf();
	shaderFile.close();

	std::string returnString = shaderStream.str();
	shaderStream.clear();

	return returnString;
}

static unsigned int compileShader(unsigned int type, const char* source)
{

}

unsigned int LoadShader(const char* vertexPath, const char* fragmentPath, const char* geometryPath = nullptr)
{

}

