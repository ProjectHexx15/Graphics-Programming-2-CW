#include "Entity.h"

#include "Camera.h"
#include "Material.h"
#include "Shader.h"
#include "Model.h"
#include "Transform.h"

#include <SDL/SDL.h>
#include <iostream>

// a renderable object within the scene

Entity::Entity(std::shared_ptr<Model> model, std::shared_ptr<Material> material): _model(model), _material(material)
{

}

Transform& Entity::GetTransform()
{
    return _transform;
}

void Entity::Draw(const Camera& camera, float explosionAmount) const
{
    _material->Bind();

    auto shader = _material->GetShader();

    shader->SetUniformMat4("u_Model", _transform.GetModel());
    shader->SetUniformMat4("u_View", camera.GetView());
    shader->SetUniformMat4("u_Projection", camera.GetProjection());
    shader->SetUniformVec3("u_CameraPos", camera.GetPosition());
    shader->SetUniform1f("u_Time", SDL_GetTicks() / 500.0f);
    shader->SetUniform1f("u_ExplosionAmount", explosionAmount);
    shader->SetUniformVec3("u_ObjectCenter", _transform.GetPos());

    _model->Draw();
}