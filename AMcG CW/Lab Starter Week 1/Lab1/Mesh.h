#pragma once

#include <memory>

#include "Buffer.h"
#include "obj_loader.h"

class Mesh
{
public:
    Mesh();
    explicit Mesh(const IndexedModel& model);
    ~Mesh();

    void Draw() const;
    void LoadModel(const std::string& filename);

private:
    void InitModel(const IndexedModel& model);

private:
    VertexArrayObject _vao;

    std::unique_ptr<VertexBufferObject> _vbo;
    std::unique_ptr<IndexBufferObject> _ibo;

    unsigned int _indexCount = 0;
};