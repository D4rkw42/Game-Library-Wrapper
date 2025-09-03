#include <glw/glfw3/VAO.hpp>

glw::defs::glfw3::VAO::VAO(void) {}

glw::defs::glfw3::VAO::~VAO(void) {
    if (this->ID != 0) {
        glDeleteVertexArrays(1, &this->ID);
    }
}

void glw::defs::glfw3::VAO::Generate(void) {
    glGenVertexArrays(1, &this->ID);
}

void glw::defs::glfw3::VAO::LinkAttribute(const glw::defs::glfw3::VBO& VBO, GLuint layout, GLuint numComponents, GLenum type, GLsizeiptr stride, void* offset) const {
    glVertexAttribPointer(layout, numComponents, type, GL_FALSE, stride, offset);
    glEnableVertexAttribArray(layout);
}

void glw::defs::glfw3::VAO::Bind(void) const {
    GLint currVAO;
    glGetIntegerv(GL_VERTEX_ARRAY_BINDING, &currVAO);

    if (currVAO != this->ID) {
        glBindVertexArray(this->ID);
    }
}

void glw::defs::glfw3::VAO::Unbind(void) const {
    glBindVertexArray(0);
}
