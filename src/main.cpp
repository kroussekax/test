#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "window.hpp"

#define DEBUG_MODE

void framebuffer_size_callback(GLFWwindow* window, int width, int height);

int main(){

	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	Window window("j3c engine", 1280, 720);

	gladLoadGL();
	glViewport(0, 0, 1280, 720);

	window.set_frame_buffer_size_callback(framebuffer_size_callback);

	while(!window.should_close()){
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		window.swap_buffers();
		glfwPollEvents();
	}

	return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height){
	glViewport(0, 0, width, height);
#ifdef DEBUG_MODE
	std::cout<<"Window Resized: "<<width<<", "<<height<<std::endl;
#endif
}
