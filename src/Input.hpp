//
// Created by Michael Pogrebnjak on 25.07.23.
//

#ifndef CLION_OPENGL_TEST_INPUT_HPP
#define CLION_OPENGL_TEST_INPUT_HPP

#include <unordered_map>
#include <vector>
#include <memory>

#include <GLFW/glfw3.h>
#include <glm/gtc/matrix_transform.hpp>

class Input {
public:
	static Input& getInstance() {
		static Input instance;
		return instance;
	}
	Input(Input const&) = delete;
	void operator=(Input const&) = delete;

	void init(GLFWwindow* window);
	void process();
	void bindWindow(GLFWwindow* window);
	//std::shared_ptr<glm::vec3> createMappingVec3(int posX_key, int negX_key, int posY_key, int negY_key, int posZ_key, int negZ_key);
	glm::vec3 m_wasdMovement;
	glm::vec2 m_mouseMovement;
	float m_mouseSensitivity;
private:
	Input() {};
	//std::vector<std::shared_ptr<>>
	glm::vec2 m_lastMousePosition;
	glm::vec2 m_mousePosition;
	GLFWwindow* m_window;
	void pollIsButtonPressed();
	std::unordered_map<int, bool> m_buttonIsPressed;
};

#endif //CLION_OPENGL_TEST_INPUT_HPP
