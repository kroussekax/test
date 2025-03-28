#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "camera.hpp"

class Window{
private:
	GLFWwindow* window;

public:

	bool should_close() const{
		return glfwWindowShouldClose(window);
	}

	void swap_buffers() const{
		glfwSwapBuffers(window);
	}

	void set_frame_buffer_size_callback(void(*callback)(GLFWwindow*, int, int)) const{
		glfwSetFramebufferSizeCallback(window, callback);
	}
	void set_mouse_callback(void(*callback)(GLFWwindow*, double, double)) const{
		glfwSetCursorPosCallback(window, callback);
	}
	void set_scroll_callback(void(*callback)(GLFWwindow*, double, double)) const{
		glfwSetScrollCallback(window, callback);
	}

	void input(float dt, Camera& camera);

	Window(const char* window_title, int width, int height);
	Window();
};
