#include "Model.h"

void Model::AddMesh(const Mesh& mesh)
{
	_meshes.push_back(mesh);
}

void Model::Draw() const
{
	for (const auto& mesh : _meshes)
	{
		mesh.Draw();
	}
}