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
    ResourceManager::LoadShader("Cupcake", "..\\Assets\\Shaders\\cupcake.vert", "..\\Assets\\Shaders\\cupcake.frag", "..\\Assets\\Shaders\\cupcake.geom");
    ResourceManager::LoadShader("Kitty", "..\\Assets\\Shaders\\kitty.vert", "..\\Assets\\Shaders\\kitty.frag");

    ResourceManager::LoadTexture("GemTexture", "..\\Assets\\Textures\\GemTexture.png");
    ResourceManager::LoadTexture("CupcakeTexture", "..\\Assets\\Textures\\CupcakeTexture.png");
    ResourceManager::LoadTexture("KittyTexture", "..\\Assets\\Textures\\CupcakeTexture.png");

    ResourceManager::LoadModel("Gem", "..\\Assets\\Objects\\gem.obj");
    ResourceManager::LoadModel("Cupcake", "..\\Assets\\Objects\\cupcake.obj");
    ResourceManager::LoadModel("Kitty", "..\\Assets\\Objects\\cupcake.obj");


    auto gemShader =  ResourceManager::GetShader("Gem");
    auto gemTexture = ResourceManager::GetTexture("GemTexture");
    auto gemModel = ResourceManager::GetModel("Gem");
    auto gemMaterial = std::make_shared<Material>(gemShader, gemTexture);
    ResourceManager::AddMaterial("gemMaterial", gemMaterial);

    gemMaterial->SetEnvironmentMap(environment->GetCubemap());

    _gem = std::make_shared<Entity>(gemModel, gemMaterial);
    _gem->GetTransform().SetScale(glm::vec3(1.0f));
  
    AddEntity(_gem);


    cupcakeShader = ResourceManager::GetShader("Cupcake");
    auto cupcakeTexture = ResourceManager::GetTexture("CupcakeTexture");
    auto cupcakeModel = ResourceManager::GetModel("Cupcake");
    cupcakeMaterial = std::make_shared<Material>(cupcakeShader, cupcakeTexture);
    ResourceManager::AddMaterial("cupcakeMaterial", cupcakeMaterial);

    _cupcake = std::make_shared<Entity>(cupcakeModel, cupcakeMaterial);
    _cupcake->GetTransform().SetScale(glm::vec3(1.0f));
    _cupcake->GetTransform().SetPos(glm::vec3(0.0f, 0.0f, 2.0f));
    _cupcake->GetTransform().SetRot(glm::vec3(0.0f, 45.0f, 0.0f));

    AddEntity(_cupcake);

    kittyShader = ResourceManager::GetShader("Kitty");
    auto kittyTexture = ResourceManager::GetTexture("KittyTexture");
    auto kittyModel = ResourceManager::GetModel("Kitty");
    kittyMaterial = std::make_shared<Material>(kittyShader, kittyTexture);
    ResourceManager::AddMaterial("kittyMaterial", kittyMaterial);

    _kitty = std::make_shared<Entity>(kittyModel, kittyMaterial);
    _kitty->GetTransform().SetScale(glm::vec3(1.0f));
    _kitty->GetTransform().SetPos(glm::vec3(0.0f, 0.0f, -2.0f));
    _kitty->GetTransform().SetRot(glm::vec3(0.0f, 45.0f, 0.0f));

    AddEntity(_kitty);

}

void Scene::Update(float deltaTime)
{
    float target = _explode ? 0.35f : 0.0f;

    _explosionAmount += (target - _explosionAmount) * deltaTime * 0.5f;


	if (_camera)
	{
		_camera->Update(deltaTime);
	}
}

void Scene::Render()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    if (_skybox)
    {
        _skybox->Draw(*_camera);
    }

    for (const auto& entity : _entitties)
    {
        if (entity != _gem)
        {
            entity->Draw(*_camera, _explosionAmount);
        }
    }


    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    _gem->Draw(*_camera, _explosionAmount);

    glDisable(GL_BLEND);

    if (!_camera)
    {
        return;
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

void Scene::ToggleExplosion()
{
    _explode = !_explode;
}