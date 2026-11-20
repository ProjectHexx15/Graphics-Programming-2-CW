#pragma once

#include <string>
#include <unordered_map>
#include <memory>

class Shader;
class Texture;
class Model;
class Material;

class ResourceManager
{
public:

    static void LoadShader(const std::string& name, const std::string& vertex, const std::string& fragment);
    static std::shared_ptr<Shader>GetShader(const std::string& name);

    static void LoadTexture(const std::string& name, const std::string& path);
    static std::shared_ptr<Texture> GetTexture(const std::string& name);

    static void LoadModel(const std::string& name, const std::string& path);
    static std::shared_ptr<Model> GetModel(const std::string& name);

    static void AddMaterial(const std::string& name, std::shared_ptr<Material> material);
    static std::shared_ptr<Material> GetMaterial(const std::string& name);

private:

    static std::unordered_map<std::string, std::shared_ptr<Shader>> _shaders;
    static std::unordered_map<std::string, std::shared_ptr<Texture>> _textures;
    static std::unordered_map<std::string, std::shared_ptr<Model>> _models;
    static std::unordered_map<std::string, std::shared_ptr<Material>> _materials;
};