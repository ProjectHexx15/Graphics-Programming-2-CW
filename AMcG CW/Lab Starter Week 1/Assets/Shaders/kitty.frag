#version 450 core

layout(location = 0) in vec3 WorldPos;
layout(location = 1) in vec3 WorldNormal;
layout(location = 2) in vec2 TexCoords;

out vec4 FragColor;

uniform sampler2D u_Texture;
uniform vec3 u_CameraPos;

void main()
{
	vec3 N = normalize(WorldNormal);
	vec3 V = normalize(u_CameraPos - WorldPos);
	vec3 L = normalize(vec3(1.0, 1.0, 1.0));

	float lighting =max(dot(N, L), 0.0);

	if(lighting > 0.75)
    {
        lighting = 1.0;
    }
    else if(lighting > 0.45)
    {
        lighting = 0.70;
    }
    else
    {
        lighting = 0.35;
    }

    vec3 colour = texture(u_Texture, TexCoords).rgb;
    colour *= lighting;

	float rim = 1.0 - max(dot(N, V), 0.0);
	rim = pow(rim, 3.0);

	vec3 rimColour = vec3(1.0, 0.9, 1.0);
    colour += rimColour * rim * 0.35;

	FragColor = vec4(colour, 1.0);

}