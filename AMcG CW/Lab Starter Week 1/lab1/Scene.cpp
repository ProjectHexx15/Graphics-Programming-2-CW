#include "Scene.h"


Scene::Scene()
{

}

Scene::~Scene()
{

}

void Scene::Init()
{
    std::cout << "Scene Init" << std::endl;

    _camera = std::make_shared<Camera>(10.0f, 1280.0f / 720.0f);

   // shader = std::make_shared<Shader>("..\\Assets\\Shaders\\test.vert", "..\\Assets\\Shaders\\test.frag");
    ResourceManager::LoadShader("shader", "..\\Assets\\Shaders\\test.vert", "..\\Assets\\Shaders\\test.frag");

    material = std::make_shared<Material>(shader);
    ResourceManager::AddMaterial("TreeMaterial", material);

    auto model = std::make_shared<Model>(ObjectLoader::LoadObj("..\\Assets\\Objects\\tree.obj"));

    tree = std::make_shared<Entity>(model, material);

    AddEntity(tree);

    tree->GetTransform().SetPos(glm::vec3(0.0f, 0.0f, 0.0f));
    tree->GetTransform().SetScale(glm::vec3(5.0f));

    std::cout << "Scene Loaded" << std::endl;
}

void Scene::Update(float deltaTime)
{
	if (_camera)
	{
		_camera->Update(deltaTime);
	}

    static float angle = 0.0f;

    angle += 50.0f * deltaTime;

    tree->GetTransform().SetRot(glm::vec3(0.0f, angle, 0.0f));
}

void Scene::Render()
{
    if (!_camera)
    {
        return;
    }

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    for (const auto& entity : _entitties)
    {
        entity->Draw(*_camera);
    }

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