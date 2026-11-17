#pragma once

#include "glm/glm.hpp"

class Model;
class Material;

class Entity
{
public:
	Entity();

	virtual void Update(float deltaTime);
	virtual void Render();

	void SetModel(Model* model);
	void SetMaterial(Material* material);

protected:
	glm::vec3 position;
	glm::vec3 rotation;
	glm::vec3 scale;

	Model* model;
	Material* material;

};