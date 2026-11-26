#version 450 core

layout(location = 0) in vec3 aPosition;
layout(location = 1) in vec2 aTexCoord;
layout(location = 2) in vec3 aNormal;

out VS_OUT
{
    vec2 TexCoord;
    vec3 WorldPos;
} vs_out;

uniform mat4 u_Model;
uniform mat4 u_View;
uniform mat4 u_Projection;

void main()
{
    vec4 worldPos = u_Model * vec4(aPosition, 1.0);

    vs_out.WorldPos = worldPos.xyz;

    vs_out.TexCoord = aTexCoord;

    gl_Position = u_Projection * u_View *worldPos;
}