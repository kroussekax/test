#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

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

	void input(float dt);

	Window(const char* window_title, int width, int height);
	Window();
};
