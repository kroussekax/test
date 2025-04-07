#version 330 core

out vec4 FragColor;

in vec2 TexCoord;

uniform sampler2D Diffuse1;

void main()
{
    FragColor = texture(Diffuse1, TexCoord);
}
