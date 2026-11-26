#include "ResourceManager.h"

#include "Shader.h"
#include "Texture.h"
#include "Model.h"
#include "Material.h"
#include "ObjectLoader.h"

std::unordered_map<std::string, std::shared_ptr<Shader>> ResourceManager::_shaders;
std::unordered_map<std::string, std::shared_ptr<Texture>> ResourceManager::_textures;
std::unordered_map<std::string, std::shared_ptr<Model>> ResourceManager::_models;
std::unordered_map<std::string, std::shared_ptr<Material>> ResourceManager::_materials;

// manages the assets for the scene

void ResourceManager::LoadShader(const std::string& name, const std::string& vertex, const std::string& fragment)
{
    _shaders[name] = std::make_shared<Shader>(vertex.c_str(), fragment.c_str());
}

void ResourceManager::LoadShader(const std::string& name, const std::string& vertex, const std::string& fragment, const std::string& geometry)
{
    _shaders[name] = std::make_shared<Shader>(vertex.c_str(), fragment.c_str(), geometry.c_str());
}

std::shared_ptr<Shader> ResourceManager::GetShader(const std::string& name)
{
    auto it = _shaders.find(name);

    if (it == _shaders.end())
    {
        return nullptr;
    }

    return it->second;
}


void ResourceManager::LoadTexture(const std::string& name, const std::string& path)
{
    _textures[name] = std::make_shared<Texture>(path);
}

std::shared_ptr<Texture> ResourceManager::GetTexture(const std::string& name)
{
    auto it = _textures.find(name);

    if (it == _textures.end())
    {
        return nullptr;
    }

    return it->second;
}


void ResourceManager::LoadModel(const std::string& name, const std::string& path)
{
    _models[name] = std::make_shared<Model>(ObjectLoader::LoadObj(path));
}

std::shared_ptr<Model> ResourceManager::GetModel(const std::string& name)
{
    auto it = _models.find(name);

    if (it == _models.end())
    {
        return nullptr;
    }

    return it->second;
}

void ResourceManager::AddMaterial(const std::string& name, std::shared_ptr<Material> material)
{
    _materials[name] = material;
}

std::shared_ptr<Material> ResourceManager::GetMaterial(const std::string& name)
{
    auto it = _materials.find(name);

    if (it == _materials.end())
    {
        return nullptr;
    }

    return it->second;
}
