#pragma once

#include <vector>
#include <glm/glm.hpp>

struct Particle
{
	glm::vec3 position;
	glm::vec3 velocity;

	float life;
};

class ParticleEmitter
{
public:
	void Update(float deltaTime);
	void Draw();

	void Spawn();

private:
	std::vector<Particle> particles;
};
