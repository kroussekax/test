#pragma once

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>

namespace j3e{
inline glm::mat4 view;
inline glm::mat4 projection;
inline float last_time = 0.0f;
inline float MovementSpeed;
inline bool cam_should_move = true;

float getDeltaTime(float& last_time);

void linkAttrib(unsigned int& vbo, GLuint layout, GLuint numComponents, GLenum type, GLsizeiptr stride, void* offset);
}
