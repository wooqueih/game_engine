//
// Created by Michael Pogrebnjak on 28.07.23.
//

#include "Mesh.hpp"

Mesh::Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices, std::vector<Texture> textures) {
	m_vertices = vertices;
	m_indices = indices;
	m_textures = textures;

	setupMesh();
}

void Mesh::setupMesh() {
	glGenVertexArrays(1, &m_VAO);
	glGenBuffers(1, &m_VBO);
	glGenBuffers(1, &m_EBO);

	glBindVertexArray(m_VAO);

	glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
	glBufferData(GL_ARRAY_BUFFER, m_vertices.size() * sizeof(Vertex), &m_vertices[0], GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_indices.size() * sizeof(unsigned int), m_indices.data(), GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)3);
	glEnableVertexAttribArray(1);

	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)6);
	glEnableVertexAttribArray(2);

	glBindVertexArray(0);
}

void Mesh::Draw(Shader &shader)
{
	unsigned int diffuseNr = 1;
	unsigned int specularNr = 1;
	int count;
	for(unsigned int i = 0; i < m_textures.size(); i++) {
		count = i;
		glActiveTexture(GL_TEXTURE0 + i); // activate proper texture unit before binding
		// retrieve texture number (the N in diffuse_textureN)
		std::string number;
		std::string name = m_textures[i].type;
		if(name == "texture_diffuse") {
			number = std::to_string(diffuseNr);
			diffuseNr++;
		} else if(name == "texture_specular") {
			number = std::to_string(specularNr);
			specularNr++;
		}

		shader.setUniform1i(("material." + name + number).c_str(), i);
		glBindTexture(GL_TEXTURE_2D, m_textures[i].id);
	}
	while (diffuseNr < 9) {
		glActiveTexture(GL_TEXTURE0 + count); // activate proper texture unit before binding
		shader.setUniform1i(("material.texture_diffuse" + std::to_string(diffuseNr)).c_str(), count);
		glBindTexture(GL_TEXTURE_2D, Texture::white());

		diffuseNr++;
		count++;
	}
	while (specularNr < 9) {
		glActiveTexture(GL_TEXTURE0 + count); // activate proper texture unit before binding
		shader.setUniform1i(("material.texture_diffuse" + std::to_string(specularNr)).c_str(), count);
		glBindTexture(GL_TEXTURE_2D, Texture::white());

		specularNr++;
		count++;
	}
	glActiveTexture(GL_TEXTURE0);

	shader.use();
	// draw mesh
	glBindVertexArray(m_VAO);
	//glDrawArrays(GL_TRIANGLES, 0, m_vertices.size());
	glDrawElements(GL_TRIANGLES, static_cast<unsigned int>(m_indices.size()), GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}