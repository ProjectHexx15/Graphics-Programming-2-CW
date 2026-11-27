#version 450 core

layout(triangles) in;
layout(triangle_strip, max_vertices = 3) out;

in VS_OUT
{
    vec2 TexCoord;
    vec3 WorldPos;
    vec3 WorldNormal;
}
gs_in[];

out vec2 TexCoord;
out vec3 WorldPos;
out vec3 WorldNormal;

uniform float u_ExplosionAmount;

uniform vec3 u_ObjectCenter;

uniform mat4 u_View;
uniform mat4 u_Projection;

vec3 GetDirection()
{
    vec3 center = (gs_in[0].WorldPos + gs_in[1].WorldPos + gs_in[2].WorldPos) / 3.0;
    return normalize(center - u_ObjectCenter);
}

void main()
{
    vec3 direction = GetDirection();

    vec3 offset = direction * u_ExplosionAmount;

    float angle = u_ExplosionAmount * 2.0;

    float c = cos(angle);
    float s = sin(angle);

    mat2 rot = mat2(c, -s, s, c);

    offset.xz = rot * offset.xz;

    for(int i = 0; i < 3; i++)
    {
        vec3 movedPos = gs_in[i].WorldPos + offset;
        TexCoord = gs_in[i].TexCoord;
        WorldPos = movedPos;
        WorldNormal = gs_in[i].WorldNormal;
        gl_Position = u_Projection * u_View * vec4(movedPos, 1.0);
        EmitVertex();
    }

    EndPrimitive();
}