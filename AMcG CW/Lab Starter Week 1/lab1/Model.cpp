#include "Model.h"

void Model::AddMesh(std::shared_ptr<Mesh> mesh)
{
    _meshes.push_back(mesh);
}

void Model::Draw() const
{
    for (const auto& mesh : _meshes)
    {
        mesh->Draw();
    }
}