#include "window.hpp"

#include <iostream>

#include <glm/ext/matrix_transform.hpp>

#include "global_var.hpp"

void Window::input(float dt){
    if(glfwGetKey(window, GLFW_KEY_RIGHT))
        view = glm::rotate(view, glm::radians(-55.0f * dt), glm::vec3(0.0f, 1.0f, 0.0f));
    if(glfwGetKey(window, GLFW_KEY_LEFT))
        view = glm::rotate(view, glm::radians(55.0f * dt), glm::vec3(0.0f, 1.0f, 0.0f));
    if(glfwGetKey(window, GLFW_KEY_UP))
        view = glm::rotate(view, glm::radians(55.0f * dt), glm::vec3(1.0f, 0.0f, 0.0f));
    if(glfwGetKey(window, GLFW_KEY_DOWN))
        view = glm::rotate(view, glm::radians(-55.0f * dt), glm::vec3(1.0f, 0.0f, 0.0f));

    if(glfwGetKey(window, GLFW_KEY_SPACE))
        view = glm::translate(view, glm::vec3(0.0f, -dt, 0.0f));
    if(glfwGetKey(window, GLFW_KEY_LEFT_SHIFT))
        view = glm::translate(view, glm::vec3(0.0f, dt, 0.0f));

    if(glfwGetKey(window, GLFW_KEY_W))
        view = glm::translate(view, glm::vec3(0.0f, 0.0f, dt));
    if(glfwGetKey(window, GLFW_KEY_A))
        view = glm::translate(view, glm::vec3(dt, 0.0f, 0.0f));
    if(glfwGetKey(window, GLFW_KEY_S))
        view = glm::translate(view, glm::vec3(0.0f, 0.0f, -dt));
    if(glfwGetKey(window, GLFW_KEY_D))
        view = glm::translate(view, glm::vec3(-dt, 0.0f, 0.0f));
}

Window::Window(const char* window_title, int width, int height){
	window = glfwCreateWindow(width, height, window_title, NULL, NULL);
	if(window == NULL){
		std::cerr<<"failed to create a glfw window."<<std::endl;
		glfwTerminate();
	}
	glfwMakeContextCurrent(window);
}

Window::Window(){
}
