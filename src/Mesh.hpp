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

	static unsigned int white() {
		static Texture tex;
		if (tex.id) {
			return tex.id;
		}

		glGenTextures(1, &tex.id);

		GLenum format = GL_RGB;
		static float whiteTexture[] = {1.0f, 1.0f, 1.0f, 1.0f};

		glBindTexture(GL_TEXTURE_2D, tex.id);
		glTexImage2D(GL_TEXTURE_2D, 0, format, 1, 1, 0, format, GL_UNSIGNED_BYTE, whiteTexture);
		glGenerateMipmap(GL_TEXTURE_2D);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		return tex.id;
	}
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
