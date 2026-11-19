#pragma once

#include <memory>

#include "Shader.h"
#include "Texture.h"

class Material
{
public:

    Material(std::shared_ptr<Shader> shader, std::shared_ptr<Texture> texture = nullptr);

    void Bind() const;

    std::shared_ptr<Shader> GetShader() const
    {
        return _shader;
    }

private:

    std::shared_ptr<Shader> _shader;
    std::shared_ptr<Texture> _texture;
};
