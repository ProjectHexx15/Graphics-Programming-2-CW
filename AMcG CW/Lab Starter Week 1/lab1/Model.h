#pragma once

#include <vector>
#include <memory>

#include "Mesh.h"

class Model
{
public:
    void AddMesh(std::shared_ptr<Mesh> mesh);

    void Draw() const;

private:
    std::vector<std::shared_ptr<Mesh>> _meshes;
};