#version 330 core

out vec4 FragColor;

in vec2 TexCoord;

uniform sampler2D ourTexture;
uniform vec4 lightColor;

void main()
{
	float ambientStrength = 0.6;
	FragColor = texture(ourTexture, TexCoord) * lightColor * ambientStrength;
}
