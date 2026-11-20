#include "Scene.h"

#include "Camera.h"
#include "Shader.h"
#include "Mesh.h"
#include "Transform.h"
#include "Skybox.h"
#include "Entity.h"
#include "Material.h"
#include "ObjectLoader.h"
#include "ResourceManager.h"

// contains alll renderable objects and resources for the sceen

Scene::Scene()
{

}

Scene::~Scene()
{

}

void Scene::Init()
{
    _camera = std::make_shared<Camera>(10.0f, 1280.0f / 720.0f);
    auto pos = _camera->GetPosition();

    ResourceManager::LoadShader("shader", "..\\Assets\\Shaders\\test.vert", "..\\Assets\\Shaders\\test.frag");

    ResourceManager::LoadModel("Tree", "..\\Assets\\Objects\\tree.obj");

    auto shader = ResourceManager::GetShader("shader");
    std::cout << "Shader ID: " << shader->GetID()<< std::endl;

    auto material = std::make_shared<Material>(shader);
    ResourceManager::AddMaterial("TestMaterial",material);

    auto model = ResourceManager::GetModel("Tree");

    _tree = std::make_shared<Entity>(model, material);

    _tree->GetTransform().SetScale(glm::vec3(1.0f));

    AddEntity(_tree);
}

void Scene::Update(float deltaTime)
{
	if (_camera)
	{
		_camera->Update(deltaTime);
	}

    static float angle = 0.0f;
    angle += 50.0f * deltaTime;

    _tree->GetTransform().SetRot(glm::vec3(0.0f, angle, 0.0f));
}

void Scene::Render()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    if (!_camera)
    {
        return;
    }

    if (_skybox)
    {
        _skybox->Draw(*_camera);
    }

    for (const auto& entity : _entitties)
    {
        entity->Draw(*_camera);
    }

    std::cout << "Entities: " << _entitties.size() << std::endl;
}

void Scene::AddEntity(std::shared_ptr<Entity> entity)
{
	_entitties.push_back(entity);
}

const std::vector<std::shared_ptr<Entity>>& Scene::GetEntities() const
{
	return _entitties;
}

void Scene::SetCamera(std::shared_ptr<Camera> camera)
{
	_camera = camera;
}

std::shared_ptr<Camera> Scene::GetCamera() const
{
	return _camera;
}

void Scene::SetSkybox(std::shared_ptr<Skybox> skybox)
{
	//_skybox = skybox;
}

void Scene::SetParticleEmitter(std::shared_ptr<ParticleEmitter> emitter)
{
	//_particleEmitter = emitter;
}