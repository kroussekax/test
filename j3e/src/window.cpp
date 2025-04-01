#include "window.hpp"

#include <iostream>

#include <glm/ext/matrix_transform.hpp>

#include "globals.hpp"
#include "input_manager.hpp"

namespace j3e{
void Window::input(float dt, Camera& camera){
	InputManager::Update(window);

	if(InputManager::IsKeyPressed(GLFW_KEY_CAPS_LOCK)){
		if(glfwGetInputMode(window, GLFW_CURSOR) == GLFW_CURSOR_DISABLED)
			glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
		else
			glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
		cam_should_move = !cam_should_move;
	}

	custom_input_impl(dt, camera, this);
}

Window::Window(const char* window_title, int width, int height){
	window = glfwCreateWindow(width, height, window_title, NULL, NULL);
	if(window == NULL){
		std::cerr<<"failed to create a glfw window."<<std::endl;
		glfwTerminate();
	}
	glfwMakeContextCurrent(window);
	glfwSwapInterval(1); // 1 = Enable V-Sync, 0 = Disable

	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	switch_mouse_mode = false;
}

Window::Window(){
}
}
