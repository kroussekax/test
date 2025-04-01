#include "globals.hpp"

namespace j3e{
float getDeltaTime(float &last_time){
	// Get current time
	float currentTime = static_cast<float>(glfwGetTime());

	// Calculate delta time
	float deltaTime = currentTime - last_time;

	// Update last time to current time
	last_time = currentTime;

	return deltaTime;
}

void linkAttrib(unsigned int& vbo, GLuint layout, GLuint numComponents, GLenum type, GLsizeiptr stride, void* offset){
	glBindBuffer(GL_ARRAY_BUFFER, vbo);

	glVertexAttribPointer(layout, numComponents, type, GL_FALSE, stride, offset);
	glEnableVertexAttribArray(layout);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
}
}
