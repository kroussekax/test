#pragma once

#include <string>

namespace j3e{
class Shader{
private:
	unsigned int id;
public:
	int get_id(){ return id; }

	void use();

	void setBool(const std::string& name, bool value) const;
	void setInt(const std::string& name, int value) const;
	void setFloat(const std::string& name, float value) const;

	void Delete();

	Shader(const char* vert_shader_parth, const char* frag_shader_parth);
	Shader();
};
}
