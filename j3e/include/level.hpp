#pragma once

#include <vector>
#include <memory>

#include "shader.hpp"
#include "mesh.hpp"

#define DEFAULT_IMG_PATH "res/img/brick.jpg"

namespace j3e{
class Level{
private:
	char* lvl_name;

	Shader mesh_shader;
	Shader highlight_shader;

	std::vector<float> default_vertices;
	std::vector<unsigned int> default_indices;

	std::unique_ptr<Mesh> highlight_mesh; /* optimize this shit yo */
	std::vector<std::unique_ptr<Mesh>> meshes; /* prolly gonna be changed after adding assimp support to load models */
	int current_mesh;
public:
	// glm::vec3 pos, std::vector<float> vertices, std::vector<unsigned int> indices, const char* img_path
	void add_mesh(glm::vec3 pos, std::vector<float> vertices, std::vector<unsigned int> indices, const char* img_path){
		meshes.push_back(std::make_unique<Mesh>(vertices, indices, pos, img_path));
	}

	void add_mesh(glm::vec3 pos, const char* img_path=DEFAULT_IMG_PATH){
		meshes.push_back(std::make_unique<Mesh>(default_vertices, default_indices, pos, img_path));
	}

	void add_mesh(){
		if(meshes.size() > 0)
			meshes.push_back(std::make_unique<Mesh>(default_vertices, default_indices, meshes[current_mesh]->get_position(), DEFAULT_IMG_PATH));
		else
			meshes.push_back(std::make_unique<Mesh>(default_vertices, default_indices, glm::vec3(1.0f, 0.0f, .0f), DEFAULT_IMG_PATH));
	}

	void load();
	void save();

	void Draw();
	void Draw_UI();

	Level(char* lvl_name, std::vector<float> vertices, std::vector<unsigned int> indices); /* vertices and indices here are for the first/default mesh*/
	Level();
};
}
