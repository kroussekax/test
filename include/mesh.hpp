#pragma once

#include <vector>

class Mesh {
private:
	unsigned int VAO, VBO, EBO;
public:

	void Bind() const;
	void Unbind() const;
	void Draw() const;

	Mesh(const std::vector<float>& vertices, const std::vector<unsigned int>& indices);
	Mesh();
	~Mesh();
};
