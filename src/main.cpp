#include <iostream>
#include <memory>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <vector>

#include "global_var.hpp"
#include "mesh.hpp"
#include "window.hpp"

#define DEBUG_MODE

void framebuffer_size_callback(GLFWwindow* window, int width, int height);

float getDeltaTime(float& last_time);

int main(){
	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	Window window("j3c engine", 1280, 720);

	gladLoadGL();

	window.set_frame_buffer_size_callback(framebuffer_size_callback);

	std::vector<float> vertices = {
		// positions         // texture coords
		0.5f,  0.5f, 0.0f,   1.0f, 1.0f,   // top right
		0.5f, -0.5f, 0.0f,   1.0f, 0.0f,   // bottom right
		-0.5f, -0.5f, 0.0f,  0.0f, 0.0f,   // bottom left
		-0.5f,  0.5f, 0.0f,  0.0f, 1.0f    // top left
	};

	std::vector<unsigned int> indices = {
		0, 1, 3,   // first triangle
		1, 2, 3    // second triangle
	};


	view = glm::mat4(1.0f);
	view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));

	projection = glm::perspective(glm::radians(45.0f), 800.0f / 800.0f, 0.1f, 100.0f);

	glViewport(0, 0, 1280, 720);

	std::unique_ptr<Mesh> mesh = std::make_unique<Mesh>(Mesh(vertices, indices, "res/shaders/vertexshaders.glsl", "res/shaders/fragmentshaders.glsl"));

	float last_time = 0.0f;

	while(!window.should_close()){
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		window.input(getDeltaTime(last_time));

		mesh->Draw();

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

float getDeltaTime(float& last_time){
	// Get current time
	float currentTime = static_cast<float>(glfwGetTime());

	// Calculate delta time
	float deltaTime = currentTime - last_time;

	// Update last time to current time
	last_time = currentTime;

	return deltaTime;
}
