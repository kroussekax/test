#include "level.hpp"

#include <iostream>
#include <fstream>
#include <format>
#include <string>
#include <vector>

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

#include <json.hpp>
using json=nlohmann::json;

#include "input_manager.hpp"

void Level::Draw(){
	mesh_shader.use();

	for(int i=0;i<meshes.size();i++){
		meshes[i]->Draw(mesh_shader);
	}

	highlight_mesh->Draw(highlight_shader);
}

void Level::Draw_UI(){
	if(InputManager::IsKeyPressed(GLFW_KEY_RIGHT)) current_mesh++;
	if(InputManager::IsKeyPressed(GLFW_KEY_LEFT)) current_mesh--;

	if(current_mesh < 0) current_mesh = 0;
	if(current_mesh > meshes.size()-1) current_mesh = meshes.size()-1;
	highlight_mesh->get_position() = meshes[current_mesh]->get_position();

	ImGui::Begin("Mesh Control Panel");
	{
		ImGui::Text("Total Mesh: %i", (int)meshes.size());
		ImGui::Text("Current Mesh: %i", current_mesh+1);
		ImGui::SliderFloat(std::format("Mesh {0} X", current_mesh).c_str(), &meshes[current_mesh]->get_position().x, -10.0f, 10.0f);
		ImGui::SliderFloat(std::format("Mesh {0} Y", current_mesh).c_str(), &meshes[current_mesh]->get_position().y, -10.0f, 10.0f);
		ImGui::SliderFloat(std::format("Mesh {0} Z", current_mesh).c_str(), &meshes[current_mesh]->get_position().z, -10.0f, 10.0f);

		if(ImGui::Button("New Mesh", ImVec2(101, 30))){
			add_mesh();
		}
	}
	ImGui::End();

	ImGui::Begin("Saving Menu");
	{
		ImGui::InputText("Level Name", lvl_name, sizeof(lvl_name));
		if(ImGui::Button("Save", ImVec2(101, 30))){
			save();
		}
	}
	ImGui::End();

}

void Level::load(){
}

void Level::save(){
	std::vector<std::array<float, 3>> positions;
	for (auto& mesh : meshes) {
		positions.push_back({mesh->get_position().x, mesh->get_position().y, mesh->get_position().z});
	}

	json j = {
		{"name", lvl_name},
	};
	j["data"] = positions;
	std::cout<<j.dump(4)<<std::endl;

	std::string path = "res/" ;
	path.append(lvl_name);
	path.append(".json");
	std::ofstream outFile(path);
	if (outFile.is_open()) {
		outFile << j.dump(4);
		outFile.close();
		std::cout << "JSON file written successfully." << std::endl;
	}else {
		std::cerr << "Error opening file for writing." << std::endl;
	}

}

Level::Level(char* lvl_name, std::vector<float> vertices, std::vector<unsigned int> indices)
:lvl_name{lvl_name}, default_verticecs{vertices}, default_indices{indices}{
	mesh_shader = Shader("res/shaders/vertexshaders.glsl", "res/shaders/fragmentshaders.glsl");
	highlight_shader = Shader("res/shaders/no_texture_vert.glsl", "res/shaders/fraghighlight.glsl");

	meshes.push_back(std::make_unique<Mesh>(vertices, indices, glm::vec3(.0f, .0f, .0f), "res/img/brick.jpg"));
	current_mesh = 0;

	std::vector<float> highlight_vertices = {
		-0.55f, -0.55f, -0.55f,  0.0f, 0.0f,
		0.55f, -0.55f, -0.55f,	  1.0f, 0.0f,
		0.55f,  0.55f, -0.55f,   1.0f, 1.0f,
		0.55f,  0.55f, -0.55f,   1.0f, 1.0f,
		-0.55f,  0.55f, -0.55f,  0.0f, 1.0f,
		-0.55f, -0.55f, -0.55f,  0.0f, 0.0f,

		-0.55f, -0.55f,  0.55f,  0.0f, 0.0f,
		0.55f, -0.55f,  0.55f,   1.0f, 0.0f,
		0.55f,  0.55f,  0.55f,   1.0f, 1.0f,
		0.55f,  0.55f,  0.55f,   1.0f, 1.0f,
		-0.55f,  0.55f,  0.55f,  0.0f, 1.0f,
		-0.55f, -0.55f,  0.55f,  0.0f, 0.0f,

		-0.55f,  0.55f,  0.55f,  1.0f, 0.0f,
		-0.55f,  0.55f, -0.55f,  1.0f, 1.0f,
		-0.55f, -0.55f, -0.55f,  0.0f, 1.0f,
		-0.55f, -0.55f, -0.55f,  0.0f, 1.0f,
		-0.55f, -0.55f,  0.55f,  0.0f, 0.0f,
		-0.55f,  0.55f,  0.55f,  1.0f, 0.0f,

		0.55f,  0.55f,  0.55f,  1.0f, 0.0f,
		0.55f,  0.55f, -0.55f,  1.0f, 1.0f,
		0.55f, -0.55f, -0.55f,  0.0f, 1.0f,
		0.55f, -0.55f, -0.55f,  0.0f, 1.0f,
		0.55f, -0.55f,  0.55f,  0.0f, 0.0f,
		0.55f,  0.55f,  0.55f,  1.0f, 0.0f,

		-0.55f, -0.55f, -0.55f,  0.0f, 1.0f,
		0.55f, -0.55f, -0.55f,   1.0f, 1.0f,
		0.55f, -0.55f,  0.55f,   1.0f, 0.0f,
		0.55f, -0.55f,  0.55f,   1.0f, 0.0f,
		-0.55f, -0.55f,  0.55f,  0.0f, 0.0f,
		-0.55f, -0.55f, -0.55f,  0.0f, 1.0f,

		-0.55f,  0.55f, -0.55f,  0.0f, 1.0f,
		0.55f,  0.55f, -0.55f,   1.0f, 1.0f,
		0.55f,  0.55f,  0.55f,   1.0f, 0.0f,
		0.55f,  0.55f,  0.55f,   1.0f, 0.0f,
		-0.55f,  0.55f,  0.55f,  0.0f, 0.0f,
		-0.55f,  0.55f, -0.55f,  0.0f, 1.0f
	};

	highlight_mesh = std::make_unique<Mesh>(Mesh(highlight_vertices, indices, glm::vec3(2.0f, 2.0f, 2.0f), "res/img/brick.jpg"));
	highlight_mesh->get_position() = meshes[0]->get_position();
}
