#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glw/glfw3/shader.hpp>
#include <glw/glfw3/VBO.hpp>
#include <glw/glfw3/VAO.hpp>
#include <glw/glfw3/EBO.hpp>

#include <glw/glfw3/model.hpp>
#include <glw/glfw3/models/models.hpp>

namespace glw::defs::glfw3 {
    class _Mesh {
        public:
            _Mesh(const glw::defs::glfw3::_MeshModel& model);
            _Mesh(void);

            ~_Mesh();

            void _Render(const glw::defs::glfw3::_Shader& shader) const;

            _Mesh(const _Mesh&) = delete;
            _Mesh& operator=(const _Mesh&) = delete;

            // Move constructor
            _Mesh(_Mesh&& other) noexcept {
                this->VBO = std::move(other.VBO);
                this->VAO = std::move(other.VAO);
                this->EBO = std::move(other.EBO);

                this->glPrimitiveDrawMode = other.glPrimitiveDrawMode;
                this->indicesCount = other.indicesCount;
            }

            // Move assigment
            _Mesh& operator=(_Mesh&& other) noexcept {
                this->VBO = std::move(other.VBO);
                this->VAO = std::move(other.VAO);
                this->EBO = std::move(other.EBO);

                this->glPrimitiveDrawMode = other.glPrimitiveDrawMode;
                this->indicesCount = other.indicesCount;

                return *this;
            }

        private:
            glw::defs::glfw3::_VBO VBO;
            glw::defs::glfw3::_VAO VAO;
            glw::defs::glfw3::_EBO EBO;

            std::uint16_t glPrimitiveDrawMode;
            int indicesCount;
    };

    inline _Mesh _CreateMeshTextureSquare(void) noexcept {
        return _Mesh(glw::defs::glfw3::models::MeshTextureSquareModel);
    };
}
