#pragma once

#include <cstdint>
#include <vector>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace glw::defs::glfw3 {
    struct MeshModel {
        std::vector<GLfloat> vertices;
        std::vector<GLuint> indices;

        int layoutSize;

        const GLfloat* GetVertices(void) const noexcept;
        const GLuint* GetIndices(void) const noexcept;

        struct Section {
            int start, numOfComponents;

            int GetPosition(void) const noexcept;
            int GetNumOfComponents(void) const noexcept;
            void* GetOffset(void) const noexcept;

            Section(int start, int numOfComponents) {
                this->start = start;
                this->numOfComponents = numOfComponents;
            }
        };

        std::vector<Section> sections;

        GLsizeiptr GetStride(void) const noexcept;
        GLsizeiptr GetVerticesSizePtr(void) const noexcept;
        GLsizeiptr GetIndicesSizePtr(void) const noexcept;

        int GetIndicesCount(void) const noexcept;

        std::uint16_t glPrimiveDrawMode;

        MeshModel(const std::vector<GLfloat>& vertices, int layoutSize, const std::vector<glw::defs::glfw3::MeshModel::Section>& sections, const std::vector<GLuint>& indices, std::uint32_t glPrimitiveDrawMode) {
            this->vertices = vertices;
            this->indices = indices;
            this->sections = sections;

            this->layoutSize = layoutSize;
            this->glPrimiveDrawMode = glPrimitiveDrawMode;
        }
    };
}
