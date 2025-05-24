#include <glw/glfw3/VAO.hpp>

glw::defs::glfw3::_VAO::_VAO(void) {
    glGenVertexArrays(1, &this->ID);
}

glw::defs::glfw3::_VAO::~_VAO(void) {
    glDeleteVertexArrays(1, &this->ID);
}

void glw::defs::glfw3::_VAO::_LinkAttribute(glw::defs::glfw3::_VBO& VBO, GLuint layout, GLuint numComponents, GLenum type, GLsizeiptr stride, void* offset) {
    VBO._Bind();

    glVertexAttribPointer(layout, numComponents, type, GL_FALSE, stride, offset);
    glEnableVertexAttribArray(layout);

    VBO._Unbind();
}

void glw::defs::glfw3::_VAO::_Bind(void) const {
    glBindVertexArray(this->ID);
}

void glw::defs::glfw3::_VAO::_Unbind(void) const {
    glBindVertexArray(0);
}
