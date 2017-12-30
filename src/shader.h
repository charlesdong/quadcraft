#ifndef SHADER_H_
#define SHADER_H_

#include <GL/glew.h>
#include "vec2.h"

// Shader program class.
class Shader
{
private:
	GLuint id;
	
	// a constant representing the program type
	// can have any value different from GL_VERTEX_SHADER and GL_FRAGMENT_SHADER
	// NOTE: the constant must be defined as **static**, or the copy assignment function
	// would be deleted
	static const GLenum PROGRAM = 0;
	
	GLuint loadShader(const char * code, GLenum type) const;
	void loadProgram(GLuint vShader, GLuint fShader);
	bool checkErrors(GLuint vid, GLenum type) const;
	void outputInfoLog(GLuint vid, GLenum type) const;
	const char * getTypeName(GLenum type) const;

	GLint getLoc(const char * name) const
	{
		return glGetUniformLocation(id, name);
	}
	
public:
	Shader();
	~Shader();
	
	void load(const char * vCode, const char * fCode);

	void use() const
	{
		glUseProgram(id);
	}

	void clear() const
	{
		glDeleteShader(id);
	}

	// FIXME: uniform setting functions should be static

	void seti(const char * name, int value) const
	{
		glUniform1i(getLoc(name), value);
	}

	void setf(const char * name, float value) const
	{
		glUniform1f(getLoc(name), value);
	}

	void set2f(const char * name, float v1, float v2) const
	{
		glUniform2f(getLoc(name), v1, v2);
	}

	void set3f(const char * name, float v1, float v2, float v3) const
	{
		glUniform3f(getLoc(name), v1, v2, v3);
	}

	void set4f(const char * name, float v1, float v2, float v3, float v4) const
	{
		glUniform4f(getLoc(name), v1, v2, v3, v4);
	}

	void setmat4f(const char * name, Mat4fr m) const
	{
		glUniformMatrix4fv(getLoc(name), 1, GL_FALSE, m.pointer());
	}
};

#endif