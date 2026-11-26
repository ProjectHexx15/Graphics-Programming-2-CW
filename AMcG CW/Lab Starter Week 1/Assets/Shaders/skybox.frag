#version 450 core

in vec3 TexCoords;

out vec4 FragColor;

uniform samplerCube u_EnvironmentMap;

void main()
{
    FragColor = texture(u_EnvironmentMap, normalize(TexCoords));
}