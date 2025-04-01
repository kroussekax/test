#include "mesh.hpp"

#include <GL/gl.h>
#include <GL/glext.h>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "globals.hpp"

namespace j3e{
void Mesh::Draw(Shader &shader){
	shader.use();
	glActiveTexture(GL_TEXTURE0);
	texture.Bind();
	glBindVertexArray(VAO);
	glm::mat4 model = glm::mat4(1.0f);
	model = glm::translate(model, pos);

	glUniformMatrix4fv(glGetUniformLocation(shader.get_id(), "model"), 1, GL_FALSE, glm::value_ptr(model));
	glUniformMatrix4fv(glGetUniformLocation(shader.get_id(), "view"), 1, GL_FALSE, glm::value_ptr(*global.view));
	glUniformMatrix4fv(glGetUniformLocation(shader.get_id(), "projection"), 1, GL_FALSE, glm::value_ptr(*global.projection));
	glDrawArrays(GL_TRIANGLES, 0, 36);
	//glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

Mesh::Mesh(std::vector<float> vertices, std::vector<unsigned int> indices, glm::vec3 pos, const char* texture_path){
	glEnable(GL_DEPTH_TEST);

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
	//linkAttrib(VBO, 2, 2, GL_FLOAT, 6 * sizeof(float), (void*)(3 * sizeof(float))); /* texture coord */

	glm::mat4 model = glm::mat4(1.0f);
	this->pos = pos;
	model = glm::translate(model, pos);

	texture = Texture(GL_TEXTURE_2D, texture_path);
}

Mesh::Mesh(){
}
}
