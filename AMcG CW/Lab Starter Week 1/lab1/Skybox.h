#pragma once

#include <memory>

class Shader;
class Camera;
class EnvironmentMap;

class Skybox
{
public:

    Skybox(std::shared_ptr<EnvironmentMap> environment);

    ~Skybox();

    void Draw(const Camera& camera);

private:

    std::shared_ptr<EnvironmentMap> _environment;

    std::shared_ptr<Shader> _shader;

    unsigned int _vao = 0;
    unsigned int _vbo = 0;
};