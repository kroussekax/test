#pragma once

#include <vector>
#include <memory>

#include "shader.hpp"
#include "mesh.hpp"

#define DEFAULT_IMG_PATH "res/img/brick.jpg"

namespace j3e{
struct Level{
	char* lvl_name;
	std::vector<std::unique_ptr<Mesh>> meshes; /* prolly gonna be changed after adding assimp support to load models */
	Shader mesh_shader;

	void Draw();

	Level(char* lvl_name, Shader mesh_shader):lvl_name{lvl_name}, mesh_shader{mesh_shader}{};
	Level();
};
}
