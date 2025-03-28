#include "window.hpp"

#include <iostream>

#include <glm/ext/matrix_transform.hpp>

#include "globals.hpp"

void Window::input(float dt){
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);

	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		camera.ProcessKeyboard(FORWARD, dt);
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		camera.ProcessKeyboard(BACKWARD, dt);
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		camera.ProcessKeyboard(LEFT, dt);
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		camera.ProcessKeyboard(RIGHT, dt);
}

Window::Window(const char* window_title, int width, int height){
	window = glfwCreateWindow(width, height, window_title, NULL, NULL);
	if(window == NULL){
		std::cerr<<"failed to create a glfw window."<<std::endl;
		glfwTerminate();
	}
	glfwMakeContextCurrent(window);

	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
}

Window::Window(){
}
