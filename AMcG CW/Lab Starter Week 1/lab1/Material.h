#pragma once

#include <glm/glm.hpp>

class Shader;
class Texture;

class Material
{
public:
	Material();
	Material(Shader* shader, Texture* texture);
	void Bind() const;


private:
	Shader* _shader;
	Texture* _texture;

	glm::vec3 _colour;
};