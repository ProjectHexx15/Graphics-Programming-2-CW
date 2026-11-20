#include "Skybox.h"
#include "Shader.h"
#include "Camera.h"

Skybox::Skybox(
    const std::vector<std::string>& faces)
{
    _cubemap =
        LoadCubemap(faces);
}

GLuint Skybox::LoadCubemap(
    const std::vector<std::string>& faces)
{
    GLuint tex;

    glGenTextures(
        1,
        &tex);

    return tex;
}

void Skybox::Draw(
    const Camera& camera)
{
    glDepthFunc(GL_LEQUAL);

    _shader->bind();

    glBindVertexArray(_vao);

    glActiveTexture(GL_TEXTURE0);

    glBindTexture(
        GL_TEXTURE_CUBE_MAP,
        _cubemap);

    glDrawArrays(
        GL_TRIANGLES,
        0,
        36);

    glBindVertexArray(0);

    glDepthFunc(GL_LESS);
}