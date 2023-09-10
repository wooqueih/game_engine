#include "Shader.hpp"

void Shader::use() {
	glUseProgram(m_shaderProgram);
}
Shader::Shader(std::string vertexPath, std::string fragmentPath) {
	std::string raw_vertexSrc;
	std::string raw_fragmentSrc;
	std::ifstream vertexFile;
	std::ifstream fragmentFile;

	vertexFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);
	fragmentFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);
	try
	{
		// open files
		vertexFile.open(vertexPath);
		fragmentFile.open(fragmentPath);
		std::stringstream vertexStream, fragmentStream;
		// read file's buffer contents into streams
		vertexStream << vertexFile.rdbuf();
		fragmentStream << fragmentFile.rdbuf();
		// close file handlers
		vertexFile.close();
		fragmentFile.close();
		// convert stream into string
		raw_vertexSrc = vertexStream.str();
		raw_fragmentSrc = fragmentStream.str();
	}
	catch(std::ifstream::failure e)
	{
		std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
	}
	const char* vertexSrc = raw_vertexSrc.c_str();
	const char* fragmentSrc = raw_fragmentSrc.c_str();

	//std::cout << "VERTEX SOURCE:\n" << vertexSrc << "\nFRAGMENT SOURCE:\n" << fragmentSrc << std::endl;

	unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
	unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

	glShaderSource(vertexShader, 1, &vertexSrc, NULL);
	glShaderSource(fragmentShader, 1, &fragmentSrc, NULL);

	int success;
	char infoLog[512];
	glCompileShader(vertexShader);
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
	}
	glCompileShader(fragmentShader);
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
	}

	m_shaderProgram = glCreateProgram();
	glAttachShader(m_shaderProgram, vertexShader);
	glAttachShader(m_shaderProgram, fragmentShader);
	glLinkProgram(m_shaderProgram);

	glGetProgramiv(m_shaderProgram, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(m_shaderProgram, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
	}
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}
