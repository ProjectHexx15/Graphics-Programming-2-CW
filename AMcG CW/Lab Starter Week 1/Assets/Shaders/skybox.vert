#version 450 core

layout(location = 0) in vec3 aPosition;

out vec3 TexCoords;

uniform mat4 u_View;
uniform mat4 u_Projection;

void main()
{
    TexCoords = aPosition;

    vec4 pos = u_Projection * u_View * vec4(aPosition, 1.0);

    gl_Position = pos.xyww;
}