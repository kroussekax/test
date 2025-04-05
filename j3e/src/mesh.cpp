#include "mesh.hpp"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

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
}

void Mesh::update_height(){
	vertices[1] = height.x;
	vertices[6] = height.x;
	vertices[11] = height.y;
	vertices[16] = height.y;
	vertices[21] = height.y;
	vertices[26] = height.x;

	vertices[31] = height.x;
	vertices[36] = height.x;
	vertices[41] = height.y;
	vertices[46] = height.y;
	vertices[51] = height.y;
	vertices[56] = height.x;

	vertices[61] = height.y;
	vertices[66] = height.y;
	vertices[71] = height.x;
	vertices[76] = height.x;
	vertices[81] = height.x;
	vertices[86] = height.y;

	vertices[91] = height.y;
	vertices[96] = height.y;
	vertices[101] = height.x;
	vertices[106] = height.x;
	vertices[111] = height.x;
	vertices[116] = height.y;

	vertices[121] = height.x;
	vertices[126] = height.x;
	vertices[131] = height.x;
	vertices[136] = height.x;
	vertices[141] = height.x;
	vertices[146] = height.x;

	vertices[151] = height.y;
	vertices[156] = height.y;
	vertices[161] = height.y;
	vertices[166] = height.y;
	vertices[171] = height.y;
	vertices[176] = height.y;


	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}
void Mesh::update_sides(){
	vertices[0] = sides.y;
	vertices[5] = sides.x;
	vertices[10] = sides.x;
	vertices[15] = sides.x;
	vertices[20] = sides.y;
	vertices[25] = sides.y;

	vertices[30] = sides.y;
	vertices[35] = sides.x;
	vertices[40] = sides.x;
	vertices[45] = sides.x;
	vertices[50] = sides.y;
	vertices[55] = sides.y;

	vertices[60] = sides.x;
	vertices[65] = sides.x;
	vertices[70] = sides.y;
	vertices[75] = sides.y;
	vertices[80] = sides.y;
	vertices[85] = sides.x;

	vertices[90] = sides.x;
	vertices[95] = sides.x;
	vertices[100] = sides.y;
	vertices[105] = sides.y;
	vertices[110] = sides.y;
	vertices[115] = sides.x;

	vertices[120] = sides.y;
	vertices[125] = sides.x;
	vertices[130] = sides.x;
	vertices[135] = sides.x;
	vertices[140] = sides.y;
	vertices[145] = sides.y;

	vertices[150] = sides.y;
	vertices[155] = sides.x;
	vertices[160] = sides.x;
	vertices[165] = sides.x;
	vertices[170] = sides.y;
	vertices[175] = sides.y;

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

Mesh::Mesh(glm::vec2 sides, glm::vec2 height, std::vector<float> vertices, std::vector<unsigned int> indices, glm::vec3 pos, const char* texture_path, int idx):idx{idx}{
	this->height = height;
	this->sides = sides;
	this->vertices = vertices;
	this->indices = indices;

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

	update_height();

	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

Mesh::Mesh(){
}
}
