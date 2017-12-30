#version 330 core

layout (location = 0) in vec4 position;

out vec2 texCoord;

uniform mat4 model;
uniform mat4 proj;

void main()
{
	gl_Position = proj * model * position;
	texCoord = position.xy;
}