#include "hama.hpp"

#include <memory>
#include <array>
#include <fstream>
#include <format>
#include <iostream>

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

#include <json.hpp>

#include "input_manager.hpp"

using namespace nlohmann;

namespace hama{
void LevelEditor::add_mesh(glm::vec3 pos, glm::vec2 height, const char* img_path,
						   std::vector<float> vertices, std::vector<unsigned int> indices, int id){
	level.meshes.push_back(std::make_unique<j3e::Mesh>(height, vertices, indices, pos, img_path, id));
}

void LevelEditor::change_height(glm::vec2 height){
	level.meshes[current_mesh]->height = height;
	level.meshes[current_mesh]->update_height();

	update_highlight = true;
}

void LevelEditor::load(){
	//resetting
	level.meshes.clear();
	current_mesh = 0;

	std::string path = "res/" ;
	path.append(level.lvl_name);
	path.append(".json");

	std::ifstream file(path);
	if (!file.is_open()) {
		std::cerr << "Failed to open file!" << std::endl;
	}

	// Parse JSON
	json j;
	file >> j;
	file.close();

	// Extract "data" field
	if (j.contains("data") && j["data"].is_array()) {
		for (const auto& arr : j["data"]) {
			if (arr.is_array() && arr.size() == 5) {
				add_mesh(glm::vec3(arr[0], arr[1], arr[2]), glm::vec2(arr[3], arr[4]));
			}
		}
	}
}

void LevelEditor::save(){
	std::vector<std::array<float, 5>> positions;
	for (auto& mesh : level.meshes) {
		positions.push_back({mesh->get_position().x, mesh->get_position().y, mesh->get_position().z, mesh->height.x, mesh->height.y});
	}

	json j = {
		{"name", level.lvl_name},
	};
	j["data"] = positions;
	std::cout<<j.dump(4)<<std::endl;

	std::string path = "res/" ;
	path.append(level.lvl_name);
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

void LevelEditor::Draw(j3e::Shader highlight_shader){
	highlight_mesh->Draw(highlight_shader);
	level.Draw();
}

void LevelEditor::Draw_UI(){
	//! hjkl
	if(j3e::InputManager::IsKeyPressed(GLFW_KEY_K) || j3e::InputManager::IsKeyPressed(GLFW_KEY_J) || j3e::InputManager::IsKeyPressed(GLFW_KEY_H) || j3e::InputManager::IsKeyPressed(GLFW_KEY_L)){
		float y = level.meshes[current_mesh]->get_position().y;
		float x = level.meshes[current_mesh]->get_position().x;
		auto it = std::find_if(level.meshes.begin(), level.meshes.end(), [x, y](std::unique_ptr<j3e::Mesh>& mesh){
			if(j3e::InputManager::IsKeyPressed(GLFW_KEY_J))
				return mesh->get_position().y == y -1&& mesh->get_position().x == x;
			else if(j3e::InputManager::IsKeyPressed(GLFW_KEY_K))
				return mesh->get_position().y == y+1 && mesh->get_position().x == x;
			else if(j3e::InputManager::IsKeyPressed(GLFW_KEY_L))
				return mesh->get_position().x == x+1 && mesh->get_position().y == y;
			else
				return mesh->get_position().x == x-1 && mesh->get_position().y == y;
		});
		if(it != level.meshes.end()){
			current_mesh = (*it)->idx;
			update_highlight = true;
		}
	}

	if(j3e::InputManager::IsKeyPressed(GLFW_KEY_RIGHT)) { current_mesh++; update_highlight = true; }
	if(j3e::InputManager::IsKeyPressed(GLFW_KEY_LEFT)) { current_mesh--; update_highlight = true; }

	if(current_mesh < 0) current_mesh = 0;
	if(current_mesh > level.meshes.size()-1) current_mesh = level.meshes.size()-1;

	ImGui::Begin("j3e::Mesh Control Panel");
	{
		ImGui::Text("Total j3e::Mesh: %i", (int)level.meshes.size());
		ImGui::Text("Current j3e::Mesh: %i", current_mesh+1);

		ImGui::SetNextItemWidth(100);
		ImGui::InputFloat("X", &level.meshes[current_mesh]->get_position().x);
		ImGui::SameLine();
		ImGui::SliderFloat(std::format("##X{}", current_mesh).c_str(), &level.meshes[current_mesh]->get_position().x, -10.0f, 10.0f);

		ImGui::SetNextItemWidth(100);
		ImGui::InputFloat("Y", &level.meshes[current_mesh]->get_position().y);
		ImGui::SameLine();
		ImGui::SliderFloat(std::format("##Y{}", current_mesh).c_str(), &level.meshes[current_mesh]->get_position().y, -10.0f, 10.0f);

		ImGui::SetNextItemWidth(100);
		ImGui::InputFloat("Z", &level.meshes[current_mesh]->get_position().z); // Fixed `.z`
		ImGui::SameLine();
		ImGui::SliderFloat(std::format("##Z{}", current_mesh).c_str(), &level.meshes[current_mesh]->get_position().z, -10.0f, 10.0f);

		ImGui::SetNextItemWidth(100);
		if(ImGui::InputFloat("TP Height", &level.meshes[current_mesh]->height.y)){
			change_height(level.meshes[current_mesh]->height);

			highlight_mesh->height.y  = level.meshes[current_mesh]->height.y;
			highlight_mesh->update_height();
		}
		ImGui::SameLine();
		if(ImGui::SliderFloat(std::format("##TP Height{}", current_mesh).c_str(), &level.meshes[current_mesh]->height.y, -0.5f, 1.0f)){
			change_height(level.meshes[current_mesh]->height);
		}
		ImGui::SetNextItemWidth(100);
		if(ImGui::InputFloat("BT Height", &level.meshes[current_mesh]->height.x)){
			change_height(level.meshes[current_mesh]->height);
		}
		ImGui::SameLine();
		if(ImGui::SliderFloat(std::format("##BT Size{}", current_mesh).c_str(), &level.meshes[current_mesh]->height.x, -1.0f, 0.5f)){
			change_height(level.meshes[current_mesh]->height);
		}

		if(ImGui::Button("New j3e::Mesh", ImVec2(101, 30))){
			add_mesh();
			current_mesh = level.meshes.size()-1;
		}
	}
	ImGui::End();

	ImGui::Begin("Saving Menu");
	{
		ImGui::InputText("Level Name", level.lvl_name, sizeof(level.lvl_name));
		if(ImGui::Button("Save", ImVec2(100, 30))){
			save();
		}

		if(ImGui::Button("Load", ImVec2(100, 30))){
			load();
		}
	}
	ImGui::End();

	if(update_highlight){
		highlight_mesh->get_position() = level.meshes[current_mesh]->get_position();
	}

}

LevelEditor::LevelEditor(std::vector<float> vertices, std::vector<unsigned int> indices, glm::vec2 height, const char* img_path,
						 char* lvl_name){
	Defaults = {
		.vertices = vertices,
		.indices = indices,
		.height = height,
		.img_path = img_path
	};

	j3e::Shader mesh_shader = j3e::Shader("res/shaders/vertexshaders.glsl", "res/shaders/fragmentshaders.glsl");

	level = j3e::Level(lvl_name, mesh_shader);

	std::vector<float> highlight_vertices = {
		-0.52f, -0.52f, -0.52f,  0.0f, 0.0f,
		0.52f, -0.52f, -0.52f,	  1.0f, 0.0f,
		0.52f,  0.52f, -0.52f,   1.0f, 1.0f,
		0.52f,  0.52f, -0.52f,   1.0f, 1.0f,
		-0.52f,  0.52f, -0.52f,  0.0f, 1.0f,
		-0.52f, -0.52f, -0.52f,  0.0f, 0.0f,

		-0.52f, -0.52f,  0.52f,  0.0f, 0.0f,
		0.52f, -0.52f,  0.52f,   1.0f, 0.0f,
		0.52f,  0.52f,  0.52f,   1.0f, 1.0f,
		0.52f,  0.52f,  0.52f,   1.0f, 1.0f,
		-0.52f,  0.52f,  0.52f,  0.0f, 1.0f,
		-0.52f, -0.52f,  0.52f,  0.0f, 0.0f,

		-0.52f,  0.52f,  0.52f,  1.0f, 0.0f,
		-0.52f,  0.52f, -0.52f,  1.0f, 1.0f,
		-0.52f, -0.52f, -0.52f,  0.0f, 1.0f,
		-0.52f, -0.52f, -0.52f,  0.0f, 1.0f,
		-0.52f, -0.52f,  0.52f,  0.0f, 0.0f,
		-0.52f,  0.52f,  0.52f,  1.0f, 0.0f,

		0.52f,  0.52f,  0.52f,  1.0f, 0.0f,
		0.52f,  0.52f, -0.52f,  1.0f, 1.0f,
		0.52f, -0.52f, -0.52f,  0.0f, 1.0f,
		0.52f, -0.52f, -0.52f,  0.0f, 1.0f,
		0.52f, -0.52f,  0.52f,  0.0f, 0.0f,
		0.52f,  0.52f,  0.52f,  1.0f, 0.0f,

		-0.52f, -0.52f, -0.52f,  0.0f, 1.0f,
		0.52f, -0.52f, -0.52f,   1.0f, 1.0f,
		0.52f, -0.52f,  0.52f,   1.0f, 0.0f,
		0.52f, -0.52f,  0.52f,   1.0f, 0.0f,
		-0.52f, -0.52f,  0.52f,  0.0f, 0.0f,
		-0.52f, -0.52f, -0.52f,  0.0f, 1.0f,

		-0.52f,  0.52f, -0.52f,  0.0f, 1.0f,
		0.52f,  0.52f, -0.52f,   1.0f, 1.0f,
		0.52f,  0.52f,  0.52f,   1.0f, 0.0f,
		0.52f,  0.52f,  0.52f,   1.0f, 0.0f,
		-0.52f,  0.52f,  0.52f,  0.0f, 0.0f,
		-0.52f,  0.52f, -0.52f,  0.0f, 1.0f
	};

	add_mesh();

	highlight_mesh = std::make_unique<j3e::Mesh>(j3e::Mesh(glm::vec2(-0.52, 0.52), highlight_vertices, indices, glm::vec3(2.0f, .0f, .0f), "res/img/brick.jpg"));
	highlight_mesh->get_position() = level.meshes[0]->get_position();

	update_highlight = false;
}
}
