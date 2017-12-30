#ifndef QUAD_RENDERER_H_
#define QUAD_RENDERER_H_

#include "vec2.h"
#include "shader.h"
#include <GL/glew.h>

class QuadRenderer
{
private:
	static int shaderNo;
	static GLuint vao;
	static GLuint ebo;
	static int textureNo;
	static Vec2f size;
public:
	static void init();

	static void setTexture(int index)
	{
		textureNo = index;
	}

	static void setSize(Vec2fr s)
	{
		size = s;
	}

	static void setSize(float x, float y)
	{
		setSize(Vec2f(x, y));
	}

	static void render(Vec2fr position);

	static void render(float x, float y)
	{
		render(Vec2f(x, y));
	}
};

#endif