#version 330 core

out vec4 FragColor;

in vec2 TexCoord;

uniform sampler2D ourTexture;

varying vec2 pos;

void main()
{
	FragColor = vec4(pos.x, 0., 1., 1.);
}
