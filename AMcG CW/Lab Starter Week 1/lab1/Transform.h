#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Transform
{
public:
    Transform();

    void SetPos(const glm::vec3& pos);
    void SetRot(const glm::vec3& rot);
    void SetScale(const glm::vec3& scale);

    glm::vec3 GetPos() const;
    glm::vec3 GetRot() const;
    glm::vec3 GetScale() const;

    glm::mat4 GetModel() const;

private:
    glm::vec3 _position;
    glm::vec3 _rotation;
    glm::vec3 _scale;
};