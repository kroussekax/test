#pragma once

#include <glad/glad.h>

class Texture{
private:
	unsigned int id;
public:

	void Bind();
	void Unbind();
	void Delete();

	Texture(GLenum texture_type, const char* img_path);
	Texture();
};
