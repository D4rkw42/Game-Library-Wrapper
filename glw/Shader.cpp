#include <glw/glfw3/Shader.hpp>

#include <iostream>
#include <fstream>

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

glw::defs::glfw3::Shader::Shader(const std::string& name) {
    const std::string vertShaderContent = ReadShaderFile(name + ".vert");
    const std::string fragShaderContent = ReadShaderFile(name + ".frag");

    const char* vertShaderCStr = vertShaderContent.c_str();
    const char* fragShaderCStr = fragShaderContent.c_str();

    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

    glShaderSource(vertexShader, 1, &vertShaderCStr, NULL);
    glCompileShader(vertexShader);
    CompileErrors(vertexShader, "VERTEX");
    
    glShaderSource(fragmentShader, 1, &fragShaderCStr, NULL);
    glCompileShader(fragmentShader);
    CompileErrors(fragmentShader, "FRAGMENT");

    GLuint shaderProgram = glCreateProgram();

    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    CompileErrors(shaderProgram, "PROGRAM");

    this->ID = shaderProgram;

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

glw::defs::glfw3::Shader::Shader(void) {}

glw::defs::glfw3::Shader::~Shader() {
    glDeleteProgram(this->ID);
}

void glw::defs::glfw3::Shader::Activate(void) const {
    GLint currShaderProgram;

    glGetIntegerv(GL_CURRENT_PROGRAM, &currShaderProgram);

    if (currShaderProgram != this->ID) {
        glUseProgram(this->ID);
    }
}

void glw::defs::glfw3::Shader::SetUniformi(const GLchar* uniform, GLint value) const {
    Activate();

    GLint uniformID = glGetUniformLocation(this->ID, uniform);
    glUniform1i(uniformID, value);
}

void glw::defs::glfw3::Shader::SetUniformMat4(const GLchar* uniform, const glm::mat4& value) const {
    Activate();

    GLint uniformID = glGetUniformLocation(this->ID, uniform);
    glUniformMatrix4fv(uniformID, 1, GL_FALSE, glm::value_ptr(value));
}

void glw::defs::glfw3::Shader::SetUniformVec4(const GLchar* uniform, const glm::vec4& value) const {
    Activate();

    GLint uniformID = glGetUniformLocation(this->ID, uniform);
    glUniform4fv(uniformID, 1, glm::value_ptr(value));
}

std::string glw::defs::glfw3::Shader::ReadShaderFile(const std::string& fileName) const {
    std::string content, line;
    std::ifstream file("./" + std::string(SHADER_FOLDER_PATH) + fileName);

    while (std::getline(file, line)) {
        content += line + "\n";
    }

    return content;
}

void glw::defs::glfw3::Shader::CompileErrors(GLuint shader, const char* type) const {
    GLint hasCompiled;
    char infoLog[1024];

    if (strcmp(type, "PROGRAM") == 0) {
        glGetProgramiv(shader, GL_LINK_STATUS, &hasCompiled);

        if (hasCompiled == GL_FALSE) {
            glGetProgramInfoLog(shader, 1024, NULL, infoLog);
            std::cerr << "SHADER_LINKING_ERROR for: " << type << "\n";
            std::cerr << "reason: " << infoLog << "\n\n";
        }
    } else {
        glGetShaderiv(shader, GL_COMPILE_STATUS, &hasCompiled);

        if (hasCompiled == GL_FALSE) {
            glGetShaderInfoLog(shader, 1024, NULL, infoLog);
            std::cerr << "SHADER_COMPILATION_ERROR for: " << type << "\n";
            std::cerr << "reason: " << infoLog << "\n\n";
        }
    }
}
