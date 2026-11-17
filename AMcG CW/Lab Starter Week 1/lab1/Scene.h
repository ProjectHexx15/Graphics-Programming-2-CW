#pragma once

#include <vector>
#include <memory>

class Entity;
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
	void RemoveEntity(std::shared_ptr<Entity> entity);
	void SetCamera(std::shared_ptr<Camera> camera);
	void SetSkybox(std::shared_ptr<Skybox> Skybox);
	void SetParticleEmitter(std::shared_ptr<ParticleEmitter> emitter);

	std::shared_ptr<Camera> GetCamera() const;
	std::shared_ptr<std::shared_ptr<Entity>>& GetEntities() const;

private:
	std::vector<std::shared_ptr<Entity>> _entitties;

	std::shared_ptr<Camera> _camera;
	std::shared_ptr<Skybox> _skybox;
	std::shared_ptr<ParticleEmitter> _particleEmitter;
};
