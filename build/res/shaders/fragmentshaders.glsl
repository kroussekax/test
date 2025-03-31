#version 330 core

out vec4 FragColor;

in vec2 TexCoord;

uniform sampler2D ourTexture;
uniform float millis;

varying vec2 pos;

void main()
{
	vec4 tex = texture(ourTexture, TexCoord);

	float avg = (tex.r + tex.g + tex.b) / 3.;

	FragColor = vec4(avg, avg, avg, 1.);

}
