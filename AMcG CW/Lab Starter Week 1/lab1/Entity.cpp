#include "Entity.h"

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

    _model->Draw();
}