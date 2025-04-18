#pragma once

#include <memory>
#include <utility>
#include <vector>
#include <map>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>

#include "shader.hpp"

namespace j3e{
std::pair<unsigned int, const char*> texture_from_file(const char *path, const char* directory="res/img/", bool gamma = false); /* should include the last '/' */

enum class TexType{
	Diffuse,
	Specular
};

inline std::map<TexType, std::string> TexType_to_string = {
	{TexType::Diffuse, "Diffuse"},
	{TexType::Specular, "Specular"},
};

struct Vertex{
	glm::vec3 pos;
	glm::vec3 normal;
	glm::vec2 tex_coord;
};

struct Texture{
	unsigned int id;
	TexType type;
	const char* path;
};

class Mesh {
private:
	unsigned int VBO, VAO, EBO;

	glm::vec3 pos;

	std::vector<Vertex> vertices;
	std::vector<unsigned int> indices;
	std::vector<Texture> textures;
public:
	int idx;

	glm::vec3& get_position(){
		return pos;
	}

	std::unique_ptr<Mesh> clone() const {
		return std::make_unique<Mesh>(vertices, indices, textures);
	}

	void load_texture(Texture tex, int idx=0){
		textures[idx] = tex;
	}

	void Draw(Shader &shader);

	//Mesh(glm::vec2 sides, glm::vec2 height, std::vector<float> vertices, std::vector<unsigned int> indices, glm::vec3 pos, const char* texture_path, int idx=0);
	Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices, std::vector<Texture> textures);
	Mesh();
};

}
