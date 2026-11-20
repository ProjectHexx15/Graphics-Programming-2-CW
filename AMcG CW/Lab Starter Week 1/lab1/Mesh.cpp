#include "Mesh.h"
#include <iostream>

// geometry of an object

struct MeshVertex
{
    glm::vec3 position;
    glm::vec2 texCoord;
    glm::vec3 normal;
};


Mesh::Mesh()
{
}

Mesh::~Mesh()
{
}

Mesh::Mesh(const IndexedModel& model)
{
    InitModel(model);
}

void Mesh::LoadModel(const std::string& filename)
{
    IndexedModel model = OBJModel(filename).ToIndexedModel();

    InitModel(model);
}

void Mesh::InitModel(const IndexedModel& model)
{
    std::vector<MeshVertex> vertices;

    vertices.reserve(model.positions.size());

    for (size_t i = 0; i < model.positions.size(); ++i)
    {
        MeshVertex vertex;

        vertex.position = model.positions[i];
        vertex.texCoord = model.texCoords[i];
        vertex.normal = model.normals[i];

        vertices.push_back(vertex);
    }

    _indexCount = static_cast<unsigned int>(model.indices.size());

    _vbo = std::make_unique<VertexBufferObject>(vertices.data(), vertices.size() * sizeof(MeshVertex));
    _ibo = std::make_unique<IndexBufferObject>(model.indices.data(), _indexCount);

    _vao.Bind();
    _vao.BindVertexBuffer(0, *_vbo, sizeof(MeshVertex));
    _vao.BindIndexBuffer(*_ibo);

    _vao.AddAttribute(0, 3, GL_FLOAT, 0, offsetof(MeshVertex, position));

    _vao.AddAttribute(1, 2, GL_FLOAT, 0, offsetof(MeshVertex, texCoord));

    _vao.AddAttribute(2, 3, GL_FLOAT, 0, offsetof(MeshVertex, normal));

    VertexArrayObject::UnBind();
}

void Mesh::Draw() const
{
    std::cout << "Indices: " << _indexCount << std::endl;

    _vao.Bind();

    glDrawElements(GL_TRIANGLES, _indexCount, GL_UNSIGNED_INT, nullptr);

    VertexArrayObject::UnBind();
}