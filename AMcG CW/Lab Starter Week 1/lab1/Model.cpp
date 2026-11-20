#include "Model.h"
#include <iostream>

// complete asset including one or more messhes

void Model::AddMesh(std::shared_ptr<Mesh> mesh)
{
    _meshes.push_back(mesh);
}

void Model::Draw() const
{
    std::cout << "Meshes: " << _meshes.size() << std::endl;

    for (const auto& mesh : _meshes)
    {
        mesh->Draw();
    }
}