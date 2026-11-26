#pragma once

#include <memory>
#include <vector>
#include <iostream>

class Camera;
class Entity;
class Skybox;
class ParticleEmitter;
class Material;
class Shader;
class EnviornmentMap;

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

    void Scene::ToggleExplosion();

    void ProcessMouseMotion(int xRel, int yRel);
    void ProcessMouseWheel(float delta);

    std::shared_ptr<Camera> GetCamera() const;
    const std::vector<std::shared_ptr<Entity>>& GetEntities() const;

private:

    float _explosionAmount = 0.0f;
    bool _explode = false;

    std::vector<std::shared_ptr<Entity>> _entitties;

    std::shared_ptr<Material> gemMaterial;
    std::shared_ptr<Shader> gemShader;
    std::shared_ptr<Entity> _gem;

    std::shared_ptr<Material> cupcakeMaterial;
    std::shared_ptr<Shader> cupcakeShader;
    std::shared_ptr<Entity> _cupcake;

    std::shared_ptr<Camera> _camera;
    std::shared_ptr<Skybox> _skybox;
};