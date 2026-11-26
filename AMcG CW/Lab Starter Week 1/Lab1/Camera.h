#pragma once

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>

class Camera
{
public:

	Camera(float radius, float aspectRatio);
	~Camera();

	void Update(float deltaTime);

	glm::mat4 GetView() const;
	glm::mat4 GetProjection() const;

	glm::vec3 GetPosition() const;

	void Rotate(float xOffset, float yOffset);
	void Zoom(float amount);

private:
	float _radius;
	float _angle;

	glm::vec3 _target;

	glm::mat4 _projection;

	float _yaw = 0.0f;
	float _pitch = 10.0f;

};
