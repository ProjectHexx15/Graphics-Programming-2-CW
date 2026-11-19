#pragma once

#include <memory>

#include "Shader.h"
#include "Texture.h"

class Material
{
public:
    Material(std::shared_ptr<Shader> shader);

    void Bind() const;

    std::shared_ptr<Shader> GetShader() const;

private:
    std::shared_ptr<Shader> _shader;
};