#version 450 core

layout(location = 0) in vec3 WorldPos;
layout(location = 1) in vec3 WorldNormal;
layout(location = 2) in vec2 TexCoords;

out vec4 FragColor;

uniform vec3 u_CameraPos;

uniform sampler2D u_Texture;

void main()
{
    vec3 N = normalize(WorldNormal);
    vec3 V = normalize(u_CameraPos - WorldPos);

    vec3 waterColour = texture(u_Texture, TexCoords).rgb;

    float pigment = 1.0 - max(dot(N, V), 0.0);
    waterColour *= 1.0 + pigment * 0.35;

    vec2 distortion = (waterColour.rg - 0.5) * 0.02;
    vec3 paint = texture(u_Texture, TexCoords + distortion).rgb;

    vec3 finalColour = paint;

    FragColor = vec4(paint, 1.0);
}