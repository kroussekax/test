#include "level.hpp"

#include <format>

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

#include "input_manager.hpp"

void Level::Draw(){
	mesh_shader.use();
	glUniform3f(glGetUniformLocation(mesh_shader.get_id(), "objectColor"), 1.0f, 0.5f, 0.31f);
	glUniform3f(glGetUniformLocation(mesh_shader.get_id(), "lightColor"), 1.0f, 1.0f, 1.0f);

	for(int i=0;i<meshes.size();i++){
		if(current_mesh != i)
			meshes[i]->Draw(mesh_shader);
	}

	highlight_mesh->Draw(highlight_shader);
}

void Level::Draw_UI(){
	if(InputManager::IsKeyPressed(GLFW_KEY_RIGHT)){
		current_mesh++;
		highlight_mesh->get_position() = meshes[current_mesh]->get_position();
	}
	if(InputManager::IsKeyPressed(GLFW_KEY_LEFT)) current_mesh--;

	if(current_mesh < 0) current_mesh = 0;
	if(current_mesh > meshes.size()-1) current_mesh = meshes.size()-1;
	highlight_mesh->get_position() = meshes[current_mesh]->get_position();

	ImGui::Begin("Mesh Control Panel");
	{
		ImGui::Text("Total Mesh: %i", (int)meshes.size());
		ImGui::Text("Current Mesh: %i", current_mesh);
		ImGui::SliderFloat(std::format("Mesh {0} X", current_mesh).c_str(), &meshes[current_mesh]->get_position().x, -10.0f, 10.0f);
		ImGui::SliderFloat(std::format("Mesh {0} Y", current_mesh).c_str(), &meshes[current_mesh]->get_position().y, -10.0f, 10.0f);
		ImGui::SliderFloat(std::format("Mesh {0} Z", current_mesh).c_str(), &meshes[current_mesh]->get_position().z, -10.0f, 10.0f);

		if(ImGui::Button("New Mesh", ImVec2(101, 30))){
			add_mesh();
		}
	}
	ImGui::End();

}

Level::Level(std::vector<float> vertices, std::vector<unsigned int> indices){
	mesh_shader = Shader("res/shaders/vertexshaders.glsl", "res/shaders/fragmentshaders.glsl");
	highlight_shader = Shader("res/shaders/no_texture_vert.glsl", "res/shaders/fraghighlight.glsl");

	highlight_mesh = std::make_unique<Mesh>(Mesh(vertices, indices, glm::vec3(2.0f, 2.0f, 2.0f), "res/img/brick.jpg"));
	meshes.push_back(std::make_unique<Mesh>(vertices, indices, glm::vec3(.0f, .0f, .0f), "res/img/brick.jpg"));
	current_mesh = 0;

	highlight_mesh->get_position() = meshes[0]->get_position();
}
