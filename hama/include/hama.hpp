#pragma once

// from hama

#include <map>
#include <string>
#include <vector>
#include <memory>

#include "level.hpp"

#include "mesh.hpp"

namespace hama{
enum class Mode{
	Normal,
	Visual
};

inline std::map<Mode, std::pmr::string> mode_to_string = {
	{Mode::Normal, "Normal"},
	{Mode::Visual, "Visual"}
};

struct Defaults{
	std::vector<j3e::Vertex> vertices;
	std::vector<unsigned int> indices;

	glm::vec2 height;
	glm::vec2 sides;

	const char* img_path;
};

class LevelEditor{
private:
	j3e::Level level;

	Mode mode;
	std::unique_ptr<j3e::Mesh> highlight_mesh; /* optimize this shit yo */
	std::vector<int> current_mesh;

	//! defaults (should be configurable)

	Defaults defaults;

	bool update_highlight;

	void change_height(glm::vec2 height);

	void switch_modes();
public:
	/* add_mesh(..) will create a new mesh and push back into level.meshes and fill empty arguments with properties in this->defaults */
	void add_mesh(glm::vec3 pos, glm::vec2 sides, glm::vec2 height, const char* img_path,
			   std::vector<float> vertices, std::vector<unsigned int> indices, int idx=0);

	void add_mesh(glm::vec3 pos, glm::vec2 height, const char* img_path, int idx=0){
		add_mesh(pos, defaults.sides, height, img_path, defaults.vertices, defaults.indices, idx);
	}
	void add_mesh(glm::vec3 pos, glm::vec2 height, int idx=0){
		add_mesh(pos, defaults.sides, height, defaults.img_path, defaults.vertices, defaults.indices, idx);
	}
	void add_mesh(glm::vec3 pos, int idx=0){
		add_mesh(pos, defaults.sides, defaults.height, defaults.img_path, defaults.vertices, defaults.indices, idx);
	}
	void add_mesh(int idx=0){
		add_mesh(glm::vec3(.0f), defaults.sides, defaults.height, defaults.img_path, defaults.vertices, defaults.indices, idx);
	}

	/* clone_mesh will copy the mesh thats in the index given in the argument and push it into level.mesh */
	void clone_mesh(int idx=0){
		auto mesh = level.meshes[idx]->clone();
		mesh->idx = get_level_size();
		level.meshes.push_back(std::move(mesh));
	}

	void load();
	void save();

	void Draw(j3e::Shader highlight_shader);
	void Draw_UI();

	// getters
	int get_level_size(){ return level.meshes.size(); }

	LevelEditor(char* lvl_name, Defaults defaults);
};
};
