#pragma once

#include <vector>
#include <memory>
#include <iostream>
#include <GL/glew.h>

class Camera;
class Skybox;
class ParticleEmitter;

class Scene
{
public:
	Scene();
	~Scene();

	void Init();
	void Update(float deltaTime);
	void Render();
	
	void AddEntity(std::shared_ptr<Entity> entity);

	void SetCamera(std::shared_ptr<Camera> camera);
	void SetSkybox(std::shared_ptr<Skybox> skybox);
	void SetParticleEmitter(std::shared_ptr<ParticleEmitter> emitter);

	std::shared_ptr<Camera> GetCamera() const;
	const std::vector<std::shared_ptr<Entity>>& GetEntities() const;

private:
	std::vector<std::shared_ptr<Entity>> _entitties;
	std::shared_ptr<Material> material;

	std::shared_ptr<Shader> shader;

	std::shared_ptr<Entity> _tree;

	std::shared_ptr<Camera> _camera;
	std::shared_ptr<Skybox> _skybox;
};
