#include "window.hpp"

#include <iostream>

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
