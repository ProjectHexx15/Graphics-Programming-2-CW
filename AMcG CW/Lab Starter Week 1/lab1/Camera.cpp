#include "Camera.h"

Camera::Camera(float radius, float aspectRatio) : _radius(radius), _angle(0.0f), _target(0.0f, 0.0f, 0.0f)
{
	_projection = glm::perspective(glm::radians(60.0f), aspectRatio, 0.1f, 100.0f);
}

Camera::~Camera()
{

}

void Camera::Update(float deltaTime)
{
	_angle += deltaTime * 0.5f;
}

glm::vec3 Camera::GetPosition() const
{
	return glm::vec3(cos(_angle) * _radius, 2.0f, sin(_angle) * _radius);
}

glm::mat4 Camera::GetView() const
{
    return glm::lookAt(GetPosition(), _target, glm::vec3(0, 1, 0));
}


glm::mat4 Camera::GetProjection() const
{
	return _projection;
}