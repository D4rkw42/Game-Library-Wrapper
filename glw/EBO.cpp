#include <glw/glfw3/EBO.hpp>

glw::defs::glfw3::_EBO::_EBO(const GLuint* indices, GLsizeiptr size) {
    glGenBuffers(1, &this->ID);
    _Bind();
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indices, GL_STATIC_DRAW);
}

glw::defs::glfw3::_EBO::_EBO(void) {}

glw::defs::glfw3::_EBO::~_EBO() {
    if (this->ID != 0) {
        glDeleteBuffers(1, &this->ID);
    }
}

void glw::defs::glfw3::_EBO::_Bind(void) const {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->ID);
}

void glw::defs::glfw3::_EBO::_Unbind(void) const {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}
