#pragma once

#include <cstdint>
#include <vector>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace glw::defs::glfw3 {
    struct _MeshModel {
        std::vector<GLfloat> vertices;
        std::vector<GLuint> indices;

        int layoutSize;

        const GLfloat* _GetVertices(void) const noexcept;
        const GLuint* _GetIndices(void) const noexcept;

        struct _Section {
            int start, numOfComponents;

            int _GetPosition(void) const noexcept;
            int _GetNumOfComponents(void) const noexcept;
            void* _GetOffset(void) const noexcept;

            _Section(int start, int numOfComponents) {
                this->start = start;
                this->numOfComponents = numOfComponents;
            }
        };

        std::vector<_Section> sections;

        GLsizeiptr _GetStride(void) const noexcept;
        GLsizeiptr _GetVerticesSizePtr(void) const noexcept;
        GLsizeiptr _GetIndicesSizePtr(void) const noexcept;

        int _GetIndicesCount(void) const noexcept;

        std::uint16_t glPrimiveDrawMode;

        _MeshModel(const std::vector<GLfloat>& vertices, int layoutSize, const std::vector<glw::defs::glfw3::_MeshModel::_Section>& sections, const std::vector<GLuint>& indices, std::uint32_t glPrimitiveDrawMode) {
            this->vertices = vertices;
            this->indices = indices;
            this->sections = sections;

            this->layoutSize = layoutSize;
            this->glPrimiveDrawMode = glPrimitiveDrawMode;
        }
    };
}
