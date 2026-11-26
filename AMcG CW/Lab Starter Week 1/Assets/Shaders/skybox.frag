#version 450 core

in vec3 TexCoords;

out vec4 FragColor;

uniform float u_time;

uniform samplerCube u_EnvironmentMap;

void main()
{
    vec3 dir = normalize(TexCoords);

    dir.x += sin(u_time * 0.05) * 0.05;
    dir.y += cos(u_time * 0.04) * 0.05;
    

    vec3 colour = texture(u_EnvironmentMap, dir).rgb;
    colour = floor(colour * 8.0) / 8.0;
    colour = pow(colour, vec3(0.9));

    float brightness = dot(colour, vec3(0.299, 0.587, 0.114));

    colour += brightness * 0.08;

    float pigment = pow(1.0 - abs(dir.y), 2.0);

    colour *= 1.0 + pigment * 0.10;
    colour = mix(colour, vec3(colour.r, colour.g * 0.95, colour.b * 1.05), 0.15);

    FragColor = vec4(colour, 1.0);
}