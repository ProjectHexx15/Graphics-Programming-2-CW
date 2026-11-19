#pragma once

#include <memory>

#include "Camera.h"
#include "Transform.h"
#include "Model.h"
#include "Material.h"

class Camera;

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
