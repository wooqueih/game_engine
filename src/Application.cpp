#include "Application.hpp"

Application::Application() {
	m_windowHeight = 0;
	m_windowWidth = 0;
	m_window = nullptr;
}
void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	Application app = Application::getInstance();
	app.setWindowSize(width, height);
	glViewport(0, 0, width, height);
}
int Application::init(int windowWidth, int windowHeight, const char* title) {
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	m_windowWidth = windowWidth;
	m_windowHeight = windowHeight;
	m_title = title;
	m_window = glfwCreateWindow(m_windowWidth, m_windowHeight, m_title, NULL, NULL);
	if (m_window == NULL) {
		std::cout << "FAILED to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(m_window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "FAILED to init GLAD" << std::endl;
		return -1;
	}
	glViewport(0, 0, m_windowWidth, m_windowHeight);

	glfwSetFramebufferSizeCallback(m_window, framebuffer_size_callback);

	return 0;
}

