#include "globals.hpp"

#include <iostream>
#include <fstream>

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

std::string readFile(std::string filename){
	std::ifstream in(filename, std::ios::binary);
	if (in)
	{
		std::string contents;
		in.seekg(0, std::ios::end);
		contents.resize(in.tellg());
		in.seekg(0, std::ios::beg);
		in.read(&contents[0], contents.size());
		in.close();
		return(contents);
	}
	throw(errno);
}

}
