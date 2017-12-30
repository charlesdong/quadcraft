#ifndef TEXTURE_H_
#define TEXTURE_H_

#include <GL/glew.h>

// Texture class.
class Texture
{
private:
	GLuint id;
public:
	Texture();
	~Texture();

	void load(const unsigned char * image, int width, int height);

	void clear()
	{
		glDeleteTextures(1, &id);
	}

	void bind()
	{
		glBindTexture(GL_TEXTURE_2D, id);
	}

	void unbind()	// maybe should be static, because it will always do the same thing, regardless of the texture ID
	{
		glBindTexture(GL_TEXTURE_2D, 0);
	}
};

#endif