#include <cstdio>
#include <iostream>
#include <ostream>
#include <string>
#include <vector>

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/fwd.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "globals.hpp"

#include "hama.hpp"
#include "window.hpp"
#include "input_manager.hpp"

#define DEBUG_MODE

//callbacks
static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
static void mouse_callback(GLFWwindow* window, double xpos, double ypos);
static void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);

void process_input(float dt, j3e::Camera& camera, j3e::Window* window);

j3e::Camera camera(glm::vec3(0.0f, 0.0f, 3.0f));
float lastX = 1000 / 2.0f;
float lastY = 1000 / 2.0f;
bool firstMouse = true;

int main(){
	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	j3e::Window window("j3c engine", 1600, 1000);

	gladLoadGL();

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	window.set_frame_buffer_size_callback(framebuffer_size_callback);
	window.set_mouse_callback(mouse_callback);
	window.set_scroll_callback(scroll_callback);

	float bottom_val = -0.5f;

	std::vector<float> vertices = {
		// !back
		-0.5f, bottom_val, -0.5f,  0.0f, 0.0f,
		0.5f, bottom_val, -0.5f,	  1.0f, 0.0f,
		0.5f,  0.5f, -0.5f,   1.0f, 1.0f,
		0.5f,  0.5f, -0.5f,   1.0f, 1.0f,
		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
		-0.5f, bottom_val, -0.5f,  0.0f, 0.0f,

		// !front
		-0.5f, bottom_val,  0.5f,  0.0f, 0.0f,
		0.5f, bottom_val,  0.5f,   1.0f, 0.0f,
		0.5f,  0.5f,  0.5f,   1.0f, 1.0f,
		0.5f,  0.5f,  0.5f,   1.0f, 1.0f,
		-0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
		-0.5f, bottom_val,  0.5f,  0.0f, 0.0f,

		// !right
		-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		-0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		-0.5f, bottom_val, -0.5f,  0.0f, 1.0f,
		-0.5f, bottom_val, -0.5f,  0.0f, 1.0f,
		-0.5f, bottom_val,  0.5f,  0.0f, 0.0f,
		-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

		// !left
		0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		0.5f, bottom_val, -0.5f,  0.0f, 1.0f,
		0.5f, bottom_val, -0.5f,  0.0f, 1.0f,
		0.5f, bottom_val,  0.5f,  0.0f, 0.0f,
		0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

		// !bottom
		-0.5f, bottom_val, -0.5f,  0.0f, 1.0f,
		0.5f, bottom_val, -0.5f,   1.0f, 1.0f,
		0.5f, bottom_val,  0.5f,   1.0f, 0.0f,
		0.5f, bottom_val,  0.5f,   1.0f, 0.0f,
		-0.5f, bottom_val,  0.5f,  0.0f, 0.0f,
		-0.5f, bottom_val, -0.5f,  0.0f, 1.0f,

		// !up
		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
		0.5f,  0.5f, -0.5f,   1.0f, 1.0f,
		0.5f,  0.5f,  0.5f,   1.0f, 0.0f,
		0.5f,  0.5f,  0.5f,   1.0f, 0.0f,
		-0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f
	};

	std::vector<unsigned int> indices = {
		0, 1, 3,   // first triangle
		1, 2, 3    // second triangle
	};

	glm::mat4 view = glm::mat4(1.0f);
	glm::mat4 projection = glm::perspective(glm::radians(45.0f), 1000.0f / 1000.0f, 0.1f, 100.0f);
	float last_time = .0f;
	bool cam_should_move = true;
	view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));

	j3e::Shader highlight_shader = j3e::Shader("res/shaders/no_texture_vert.glsl", "res/shaders/fraghighlight.glsl");
	char tmp[12] = "lvl";
	hama::LevelEditor *editor = new hama::LevelEditor(vertices, indices, glm::vec2(-0.5, 0.5), "res/img/brick.jpg", tmp);

	glViewport(0, 0, 1280, 720);

	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	ImGui::StyleColorsDark();
	window.impl_imgui();
	ImGui_ImplOpenGL3_Init("#version 330");

	ImFont* ui = io.Fonts->AddFontFromFileTTF("res/fonts/inter.ttf", 17.0f);
	ImFont* chat = io.Fonts->AddFontFromFileTTF("res/fonts/inter.ttf", 32.0f);

	std::vector<j3e::Chat> chat_logs;

	global = {&view, &projection, &last_time, &camera.MovementSpeed, &cam_should_move, &chat_logs};

	global.chat_logs->push_back({window.get_window_size().second - 32, "hi"});

	window.set_input_impl(process_input);

	while(!window.should_close()){
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();

		window.input(j3e::getDeltaTime(*global.last_time), camera);

		editor->Draw(highlight_shader);

		*global.projection = glm::perspective(glm::radians(camera.Zoom), (float)1000 / (float)1000, 0.1f, 100.0f);
		*global.view = camera.GetViewMatrix();

		ImGui::PushFont(ui);

		ImGui::Begin("Camera Controll Window");
		{
			//ImGui::SliderFloat("Mesh1 Pos", &mesh->get_position().x, .0f, 5.0f);
			ImGui::SliderFloat("j3e::Camera Speed", global.MovementSpeed, .0f, 5.0f);
		}
		ImGui::End();

		editor->Draw_UI();

		ImGui::PopFont();

		ImDrawList* draw_list = ImGui::GetForegroundDrawList();
		draw_list->AddText(ImVec2(20, 20), IM_COL32(255, 255, 255, 255), std::format("Camera X: {}", camera.GetViewMatrix()[3].x).c_str());
		draw_list->AddText(ImVec2(20, 40), IM_COL32(255, 255, 255, 255), std::format("Camera Y: {}", camera.GetViewMatrix()[3].y).c_str());
		draw_list->AddText(ImVec2(20, 60), IM_COL32(255, 255, 255, 255), std::format("Camera Z: {}", camera.GetViewMatrix()[3].z).c_str());

		float fps = 1.0f / j3e::getDeltaTime(*global.last_time);
		draw_list->AddText(ImVec2(20, 100), IM_COL32(255, 255, 255, 255), std::format("FPS: {}", fps).c_str());

		ImGui::PushFont(chat);

		if(j3e::InputManager::IsKeyPressed(GLFW_KEY_ENTER)){
			for(auto& text : (*global.chat_logs)){
				text.y -= 32;
			}
			int y = window.get_window_size().second - 32;
			global.chat_logs->push_back({y, "kimak"});
		}

		for(auto& text : (*global.chat_logs)){
			draw_list->AddText(ImVec2(20, text.y), IM_COL32(255, 255, 255, 255), text.msg);
		}

		ImGui::PopFont();

		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		window.swap_buffers();
		glfwPollEvents();
	}

	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();

	glfwTerminate();
	return 0;
}

static void framebuffer_size_callback(GLFWwindow* window, int width, int height){
	glViewport(0, 0, width, width);
#ifdef DEBUG_MODE
	std::cout<<"Window Resized: "<<width<<", "<<height<<std::endl;
#endif
}

static void mouse_callback(GLFWwindow* window, double xposIn, double yposIn)
{
	float xpos = static_cast<float>(xposIn);
	float ypos = static_cast<float>(yposIn);

	if (firstMouse)
	{
		lastX = xpos;
		lastY = ypos;
		firstMouse = false;
	}

	float xoffset = xpos - lastX;
	float yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top

	lastX = xpos;
	lastY = ypos;

	camera.ProcessMouseMovement(xoffset, yoffset);
}

// glfw: whenever the mouse scroll wheel scrolls, this callback is called
// ----------------------------------------------------------------------
static void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
	camera.ProcessMouseScroll(static_cast<float>(yoffset));
}

void process_input(float dt, j3e::Camera& camera, j3e::Window* window){
	if(j3e::InputManager::IsKeyDown(GLFW_KEY_W) == GLFW_PRESS)
		camera.ProcessKeyboard(j3e::Camera_Movement::FORWARD, dt);
	if(j3e::InputManager::IsKeyDown(GLFW_KEY_S) == GLFW_PRESS)
		camera.ProcessKeyboard(j3e::Camera_Movement::BACKWARD, dt);
	if(j3e::InputManager::IsKeyDown(GLFW_KEY_A) == GLFW_PRESS)
		camera.ProcessKeyboard(j3e::Camera_Movement::LEFT, dt);
	if(j3e::InputManager::IsKeyDown(GLFW_KEY_D) == GLFW_PRESS)
		camera.ProcessKeyboard(j3e::Camera_Movement::RIGHT, dt);

	if(j3e::InputManager::IsKeyDown(GLFW_KEY_SPACE) == GLFW_PRESS)
		camera.ProcessKeyboard(j3e::Camera_Movement::ABOVE, dt);
	if(j3e::InputManager::IsKeyDown(GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
		camera.ProcessKeyboard(j3e::Camera_Movement::DOWN, dt);
}
