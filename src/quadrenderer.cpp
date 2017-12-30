#include "quadrenderer.h"
#include "resourcemanager.h"
#include <GL/glew.h>

int QuadRenderer::shaderNo;
GLuint QuadRenderer::vao;
GLuint QuadRenderer::ebo;
int QuadRenderer::textureNo;
Vec2f QuadRenderer::size;

void QuadRenderer::init()
{
	int shaderNo = ResourceManager::loadShader("shaders/shader.vert", "shaders/shader.frag");
	
	GLfloat vertexes[] =
	{
		0.0f, 0.0f,		// left bottom
		1.0f, 0.0f,		// right bottom
		1.0f, 0.0f,		// right top
		0.0f, 1.0f		// left top
	};
	GLuint indexes[] =
	{
		0, 1, 2,
		0, 2, 3
	};
	GLuint vbo;

	glGenVertexArrays(1, &vao);
	glGenBuffers(1, &vbo);
	glGenBuffers(1, &ebo);

	glBindVertexArray(vao);

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexes), vertexes, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indexes), indexes, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), (void *)0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	Mat4f proj = ortho(800, 600);
	GETSHADER(shaderNo).use();
	GETSHADER(shaderNo).setmat4f("proj", proj);
}

void QuadRenderer::render(Vec2fr position)
{
	Mat4f model;
	model = translate(model, position);
	model = scale(model, size);
	GETSHADER(shaderNo).use();
	GETSHADER(shaderNo).setmat4f("model", model);

	GETTEXTURE(textureNo).bind();	// FIXME: only rebind texture when texture changed

	glBindVertexArray(vao);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
	glBindVertexArray(0);
}