#pragma once

#include <vector>
#include <memory>

#include "shader.hpp"
#include "mesh.hpp"

class Level{
private:
	Shader mesh_shader;
	Shader highlight_shader;

	std::vector<float> default_verticecs;
	std::vector<unsigned int> default_indices;

	std::unique_ptr<Mesh> highlight_mesh; /* optimize this shit yo */
	std::vector<std::unique_ptr<Mesh>> meshes; /* prolly gonna be changed after adding assimp support to load models */
	int current_mesh;
public:
	void add_mesh(std::vector<float> vertices, std::vector<unsigned int> indices){
		meshes.push_back(std::make_unique<Mesh>(vertices, indices, glm::vec3(1.0f, 0.0f, .0f), "res/img/brick.jpg"));
	}
	void add_mesh(){
		meshes.push_back(std::make_unique<Mesh>(default_verticecs, default_indices, glm::vec3(1.0f, 0.0f, .0f), "res/img/brick.jpg"));
	}

	void Draw();
	void Draw_UI();

	Level(std::vector<float> vertices, std::vector<unsigned int> indices); /* vertices and indices here are for the first/default mesh*/
};
