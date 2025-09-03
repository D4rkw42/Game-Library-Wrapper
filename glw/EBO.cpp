#include <glw/glfw3/EBO.hpp>

glw::defs::glfw3::EBO::EBO(const GLuint* indices, GLsizeiptr size) {
    glGenBuffers(1, &this->ID);
    Bind();
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indices, GL_STATIC_DRAW);
}

glw::defs::glfw3::EBO::EBO(void) {}

glw::defs::glfw3::EBO::~EBO() {
    if (this->ID != 0) {
        glDeleteBuffers(1, &this->ID);
    }
}

void glw::defs::glfw3::EBO::Bind(void) const {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->ID);
}

void glw::defs::glfw3::EBO::Unbind(void) const {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}
