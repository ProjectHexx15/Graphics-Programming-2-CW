#pragma once

#include <vector>
#include <memory>

#include <glm/glm.hpp>

#include "obj_loader.h"
#include "Buffer.h"


struct Vertex
{
	glm::vec3 Position;
	glm::vec2 TexCoord;
	glm::vec3 Normal;
};

class Mesh
{

public:
	Mesh() = default;

	explicit Mesh(const IndexedModel& model);
	~Mesh();

	void Draw() const;

	const std::vector<Vertex>& GetVertices() const;
	const std::vector<unsigned int>& GetIndices() const;

private:
	VertexArrayObject VAO;
	VertexBufferObject VBO;
	IndexBufferObject EBO;

	std::vector<Vertex> _vertices;
	std::vector<unsigned int> _indices;

	void SetUpMesh();
};
