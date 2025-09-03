#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glw/glfw3/Shader.hpp>
#include <glw/glfw3/VBO.hpp>
#include <glw/glfw3/VAO.hpp>
#include <glw/glfw3/EBO.hpp>

#include <glw/glfw3/Model.hpp>
#include <glw/glfw3/models/models.hpp>

namespace glw::defs::glfw3 {
    class Mesh {
        public:
            Mesh(const glw::defs::glfw3::MeshModel& model);
            Mesh(void);

            ~Mesh();

            void Render(const glw::defs::glfw3::Shader& shader) const;

            Mesh(const Mesh&) = delete;
            Mesh& operator=(const Mesh&) = delete;

            // Move constructor
            Mesh(Mesh&& other) noexcept {
                this->VBO = std::move(other.VBO);
                this->VAO = std::move(other.VAO);
                this->EBO = std::move(other.EBO);

                this->glPrimitiveDrawMode = other.glPrimitiveDrawMode;
                this->indicesCount = other.indicesCount;
            }

            // Move assigment
            Mesh& operator=(Mesh&& other) noexcept {
                this->VBO = std::move(other.VBO);
                this->VAO = std::move(other.VAO);
                this->EBO = std::move(other.EBO);

                this->glPrimitiveDrawMode = other.glPrimitiveDrawMode;
                this->indicesCount = other.indicesCount;

                return *this;
            }

        private:
            glw::defs::glfw3::VBO VBO;
            glw::defs::glfw3::VAO VAO;
            glw::defs::glfw3::EBO EBO;

            std::uint16_t glPrimitiveDrawMode;
            int indicesCount;
    };

    inline Mesh CreateMeshTextureSquare(void) noexcept {
        return Mesh(glw::defs::glfw3::models::MeshTextureSquareModel);
    };

    inline Mesh CreateMeshSquare(void) noexcept {
        return Mesh(glw::defs::glfw3::models::MeshSquareModel);
    }
}
