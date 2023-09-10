//
// Created by Michael Pogrebnjak on 25.07.23.
//

//#include <iostream>

#include <imgui.h>

#include "Input.hpp"


void Input::bindWindow(GLFWwindow* window) {
	m_window = window;
}

void Input::init(GLFWwindow* window) {
	m_window = window;
	m_mouseSensitivity = 5.0f;
	double xPos, yPos;
	glfwGetCursorPos(m_window, &xPos, &yPos);
	m_lastMousePosition = glm::vec2(xPos, yPos);
	//glfwSetCursorPosCallback(m_window, mouse_callback);
	m_wasdMovement = glm::vec3(0.0f, 0.0f, 0.0f);
}

static bool mouseCaptured = false;
static bool escHold = false;
void Input::process() {
	//quit
	if (glfwGetKey(m_window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		if (escHold) {
			return;
		}
		escHold = true;
		if (mouseCaptured) {
			glfwSetInputMode(m_window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
			mouseCaptured = false;
		} else {
			glfwSetInputMode(m_window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
			mouseCaptured = true;
		}
	} else { escHold = false; }

	if (!mouseCaptured) {
		return;
	}
	if (glfwGetKey(m_window, GLFW_KEY_Q) == GLFW_PRESS) {
		glfwSetWindowShouldClose(m_window, true);
	}
	//camera
	m_lastMousePosition = m_mousePosition;
	double xPos, yPos;
	glfwGetCursorPos(m_window, &xPos, &yPos);
	m_mousePosition = glm::vec2(xPos, yPos);
	m_mouseMovement = m_mouseSensitivity*glm::vec2(m_mousePosition.x - m_lastMousePosition.x, m_lastMousePosition.y - m_mousePosition.y);
	//std::cout << "x: " << mousePosition.x << " y: " << mousePosition.y << std::endl;

	Input::pollIsButtonPressed();
	//move
	if (m_buttonIsPressed[GLFW_KEY_W] == m_buttonIsPressed[GLFW_KEY_S]) {
		m_wasdMovement.z = 0.0f;
	} else if (m_buttonIsPressed[GLFW_KEY_W]) {
		m_wasdMovement.z = 1.0f;
	} else if (m_buttonIsPressed[GLFW_KEY_S]) {
		m_wasdMovement.z = -1.0f;
	}
	if (m_buttonIsPressed[GLFW_KEY_D] == m_buttonIsPressed[GLFW_KEY_A]) {
		m_wasdMovement.x = 0.0f;
	} else if (m_buttonIsPressed[GLFW_KEY_D]) {
		m_wasdMovement.x = 1.0f;
	} else if (m_buttonIsPressed[GLFW_KEY_A]) {
		m_wasdMovement.x = -1.0f;
	}
	if (m_wasdMovement != glm::vec3(0.0f, 0.0f, 0.0f)) {
		m_wasdMovement = glm::normalize(m_wasdMovement);
	}
	//std::cout << "x: " << m_wasdMovement.x << " y: " << m_wasdMovement.y << std::endl;
}
void Input::pollIsButtonPressed() {
	if (glfwGetKey(m_window, GLFW_KEY_W) == GLFW_PRESS) {
		m_buttonIsPressed[GLFW_KEY_W] = true;
	} else {
		m_buttonIsPressed[GLFW_KEY_W] = false;
	}
	if (glfwGetKey(m_window, GLFW_KEY_S) == GLFW_PRESS) {
		m_buttonIsPressed[GLFW_KEY_S] = true;
	} else {
		m_buttonIsPressed[GLFW_KEY_S] = false;
	}
	if (glfwGetKey(m_window, GLFW_KEY_D) == GLFW_PRESS) {
		m_buttonIsPressed[GLFW_KEY_D] = true;
	} else {
		m_buttonIsPressed[GLFW_KEY_D] = false;
	}
	if (glfwGetKey(m_window, GLFW_KEY_A) == GLFW_PRESS) {
		m_buttonIsPressed[GLFW_KEY_A] = true;
	} else {
		m_buttonIsPressed[GLFW_KEY_A] = false;
	}
}