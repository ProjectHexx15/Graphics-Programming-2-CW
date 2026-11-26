#version 450 core

layout(triangles) in;
layout(triangle_strip, max_vertices = 3) out;

in VS_OUT
{
	vec2 TexCoord;
} gs_in[];

out vec2 TexCoord;

uniform float u_ExplosionAmount;

vec3 GetDirection()
{
	vec3 center = (gl_in[0].gl_Position.xyz + gl_in[1].gl_Position.xyz + gl_in[2].gl_Position.xyz) / 3.0;
	return normalize(center);
}

void main()
{
	vec3 direction = GetDirection();

	vec3 offset = direction * u_ExplosionAmount;

	TexCoord = gs_in[0].TexCoord;
	gl_Position = gl_in[0].gl_Position + vec4(offset, 0.0);
	EmitVertex();

	TexCoord = gs_in[1].TexCoord;
	gl_Position = gl_in[1].gl_Position + vec4(offset, 0.0);
	EmitVertex();

	TexCoord = gs_in[2].TexCoord;
	gl_Position = gl_in[2].gl_Position + vec4(offset, 0.0);
	EmitVertex();

	EndPrimitive();

}