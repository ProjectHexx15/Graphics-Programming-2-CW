#pragma once

#include <memory>

class Shader;
class Texture;

class Material
{
public:

    Material(std::shared_ptr<Shader> shader, std::shared_ptr<Texture> texture = nullptr);

    void Bind() const;

    std::shared_ptr<Shader> GetShader() const;

private:

    std::shared_ptr<Shader> _shader;
    std::shared_ptr<Texture> _texture;
};