#include <glw/glfw3/Model.hpp>

const GLfloat* glw::defs::glfw3::MeshModel::GetVertices(void) const noexcept {
    return this->vertices.data();
}

const GLuint* glw::defs::glfw3::MeshModel::GetIndices(void) const noexcept {
    return this->indices.data();
}

GLsizeiptr glw::defs::glfw3::MeshModel::GetStride(void) const noexcept {
    return this->layoutSize * sizeof(GLfloat);
}

GLsizeiptr glw::defs::glfw3::MeshModel::GetVerticesSizePtr(void) const noexcept {
    return this->vertices.size() * sizeof(GLfloat);
}

GLsizeiptr glw::defs::glfw3::MeshModel::GetIndicesSizePtr(void) const noexcept {
    return GetIndicesCount() * sizeof(GLuint);
}

int glw::defs::glfw3::MeshModel::GetIndicesCount(void) const noexcept {
    return this->indices.size();
}

int glw::defs::glfw3::MeshModel::Section::GetPosition(void) const noexcept {
    return this->start;
}

int glw::defs::glfw3::MeshModel::Section::GetNumOfComponents(void) const noexcept {
    return this->numOfComponents;
}

void* glw::defs::glfw3::MeshModel::Section::GetOffset(void) const noexcept {
    return (void*)(GetPosition() * sizeof(GLfloat));
}
