#include "shader.h"
#include <iostream>
#include <cstdlib>
using std::cout;
using std::cin;
using std::endl;

Shader::Shader() : id(0)
{
}

Shader::~Shader()
{
}

// Loads a shader from the given source code and type.
GLuint Shader::loadShader(const char * code, GLenum type) const
{
	GLuint shader = glCreateShader(type);
	glShaderSource(shader, 1, &code, nullptr);
	glCompileShader(shader);

	if (!checkErrors(shader, type))
	{
		outputInfoLog(shader, type);
		glDeleteShader(shader);
		exit(1);
	}

	return shader;
}

// Loads the shader program from vertex and fragment shader.
void Shader::loadProgram(GLuint vShader, GLuint fShader)
{
	id = glCreateProgram();
	glAttachShader(id, vShader);
	glAttachShader(id, fShader);
	glLinkProgram(id);

	if (!checkErrors(id, PROGRAM))
	{
		outputInfoLog(id, PROGRAM);
		glDeleteProgram(id);
		exit(1);
	}
}

bool Shader::checkErrors(GLuint vid, GLenum type) const
{
	GLint status;
	if (type != PROGRAM)
		glGetShaderiv(vid, GL_COMPILE_STATUS, &status);
	else
		glGetProgramiv(vid, GL_LINK_STATUS, &status);
	return status;
}

void Shader::outputInfoLog(GLuint vid, GLenum type) const
{
	int len;
	char * infoLog;
	if (vid != PROGRAM)
	{
		glGetShaderiv(vid, GL_INFO_LOG_LENGTH, &len);
		infoLog = new char[len + 1]{ '\0' };	// make sure the end of string is NUL
		glGetShaderInfoLog(vid, len + 1, nullptr, infoLog);
		cout << "ERROR: Shader compilation failed, type: " << getTypeName(type) << ", info log:\n" << infoLog;
	}
	else
	{
		glGetProgramiv(vid, GL_INFO_LOG_LENGTH, &len);
		infoLog = new char[len + 1]{ '\0' };
		glGetProgramInfoLog(vid, len + 1, nullptr, infoLog);
		cout << "ERROR: Program linking failed, info log:\n" << infoLog;
	}
	cin.get();
}

const char * Shader::getTypeName(GLenum type) const
{
	switch (type)
	{
	case GL_VERTEX_SHADER:
		return "vertex";
	case GL_FRAGMENT_SHADER:
		return "fragment";
	default:
		return "UNKNOWN";
	}
}

// Loads the shader program from shader code.
void Shader::load(const char * vCode, const char * fCode)
{
	GLuint vShader = loadShader(vCode, GL_VERTEX_SHADER);
	GLuint fShader = loadShader(fCode, GL_FRAGMENT_SHADER);
	loadProgram(vShader, fShader);
}