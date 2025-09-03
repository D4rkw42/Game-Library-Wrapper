#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glw/glfw3/VBO.hpp>

namespace glw::defs::glfw3 {
    class VAO {
        public:
            VAO(void);
            ~VAO();

            void Generate(void);
            void LinkAttribute(const glw::defs::glfw3::VBO& VBO, GLuint layout, GLuint numComponents, GLenum type, GLsizeiptr stride, void* offset) const;

            void Bind(void) const;
            void Unbind(void) const;

            VAO(const VAO&) = delete;
            VAO& operator=(const VAO&) = delete;

            // Move constructor
            VAO(VAO&& other) noexcept : ID(other.ID) {
                other.ID = 0;
            }

            // Move assignment
            VAO& operator=(VAO&& other) noexcept {
                if (this != &other) {
                    if (this->ID != 0) {
                        glDeleteVertexArrays(1, &this->ID);
                    }

                    this->ID = other.ID;
                    other.ID = 0;
                }

                return *this;
            }

        private:
            GLuint ID = 0;
    };
}
