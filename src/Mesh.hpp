//
// Created by Michael Pogrebnjak on 28.07.23.
//

#ifndef CLION_OPENGL_TEST_MESH_HPP
#define CLION_OPENGL_TEST_MESH_HPP

#include <vector>
#include <string>

#include <glad/glad.h>
#include <glm/glm.hpp>

#include "Shader.hpp"

struct Vertex {
	glm::vec3 position;
	glm::vec3 normal;
	glm::vec2 textureCoordinates;
};

struct Texture {
	unsigned int id;
	std::string type;
	std::string path;
};

class Mesh {
public:
	std::vector<Vertex> m_vertices;
	std::vector<unsigned int> m_indices;
	std::vector<Texture> m_textures;

	Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices, std::vector<Texture> textures);
	void Draw(Shader &shader);
private:
	//  render data
	unsigned int m_VAO, m_VBO, m_EBO;

	void setupMesh();
};


#endif //CLION_OPENGL_TEST_MESH_HPP
