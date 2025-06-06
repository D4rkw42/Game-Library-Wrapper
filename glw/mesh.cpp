#include <glw/glfw3/Mesh.hpp>

glw::defs::glfw3::_Mesh::_Mesh(const glw::defs::glfw3::_MeshModel& model) {
    this->VAO._Generate();
    this->VAO._Bind();

    this->VBO = glw::defs::glfw3::_CreateVBO(model._GetVertices(), model._GetVerticesSizePtr());
    this->EBO = glw::defs::glfw3::_CreateEBO(model._GetIndices(), model._GetIndicesSizePtr());

    GLsizeiptr stride = model._GetStride();

    this->glPrimitiveDrawMode = model.glPrimiveDrawMode;
    this->indicesCount = model._GetIndicesCount();

    for (int i = 0; i < model.sections.size(); ++i) {
        const auto& section = model.sections[i];
        this->VAO._LinkAttribute(this->VBO, i, section._GetNumOfComponents(), GL_FLOAT, stride, section._GetOffset());
    }

    this->VAO._Unbind();
    this->VBO._Unbind();
    this->EBO._Unbind();
}

glw::defs::glfw3::_Mesh::_Mesh(void) {}
glw::defs::glfw3::_Mesh::~_Mesh() {}

void glw::defs::glfw3::_Mesh::_Render(const glw::defs::glfw3::_Shader& shader) const {
    shader._Activate();

    this->VAO._Bind();
    glDrawElements(this->glPrimitiveDrawMode, this->indicesCount, GL_UNSIGNED_INT, (void*)0);
    this->VAO._Unbind();
}
