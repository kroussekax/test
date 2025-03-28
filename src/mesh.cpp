#include "mesh.hpp"

#include <GL/gl.h>
#include <GL/glext.h>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "globals.hpp"

void Mesh::Draw(){
	shader.use();
	glActiveTexture(GL_TEXTURE0);
	texture.Bind();
	glBindVertexArray(1);
	glm::mat4 model = glm::mat4(1.0f);
	model = glm::translate(model, pos);

	glUniformMatrix4fv(model_loc, 1, GL_FALSE, glm::value_ptr(model));
	glUniformMatrix4fv(view_loc, 1, GL_FALSE, glm::value_ptr(view));
	glUniformMatrix4fv(projection_loc, 1, GL_FALSE, glm::value_ptr(projection));
	glDrawArrays(GL_TRIANGLES, 0, 36);
	//glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

Mesh::Mesh(std::vector<float> vertices, std::vector<unsigned int> indices, const char* vertex_shader_path, const char* fragment_shader_path, glm::vec3 pos){
	glEnable(GL_DEPTH_TEST);

	shader = Shader(vertex_shader_path, fragment_shader_path);

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);
	// bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(float), indices.data(), GL_STATIC_DRAW);

	linkAttrib(VBO, 0, 3, GL_FLOAT, 5 * sizeof(float), (void*)0); /* coord */
	linkAttrib(VBO, 1, 2, GL_FLOAT, 5 * sizeof(float), (void*)(3 * sizeof(float))); /* texture coord */

	model_loc = glGetUniformLocation(shader.get_id(), "model");
	view_loc = glGetUniformLocation(shader.get_id(), "view");
	projection_loc = glGetUniformLocation(shader.get_id(), "projection");

	glm::mat4 model = glm::mat4(1.0f);
	this->pos = pos;
	model = glm::translate(model, pos);

	shader.use();
	texture = Texture(GL_TEXTURE_2D, "res/img/brick.jpg");
	glUniformMatrix4fv(model_loc, 1, GL_FALSE, glm::value_ptr(model));
	glUniformMatrix4fv(view_loc, 1, GL_FALSE, glm::value_ptr(view));
	glUniformMatrix4fv(projection_loc, 1, GL_FALSE, glm::value_ptr(projection));
}

Mesh::Mesh(){
}

Mesh::~Mesh(){
}
