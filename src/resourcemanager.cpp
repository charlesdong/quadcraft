#include "resourcemanager.h"
#include "file.h"
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

std::vector<Shader> ResourceManager::shaders;
std::vector<Texture> ResourceManager::textures;

void ResourceManager::init()
{
}

void ResourceManager::clear()
{
	for (Shader s : shaders)
		s.clear();
	for (Texture t : textures)
		t.clear();
}

int ResourceManager::loadShader(const char * vFile, const char * fFile)
{
	const char * vSource = readFile(vFile);
	const char * fSource = readFile(fFile);
	Shader s;
	s.load(vSource, fSource);
	shaders.push_back(s);
	return shaders.size() - 1;
}

int ResourceManager::loadTexture(const char * filename)
{
	int width, height;
	unsigned char * image = stbi_load(filename, &width, &height, nullptr, 0);
	Texture t;
	t.load(image, width, height);
	textures.push_back(t);
	return textures.size() - 1;
}