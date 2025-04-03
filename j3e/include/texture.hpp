#pragma once

#include <glad/glad.h>

namespace j3e{
struct Texture{
	unsigned int id;
	const char* path;

	void Bind();
	void Unbind();
	void Delete();

	Texture(GLenum texture_type, const char* img_path);
	Texture();
};
}
