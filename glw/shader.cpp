#include <glw/glwf3/shader.hpp>

#include <fstream>

glw::defs::glwf3::_Shader::_Shader(const std::string& vertShaderPath, const std::string& fragShaderPath) {
    const std::string vertShaderContent = ReadShaderFile(vertShaderPath);
    const std::string fragShaderContent = ReadShaderFile(fragShaderPath);

    const char* vertShaderCStr = vertShaderContent.c_str();
    const char* fragShaderCStr = fragShaderContent.c_str();

    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

    glShaderSource(vertexShader, 1, &vertShaderCStr, NULL);
    glCompileShader(vertexShader);

    glShaderSource(fragmentShader, 1, &fragShaderCStr, NULL);
    glCompileShader(fragmentShader);

    GLuint shaderProgram = glCreateProgram();

    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    this->ID = shaderProgram;

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

glw::defs::glwf3::_Shader::~_Shader() {
    glDeleteProgram(this->ID);
}

GLuint glw::defs::glwf3::_Shader::GetShaderID(void) const noexcept {
    return this->ID;
}

std::string glw::defs::glwf3::_Shader::ReadShaderFile(const std::string& path) const noexcept {
    std::string content, line;
    std::ifstream file("./" + path);

    while (std::getline(file, line)) {
        content += line + "\n";
    }

    return content;
}
