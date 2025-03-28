#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>

#include "camera.hpp"

inline glm::mat4 view;
inline glm::mat4 projection;
inline Camera camera(glm::vec3(0.0f, 0.0f, 3.0f));

float getDeltaTime(float& last_time);

void linkAttrib(unsigned int& vbo, GLuint layout, GLuint numComponents, GLenum type, GLsizeiptr stride, void* offset);
