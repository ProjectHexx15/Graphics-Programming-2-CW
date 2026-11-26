#version 450 core

layout(location = 0) in vec3 aPosition;
layout(location = 1) in vec2 aTexCoord;
layout(location = 2) in vec3 aNormal;

layout(location = 0) out vec3 WorldPos;
layout(location = 1) out vec3 WorldNormal;
layout(location = 2) out vec2 TexCoords;

uniform mat4 u_Model;
uniform mat4 u_View;
uniform mat4 u_Projection;

void main()
{
    vec4 worldPos = u_Model * vec4(aPosition, 1.0);
    WorldPos = worldPos.xyz;

    WorldNormal = mat3(transpose(inverse(u_Model))) * aNormal;
    TexCoords = aTexCoord;
    gl_Position = u_Projection * u_View * worldPos;
}