#version 450 core

in vec2 TexCoord;
in vec3 WorldPos;
in vec3 WorldNormal;

out vec4 FragColor;

uniform vec3 u_CameraPos;

uniform sampler2D u_Texture;

void main()
{
    vec3 N = normalize(WorldNormal);
    vec3 V = normalize(u_CameraPos - WorldPos);

    vec3 waterColour = texture(u_Texture, TexCoord).rgb;

    float pigment = 1.0 - max(dot(N, V), 0.0);
    waterColour *= 1.0 + pigment * 0.60;

    vec2 distortion = (waterColour.rg - 0.5) * 0.02;
    vec3 paint = texture(u_Texture, TexCoord + distortion).rgb;
    paint = mix(paint, waterColour, 0.35);

    FragColor = vec4(paint, 1.0);
}