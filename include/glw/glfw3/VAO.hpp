#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glw/glfw3/VBO.hpp>

namespace glw::defs::glfw3 {
    class _VAO {
        public:
            _VAO(void);
            ~_VAO();

            void _Generate(void);
            void _LinkAttribute(const glw::defs::glfw3::_VBO& VBO, GLuint layout, GLuint numComponents, GLenum type, GLsizeiptr stride, void* offset) const;

            void _Bind(void) const;
            void _Unbind(void) const;

            _VAO(const _VAO&) = delete;
            _VAO& operator=(const _VAO&) = delete;

            // Move constructor
            _VAO(_VAO&& other) noexcept : ID(other.ID) {
                other.ID = 0;
            }

            // Move assignment
            _VAO& operator=(_VAO&& other) noexcept {
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
