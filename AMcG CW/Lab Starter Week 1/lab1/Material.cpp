#include "Material.h"

#include "Shader.h"
#include "Texture.h"
#include <GL/glew.h>

// owns shaders, textures to define how objects should be rendeered

Material::Material(std::shared_ptr<Shader> shader, std::shared_ptr<Texture> texture): _shader(shader), _texture(texture)
{

}

void Material::Bind() const
{
    _shader->bind();

    if (_texture)
    {
        _texture->Bind(0);
        _shader->SetUniform1i("u_Texture", 0);
    }

    if (_environmentMap != 0)
    {
        glActiveTexture(GL_TEXTURE1);

        glBindTexture(GL_TEXTURE_CUBE_MAP, _environmentMap);

        _shader->SetUniform1i("u_EnvironmentMap", 1);
    }

}

std::shared_ptr<Shader> Material::GetShader() const
{
    return _shader;
}

void Material::SetEnvironmentMap(GLuint cubemap)
{
    _environmentMap = cubemap;
}
