#pragma once

#include <glad/glad.h>
#include <map>
#include <string>

// difuse => colors
// spec = lights
// normals = depths

namespace j3e{
enum class TexType{
	Diffuse,
	Specular
};

inline std::map<TexType, std::string> TexType_to_string = {
	{TexType::Diffuse, "Diffuse"},
	{TexType::Specular, "Specular"},
};

struct Texture{
	unsigned int id;
	const char* path;
	TexType tex_type;

	void Bind();
	void Unbind();
	void Delete();

	Texture(GLenum texture_type, const char* img_path, TexType tex_type);
};
}
