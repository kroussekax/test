#pragma once

#include <glad/glad.h>

namespace j3e{
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
}
