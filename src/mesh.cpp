#include "mesh.hpp"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "global_var.hpp"

void Mesh::linkAttrib(GLuint layout, GLuint numComponents, GLenum type, GLsizeiptr stride, void* offset){
	bind_vbo();
	glVertexAttribPointer(layout, numComponents, type, GL_FALSE, stride, offset);
	glEnableVertexAttribArray(layout);
	unbind_vbo();
}

void Mesh::Draw(){
	shader.use();
	glActiveTexture(GL_TEXTURE0);
	texture.Bind();
	bind_vao();
	glm::mat4 model = glm::mat4(1.0f);
	model = glm::translate(model, pos);

	glUniformMatrix4fv(model_loc, 1, GL_FALSE, glm::value_ptr(model));
	//glDrawArrays(GL_TRIANGLES, 0, 36);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

Mesh::Mesh(std::vector<float> vertices, std::vector<unsigned int> indices, const char* vertex_shader_path, const char* fragment_shader_path){
	glEnable(GL_DEPTH_TEST);

	shader = Shader(vertex_shader_path, fragment_shader_path);

	//VAO
	glGenVertexArrays(1, &VAO);
	bind_vao();

	//VBO
	glGenBuffers(1, &VBO);
	bind_vbo();
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);

	//EBO
	glGenBuffers(1, &EBO);
	bind_ebo();
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), indices.data(), GL_STATIC_DRAW);

	linkAttrib(0, 3, GL_FLOAT, 5 * sizeof(float), (void*)0); /* coord */
	linkAttrib(1, 2, GL_FLOAT, 5 * sizeof(float), (void*)(3 * sizeof(float))); /* texture coord */

	unbind_vao();
	unbind_vbo();
	unbind_ebo();

	texture = Texture(GL_TEXTURE_2D, "res/img/brick.jpg");

	model_loc = glGetUniformLocation(shader.get_id(), "model");
	view_loc = glGetUniformLocation(shader.get_id(), "view");
	projection_loc = glGetUniformLocation(shader.get_id(), "projection");

	glm::mat4 model = glm::mat4(1.0f);
	pos = glm::vec3(0.0f, 0.0f, 0.0f);
	model = glm::translate(model, pos);

	shader.use();
	glUniformMatrix4fv(model_loc, 1, GL_FALSE, glm::value_ptr(model));
	glUniformMatrix4fv(view_loc, 1, GL_FALSE, glm::value_ptr(view));
	glUniformMatrix4fv(projection_loc, 1, GL_FALSE, glm::value_ptr(projection));
}

Mesh::Mesh(){
}

Mesh::~Mesh(){
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
}
