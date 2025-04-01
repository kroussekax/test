#pragma once

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>

namespace j3e{
struct Globals{
	glm::mat4* view;
	glm::mat4* projection;
	float* last_time;
	float* MovementSpeed;
	bool* cam_should_move;
};

float getDeltaTime(float &last_time);
void linkAttrib(unsigned int& vbo, GLuint layout, GLuint numComponents, GLenum type, GLsizeiptr stride, void* offset);
}
inline j3e::Globals global;
