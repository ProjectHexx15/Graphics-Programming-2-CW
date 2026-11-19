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

private:
	float _radius;
	float _angle;

	glm::vec3 _target;

	glm::mat4 _projection;

};
