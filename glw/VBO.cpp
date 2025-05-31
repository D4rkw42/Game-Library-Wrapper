#include <glw/glfw3/VBO.hpp>

glw::defs::glfw3::_VBO::_VBO(const GLfloat* vertices, GLsizeiptr size) {
    glGenBuffers(1, &this->ID); //cria um buffer (nesse caso será uma VBO). 1 significa que essa VBO está tratando de apenas 1 objeto 3D
    _Bind();
    glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
}

glw::defs::glfw3::_VBO::_VBO(void) {}

glw::defs::glfw3::_VBO::~_VBO() {
    if (this->ID != 0) {
        glDeleteBuffers(1, &this->ID);
    }
}

void glw::defs::glfw3::_VBO::_Bind(void) const {
    glBindBuffer(GL_ARRAY_BUFFER, this->ID);
}

void glw::defs::glfw3::_VBO::_Unbind(void) const {
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}
