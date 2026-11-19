#include "Material.h"

Material::Material(std::shared_ptr<Shader> shader): _shader(shader)
{

}

void Material::Bind() const
{
    _shader->bind();
}

std::shared_ptr<Shader>
Material::GetShader() const
{
    return _shader;
}