#include "ResourceManager.h"

std::unordered_map<std::string, std::shared_ptr<Shader>> ResourceManager::_shaders;
std::unordered_map<std::string, std::shared_ptr<Texture>> ResourceManager::_textures;
std::unordered_map<std::string, std::shared_ptr<Model>> ResourceManager::_models;
std::unordered_map<std::string, std::shared_ptr<Material>> ResourceManager::_materials;

Material* ResourceManager::GetMaterial(const std::string& name)
{
	return _materials[name].get();
}

void ResourceManager::AddMaterial(const std::string& name, std::shared_ptr<Material> material)
{
	_materials[name] = std::move(material);
}





void ResourceManager::LoadShader(const std::string& name, const std::string& vertex, const std::string& fragment)
{
	// error is here hoe or where this is being used
	_shaders[name] = std::make_shared<Shader>(vertex.c_str(), fragment.c_str());
}

Shader* ResourceManager::GetShader(const std::string& name)
{
	auto shader = _shaders.find(name);
	return shader != _shaders.end() ? shader->second.get() : nullptr;
}
