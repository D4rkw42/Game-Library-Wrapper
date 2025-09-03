#include <glw/glfw3/Mesh.hpp>

glw::defs::glfw3::Mesh::Mesh(const glw::defs::glfw3::MeshModel& model) {
    this->VAO.Generate();
    this->VAO.Bind();

    this->VBO = glw::defs::glfw3::CreateVBO(model.GetVertices(), model.GetVerticesSizePtr());
    this->EBO = glw::defs::glfw3::CreateEBO(model.GetIndices(), model.GetIndicesSizePtr());

    GLsizeiptr stride = model.GetStride();

    this->glPrimitiveDrawMode = model.glPrimiveDrawMode;
    this->indicesCount = model.GetIndicesCount();

    for (int i = 0; i < model.sections.size(); ++i) {
        const auto& section = model.sections[i];
        this->VAO.LinkAttribute(this->VBO, i, section.GetNumOfComponents(), GL_FLOAT, stride, section.GetOffset());
    }
    
    this->VAO.Unbind();
    this->VBO.Unbind();
    this->EBO.Unbind();
}

glw::defs::glfw3::Mesh::Mesh(void) {}
glw::defs::glfw3::Mesh::~Mesh() {}

void glw::defs::glfw3::Mesh::Render(const glw::defs::glfw3::Shader& shader) const {
    shader.Activate();

    this->VAO.Bind();
    glDrawElements(this->glPrimitiveDrawMode, this->indicesCount, GL_UNSIGNED_INT, (void*)0);
    this->VAO.Unbind();
}
