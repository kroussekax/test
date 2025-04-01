#pragma once

#include <vector>
#include <memory>

#include "shader.hpp"
#include "mesh.hpp"

namespace j3e{
class Level{
private:
	char* lvl_name;

	Shader mesh_shader;
	Shader highlight_shader;

	std::vector<float> default_verticecs;
	std::vector<unsigned int> default_indices;

	std::unique_ptr<Mesh> highlight_mesh; /* optimize this shit yo */
	std::vector<std::unique_ptr<Mesh>> meshes; /* prolly gonna be changed after adding assimp support to load models */
	int current_mesh;
public:
	void add_mesh(std::vector<float> vertices, std::vector<unsigned int> indices, glm::vec3 pos){
		meshes.push_back(std::make_unique<Mesh>(vertices, indices, pos, "res/img/brick.jpg"));
	}
	void add_mesh(std::vector<float> vertices, std::vector<unsigned int> indices){
		meshes.push_back(std::make_unique<Mesh>(vertices, indices, glm::vec3(1.0f, 0.0f, .0f), "res/img/brick.jpg"));
	}

	void add_mesh(glm::vec3 pos){
		meshes.push_back(std::make_unique<Mesh>(default_verticecs, default_indices, glm::vec3(1.0f, 0.0f, .0f), "res/img/brick.jpg"));
	}
	void add_mesh(){
		meshes.push_back(std::make_unique<Mesh>(default_verticecs, default_indices, glm::vec3(1.0f, 0.0f, .0f), "res/img/brick.jpg"));
	}

	void load();
	void save();

	void Draw();
	void Draw_UI();

	Level(char* lvl_name, std::vector<float> vertices, std::vector<unsigned int> indices); /* vertices and indices here are for the first/default mesh*/
};
}
