#include <glw/glfw3/VAO.hpp>

glw::defs::glfw3::_VAO::_VAO(void) {}

glw::defs::glfw3::_VAO::~_VAO(void) {
    if (this->ID != 0) {
        glDeleteVertexArrays(1, &this->ID);
    }
}

void glw::defs::glfw3::_VAO::_Generate(void) {
    glGenVertexArrays(1, &this->ID);
}

void glw::defs::glfw3::_VAO::_LinkAttribute(const glw::defs::glfw3::_VBO& VBO, GLuint layout, GLuint numComponents, GLenum type, GLsizeiptr stride, void* offset) const {
    glVertexAttribPointer(layout, numComponents, type, GL_FALSE, stride, offset);
    glEnableVertexAttribArray(layout);
}

void glw::defs::glfw3::_VAO::_Bind(void) const {
    GLint currVAO;
    glGetIntegerv(GL_VERTEX_ARRAY_BINDING, &currVAO);

    if (currVAO != this->ID) {
        glBindVertexArray(this->ID);
    }
}

void glw::defs::glfw3::_VAO::_Unbind(void) const {
    glBindVertexArray(0);
}
