#pragma once

#include <memory>

class Model;
class Material;
class Camera;

#include "Transform.h"

class Entity
{
public:

    Entity(std::shared_ptr<Model> model, std::shared_ptr<Material> material);

    Transform& GetTransform();

    void Draw(const Camera& camera) const;

private:

    Transform _transform;

    std::shared_ptr<Model> _model;
    std::shared_ptr<Material> _material;
};