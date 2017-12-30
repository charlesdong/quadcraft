#ifndef RESOURCE_MANAGER_H_
#define RESOURCE_MANAGER_H_

#include "shader.h"
#include "texture.h"
#include <vector>

// The resource manager class. Manages all shaders and textures.
class ResourceManager
{
private:
	static std::vector<Shader> shaders;
	static std::vector<Texture> textures;
public:
	static void init();
	static void clear();
	static int loadShader(const char * vFile, const char * fFile);
	static int loadTexture(const char * filename);

	static Shader & getShader(int index)
	{
		return shaders[index];
	}

	static Texture & getTexture(int index)
	{
		return textures[index];
	}
};

// Macrons to reduce the length of code.
#define GETSHADER(index) (ResourceManager::getShader((index)))
#define GETTEXTURE(index) (ResourceManager::getTexture((index)))

#endif