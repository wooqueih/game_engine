#ifndef CLION_OPENGL_TEST_APPLICATION_HPP
#define CLION_OPENGL_TEST_APPLICATION_HPP

#include <iostream>
#include <string>

#include <glad/glad.h>
#include <GLFW/glfw3.h>


class Application {
public:
	static Application& getInstance() {
		static Application instance;
		return instance;
	}

	int init(int windowWidth, int windowHeight, const char* title);
	inline GLFWwindow* getWindow() { return m_window; }

	inline void setWindowSize(int width, int height) { m_windowWidth = width; m_windowHeight = height; }
	inline int getWindowHeight() const { return m_windowHeight; }
	//inline int setWindowHeight(int newHeight) { this->m_windowHeight = newHeight; }
	inline int getWindowWidth() const { return m_windowWidth; }
	//inline int setWindowWidth(int newWidth) { this->m_windowWidth = newWidth; }

private:
	Application();
	int m_windowHeight;
	int m_windowWidth;
	const char* m_title;
	GLFWwindow* m_window;
};


#endif //CLION_OPENGL_TEST_APPLICATION_HPP
