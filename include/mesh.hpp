#pragma once

#include <vector>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>

#include "shader.hpp"
#include "texture.hpp"

class Mesh {
private:
	unsigned int VBO, VAO, EBO;
	Texture texture;

	unsigned int model_loc;
	unsigned int view_loc;
	unsigned int projection_loc;
	glm::vec3 pos;

	//void linkAttrib(GLuint layout, GLuint numComponents, GLenum type, GLsizeiptr stride, void* offset);

public:
	glm::vec3& get_position(){
		return pos;
	}

	void Draw(Shader &shader);

	Mesh(std::vector<float> vertices, std::vector<unsigned int> indices, glm::vec3 pos, const char* texture_path);
	Mesh();
	~Mesh();
};
