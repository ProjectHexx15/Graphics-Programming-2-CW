#version 450 core

layout(location = 0) in vec3 WorldPos;
layout(location = 1) in vec3 WorldNormal;
layout(location = 2) in vec2 TexCoords;

out vec4 FragColor;

uniform vec3 u_CameraPos;

uniform float u_Time;

uniform sampler2D u_Texture;
uniform samplerCube u_EnvironmentMap;

void main()
{
    vec3 N = normalize(WorldNormal);
    vec3 V = normalize(u_CameraPos - WorldPos);

    vec3 reflectionDir = reflect(-V, N);
    vec3 reflection = texture(u_EnvironmentMap, reflectionDir).rgb;

    vec3 refractionDir = refract(-V, N, 1.0 / 1.15);
    vec3 refraction = texture(u_EnvironmentMap, refractionDir).rgb;

    float fresnel = pow(1.0 - max(dot(N, V), 0.0), 5.0);

    vec3 waterColour = texture(u_Texture, TexCoords).rgb;

    float pigment = 1.0 - max(dot(N, V), 0.0);
    waterColour *= 1.0 + pigment * 0.35;

    vec2 distortion = (waterColour.rg - 0.5) * 0.02;
    vec3 paint = texture(u_Texture, TexCoords + distortion).rgb;

    vec3 glass = mix(refraction, reflection, fresnel);

    float angle = dot(N, V) + u_Time * 0.15;
    vec3 iridescence = vec3(0.5 + 0.5 * sin(angle * 15.0), 0.5 + 0.5 * sin(angle * 15.0 + 2.0), 0.5 + 0.5 * sin(angle * 15.0 + 4.0));

    vec3 crystalTint = vec3(1.0, 0.9, 0.95);

    vec3 finalColour = glass;

    finalColour *= paint;

    finalColour *= crystalTint;

    finalColour *= mix(vec3(1.0), iridescence, 0.35);

    float alpha = mix(0.65, 0.095, fresnel);
    FragColor = vec4(finalColour, alpha);

}