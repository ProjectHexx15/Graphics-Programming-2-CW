#include <memory>
#include <vector>
#include <string>

#include <GL/glew.h>

class Shader;
class Camera;

class Skybox
{
public:

    Skybox(
        const std::vector<std::string>& faces);

    ~Skybox();

    void Draw(
        const Camera& camera);

private:

    GLuint _vao;
    GLuint _vbo;

    GLuint _cubemap;

    std::shared_ptr<Shader> _shader;

    GLuint LoadCubemap(
        const std::vector<std::string>& faces);
};