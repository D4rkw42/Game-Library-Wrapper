#include <glw/glfw3/Model.hpp>

const GLfloat* glw::defs::glfw3::_MeshModel::_GetVertices(void) const noexcept {
    return this->vertices.data();
}

const GLuint* glw::defs::glfw3::_MeshModel::_GetIndices(void) const noexcept {
    return this->indices.data();
}

GLsizeiptr glw::defs::glfw3::_MeshModel::_GetStride(void) const noexcept {
    return this->layoutSize * sizeof(GLfloat);
}

GLsizeiptr glw::defs::glfw3::_MeshModel::_GetVerticesSizePtr(void) const noexcept {
    return this->vertices.size() * sizeof(GLfloat);
}

GLsizeiptr glw::defs::glfw3::_MeshModel::_GetIndicesSizePtr(void) const noexcept {
    return _GetIndicesCount() * sizeof(GLuint);
}

int glw::defs::glfw3::_MeshModel::_GetIndicesCount(void) const noexcept {
    return this->indices.size();
}

int glw::defs::glfw3::_MeshModel::_Section::_GetPosition(void) const noexcept {
    return this->start;
}

int glw::defs::glfw3::_MeshModel::_Section::_GetNumOfComponents(void) const noexcept {
    return this->numOfComponents;
}

void* glw::defs::glfw3::_MeshModel::_Section::_GetOffset(void) const noexcept {
    return (void*)(_GetPosition() * sizeof(GLfloat));
}
