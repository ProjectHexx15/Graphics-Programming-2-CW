#include "Entity.h"

#include "Camera.h"
#include "Material.h"
#include "Shader.h"
#include "Model.h"
#include "Transform.h"

#include <iostream>

// a renderable object within the scene

Entity::Entity(std::shared_ptr<Model> model, std::shared_ptr<Material> material): _model(model), _material(material)
{

}

Transform& Entity::GetTransform()
{
    return _transform;
}

void Entity::Draw(const Camera& camera) const
{
    _material->Bind();

    auto shader = _material->GetShader();

    shader->SetUniformMat4("u_Model", _transform.GetModel());
    shader->SetUniformMat4("u_View", camera.GetView());
    shader->SetUniformMat4("u_Projection", camera.GetProjection());
    shader->SetUniformVec3("u_CameraPos", camera.GetPosition());

    _model->Draw();
}