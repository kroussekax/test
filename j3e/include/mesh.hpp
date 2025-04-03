#pragma once

#include <memory>
#include <vector>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>

#include "shader.hpp"
#include "texture.hpp"

namespace j3e{
class Mesh {
private:
	unsigned int VBO, VAO, EBO;
	Texture texture;

	unsigned int model_loc;
	unsigned int view_loc;
	unsigned int projection_loc;
	glm::vec3 pos;

	std::vector<float> vertices;
	std::vector<unsigned int> indices;
public:
	glm::vec2 height;

	void update_height();

	glm::vec3& get_position(){
		return pos;
	}

	void Draw(Shader &shader);

	std::unique_ptr<Mesh> clone() const {
		return std::make_unique<Mesh>(height, vertices, indices, pos, texture.path);
	}

	Mesh(glm::vec2 height, std::vector<float> vertices, std::vector<unsigned int> indices, glm::vec3 pos, const char* texture_path);
	Mesh();
};
}
