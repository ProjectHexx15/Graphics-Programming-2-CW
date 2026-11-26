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
#include "EnviornmentMap.h"

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

    std::vector<std::string> faces =
    {
        "..\\Assets\\Textures\\right.png",
        "..\\Assets\\Textures\\left.png",
        "..\\Assets\\Textures\\top.png",
        "..\\Assets\\Textures\\bottom.png",
        "..\\Assets\\Textures\\front.png",
        "..\\Assets\\Textures\\back.png"
    };

    auto environment = std::make_shared<EnvironmentMap>(faces);

    _skybox = std::make_shared<Skybox>(environment);

    ResourceManager::LoadShader("Gem", "..\\Assets\\Shaders\\crystal_apple.vert", "..\\Assets\\Shaders\\crystal_apple.frag");
    ResourceManager::LoadTexture("GemTexture", "..\\Assets\\Textures\\GemTexture.png");
    ResourceManager::LoadModel("Gem", "..\\Assets\\Objects\\gem.obj");

    auto gemShader =  ResourceManager::GetShader("Gem");
    auto gemTexture = ResourceManager::GetTexture("GemTexture");
    auto gemModel = ResourceManager::GetModel("Gem");
    auto gemMaterial = std::make_shared<Material>(gemShader, gemTexture);

    gemMaterial->SetEnvironmentMap(environment->GetCubemap());

    _gem = std::make_shared<Entity>(gemModel, gemMaterial);
    _gem->GetTransform().SetScale(glm::vec3(1.0f));

    AddEntity(_gem);
}

void Scene::Update(float deltaTime)
{
	if (_camera)
	{
		_camera->Update(deltaTime);
	}
}

void Scene::Render()
{
    glClearColor(1.0f, 0.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glEnable(GL_BLEND);

    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    if (!_camera)
    {
        return;
    }

    for (const auto& entity : _entitties)
    {
        entity->Draw(*_camera);
    }

    glDisable(GL_BLEND);

    if (_skybox)
    {
        _skybox->Draw(*_camera);
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
	_skybox = skybox;
}

void Scene::ProcessMouseMotion(int xRel, int yRel)
{
    if (_camera)
    {
        _camera->Rotate((float)xRel, (float)yRel);
    }
}

void Scene::ProcessMouseWheel(float delta)
{
    if (_camera)
    {
        _camera->Zoom(delta);
    }
}