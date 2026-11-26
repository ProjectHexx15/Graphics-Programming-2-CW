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
}

glm::vec3 Camera::GetPosition() const
{
    glm::vec3 position;

    position.x = _radius * cos(glm::radians(_pitch)) * cos(glm::radians(_yaw));

    position.y = _radius * sin(glm::radians(_pitch));

    position.z = _radius * cos(glm::radians(_pitch)) * sin(glm::radians(_yaw));

    return position;
}

glm::mat4 Camera::GetView() const
{
    return glm::lookAt(GetPosition(), _target, glm::vec3(0, 1, 0));
}


glm::mat4 Camera::GetProjection() const
{
	return _projection;
}

void Camera::Rotate(float xOffset, float yOffset)
{
    const float sensitivity = 0.5f;

    _yaw += xOffset * sensitivity;

    _pitch += yOffset * sensitivity;

    _pitch = glm::clamp(_pitch, -89.0f, 89.0f);
}

void Camera::Zoom(float amount)
{
    _radius -= amount;

    _radius = glm::clamp(_radius, 2.0f, 30.0f);
}