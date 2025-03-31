#version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTex;

out vec2 TexCoord;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

varying vec2 pos;

void main()
{
	pos = aTex;
	vec4 position = vec4(aPos, 1.0);
	gl_Position = projection * view * model * position;
	TexCoord = aTex;
}
