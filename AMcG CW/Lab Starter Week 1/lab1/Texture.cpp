#include "Texture.h"

// handles image loading and creaitng textures

Texture::Texture(const std::string& filepath)
{
    int width;
    int height;
    int channels;

    unsigned char* data =
        stbi_load(
            filepath.c_str(),
            &width,
            &height,
            &channels,
            STBI_rgb_alpha);

    if (!data)
    {
        std::cerr
            << "Failed to load texture: "
            << filepath
            << std::endl;

        return;
    }

    glGenTextures(1, &_id);

    glBindTexture(
        GL_TEXTURE_2D,
        _id);

    glTexImage2D(
        GL_TEXTURE_2D,
        0,
        GL_RGBA,
        width,
        height,
        0,
        GL_RGBA,
        GL_UNSIGNED_BYTE,
        data);

    glGenerateMipmap(GL_TEXTURE_2D);

    glTexParameteri(
        GL_TEXTURE_2D,
        GL_TEXTURE_MIN_FILTER,
        GL_LINEAR_MIPMAP_LINEAR);

    glTexParameteri(
        GL_TEXTURE_2D,
        GL_TEXTURE_MAG_FILTER,
        GL_LINEAR);

    stbi_image_free(data);

    glBindTexture(
        GL_TEXTURE_2D,
        0);
}

Texture::~Texture()
{
    if (_id)
    {
        glDeleteTextures(1, &_id);
    }
}

void Texture::Bind(unsigned int slot) const
{
    glActiveTexture(
        GL_TEXTURE0 + slot);

    glBindTexture(
        GL_TEXTURE_2D,
        _id);
}