#include <glw/glfw3/shader.hpp>

#include <fstream>

glw::defs::glfw3::_Shader::_Shader(const std::string& name, const std::string& path) {
    const std::string vertShaderContent = _ReadShaderFile(path + name + ".vert");
    const std::string fragShaderContent = _ReadShaderFile(path + name + ".frag");

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

glw::defs::glfw3::_Shader::~_Shader() {
    glDeleteProgram(_GetShaderID());
}

void glw::defs::glfw3::_Shader::_Activate(void) const {
    glUseProgram(_GetShaderID());
}

GLuint glw::defs::glfw3::_Shader::_GetShaderID(void) const noexcept {
    return this->ID;
}

void glw::defs::glfw3::_Shader::_SetUniformi(const GLchar* uniform, GLint value) {
    GLint uniformID = glGetUniformLocation(_GetShaderID(), uniform);

    _Activate();
    glUniform1i(uniformID, value);
}

std::string glw::defs::glfw3::_Shader::_ReadShaderFile(const std::string& path) const noexcept {
    std::string content, line;
    std::ifstream file("./" + path);

    while (std::getline(file, line)) {
        content += line + "\n";
    }

    return content;
}
