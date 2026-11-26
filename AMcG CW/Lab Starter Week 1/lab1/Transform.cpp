#include "Transform.h"

Transform::Transform() : _position(0.0f), _rotation(0.0f), _scale(1.0f)
{

}

void Transform::SetPos(const glm::vec3& pos)
{
    _position = pos;
}

void Transform::SetRot(const glm::vec3& rot)
{
    _rotation = rot;
}

void Transform::SetScale(const glm::vec3& scale)
{
    _scale = scale;
}

glm::vec3 Transform::GetPos() const
{
    return _position;
}

glm::vec3 Transform::GetRot() const
{
    return _rotation;
}

glm::vec3 Transform::GetScale() const
{
    return _scale;
}

glm::mat4 Transform::GetModel() const
{
    glm::mat4 model(1.0f);

    model = glm::translate(model, _position);

    model = glm::rotate(model, glm::radians(_rotation.x), glm::vec3(1, 0, 0));
    model = glm::rotate(model, glm::radians(_rotation.y), glm::vec3(0, 1, 0));
    model = glm::rotate(model, glm::radians(_rotation.z), glm::vec3(0, 0, 1));

    model = glm::scale(model, _scale);

    return model;
}