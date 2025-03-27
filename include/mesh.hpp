#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>

#include "shader.hpp"
#include "texture.hpp"

class Mesh {
private:
	unsigned int VAO, VBO, EBO;

	Shader shader;
	Texture texture;

	unsigned int model_loc;
	unsigned int view_loc;
	unsigned int projection_loc;
	glm::vec3 pos;

	void linkAttrib(GLuint layout, GLuint numComponents, GLenum type, GLsizeiptr stride, void* offset);

	void bind_vao(){ glBindVertexArray(VAO); }
	void unbind_vao(){ glBindVertexArray(0); }

	void bind_vbo(){ glBindBuffer(GL_ARRAY_BUFFER, VBO); }
	void unbind_vbo(){ glBindBuffer(GL_ARRAY_BUFFER, VBO); }

	void bind_ebo(){ glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO); }
	void unbind_ebo(){ glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO); }
public:
	void Draw();

	Mesh(const float* vertices, const unsigned int* indices,
		const char* vertex_shader_path="res/shaders/vertexshaders.glsl",
		const char* fragment_shader_path= "res/shaders/fragmentshaders.glsl");
	Mesh();
	~Mesh();
};
