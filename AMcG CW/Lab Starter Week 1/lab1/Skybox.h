#pragma once

#include <vector>
#include <string>

class Shader;

class Skybox
{
public:
	Skybox(const std::vector<std::string>& faces, Shader* shader);

	void Draw();


private:
	unsigned int cubemap;

	unsigned int vao;
	unsigned int vbo;

	Shader* shader;
};
