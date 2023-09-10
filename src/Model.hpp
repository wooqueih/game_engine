//
// Created by Michael Pogrebnjak on 29.07.23.
//

#ifndef CLION_OPENGL_TEST_MODEL_HPP
#define CLION_OPENGL_TEST_MODEL_HPP

#include <string>
#include <vector>

#include <assimp/Importer.hpp>
#include <assimp/postprocess.h>
#include <assimp/scene.h>
#include <stb_image.h>

#include "Mesh.hpp"
#include "Component.hpp"

class Model : public Component {
public:
	Model(char *path)
	{
		loadModel(path);
	}
	void draw(Shader &shader);
	std::vector<Mesh> m_meshes;
private:
	// model data
	std::string m_directory;
	std::vector<Texture> m_textures_loaded;

	void loadModel(std::string path);
	void processNode(aiNode *node, const aiScene *scene);
	Mesh processMesh(aiMesh *mesh, const aiScene *scene);
	std::vector<Texture> loadMaterialTextures(aiMaterial *mat, aiTextureType type,
										 std::string typeName);
};


#endif //CLION_OPENGL_TEST_MODEL_HPP
