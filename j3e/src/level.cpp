#include "level.hpp"
#include "GLFW/glfw3.h"

#include <algorithm>
#include <iostream>
#include <fstream>
#include <format>
#include <linux/input.h>
#include <memory>
#include <ostream>
#include <string>
#include <vector>

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

#include <json.hpp>
using json=nlohmann::json;

#include "input_manager.hpp"

namespace j3e{
void Level::Draw(){
	mesh_shader.use();

	for(int i=0;i<meshes.size();i++){
		meshes[i]->Draw(mesh_shader);
	}
}

Level::Level(){
}
}
