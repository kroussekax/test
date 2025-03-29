#pragma once

#include "imgui_impl_glfw.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "camera.hpp"

class Window{
private:
	bool switch_mouse_mode;
	bool key_released;
	GLFWwindow* window;
	void (*custom_input_impl)(float, Camera&, Window*);
public:

	bool should_close() const{
		return glfwWindowShouldClose(window);
	}

	bool check_key(int key){
		return glfwGetKey(window, key);
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

	void set_input_impl(void(*impl)(float dt, Camera& camera, Window* window)){
		custom_input_impl = impl;
	}

	void impl_imgui(){
		ImGui_ImplGlfw_InitForOpenGL(window, true);
	}

	void input(float dt, Camera& camera);

	Window(const char* window_title, int width, int height);
	Window();
};
