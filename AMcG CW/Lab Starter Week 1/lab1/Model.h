#pragma once

#include <vector>

#include "Mesh.h"

class Model
{
public:
	void AddMesh(const Mesh& mesh);

	void Draw() const;

private:
	std::vector<Mesh> _meshes;
};
