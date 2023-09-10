#ifndef CLION_OPENGL_TEST_SHADER_HPP
#define CLION_OPENGL_TEST_SHADER_HPP

#include <iostream>
#include <fstream>
#include <sstream>

#include <glad/glad.h>

class Shader {
public:
	Shader(std::string vertexPath, std::string fragmentPath);
	void use();
	inline void setUniformMatrix4fv(const std::string& name, float* data) {
		glUniformMatrix4fv(glGetUniformLocation(m_shaderProgram, name.c_str()), 1, GL_FALSE, data);
	}
	inline void setUniform4fv(const std::string& name, float* data) {
		glUniform4fv(glGetUniformLocation(m_shaderProgram, name.c_str()), 1, data);
	}
	inline void setUniform3fv(const std::string& name, float* data) {
		glUniform3fv(glGetUniformLocation(m_shaderProgram, name.c_str()), 1, data);
	}
	inline void setUniform1i(const std::string& name, int value) {
		glUniform1i(glGetUniformLocation(m_shaderProgram, name.c_str()), value);
	}
	inline void setUniform1f(const std::string& name, float value) {
		glUniform1f(glGetUniformLocation(m_shaderProgram, name.c_str()), value);
	}
	inline unsigned int getProgram() { return m_shaderProgram; }
private:
	unsigned int m_shaderProgram;
};


#endif //CLION_OPENGL_TEST_SHADER_HPP
