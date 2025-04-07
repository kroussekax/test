#pragma once

#include <vector>
#include <string>

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>

namespace j3e{
struct Chat{
	int y;
	const char* msg;
};

struct Globals{
	glm::mat4* view;
	glm::mat4* projection;
	float* last_time;
	float* MovementSpeed;
	bool* cam_should_move;
	std::vector<Chat>* chat_logs;
};

float getDeltaTime(float &last_time);
void linkAttrib(unsigned int& vbo, GLuint layout, GLuint numComponents, GLenum type, GLsizeiptr stride, void* offset);
void add_msg(const char* msg);
std::string readFile(std::string filename);
}
inline j3e::Globals global;
