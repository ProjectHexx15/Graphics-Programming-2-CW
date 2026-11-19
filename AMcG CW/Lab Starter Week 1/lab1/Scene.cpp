#include "Scene.h"
#include "Camera.h"
#include "Shader.h"
#include "Mesh.h"
#include "ObjectLoader.h"
#include <iostream>

#include <GL/glew.h>

std::shared_ptr<Shader> shader;
Model testModel;


Scene::Scene()
{

}

Scene::~Scene()
{

}

void Scene::Init()
{
	std::cout << "Scene Init" << std::endl;

	_camera = std::make_shared<Camera>(
		10.0f,
		1280.0f / 720.0f);

	shader = std::make_shared<Shader>("..\\Assets\\Shaders\\test.vert", "..\\Assets\\Shaders\\test.frag");

	std::cout << "Shader Created" << std::endl;

	testModel = ObjectLoader::LoadObj("..\\Assets\\Objects\\tree.obj");

	std::cout << "Model Loaded" << std::endl;

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
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	shader->bind();

	static float angle = 0.0f;
	angle += 0.01f;

	glm::mat4 model =
		glm::rotate(
			angle,
			glm::vec3(0, 1, 0));

	shader->SetUniformMat4(
		"u_Model",
		model);

	shader->SetUniformMat4(
		"u_View",
		_camera->GetView());

	shader->SetUniformMat4(
		"u_Projection",
		_camera->GetProjection());

	testModel.Draw();
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

void Scene::SetParticleEmitter(std::shared_ptr<ParticleEmitter> emitter)
{
	_particleEmitter = emitter;
}