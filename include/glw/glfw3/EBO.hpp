#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace glw::defs::glfw3 {
    class _EBO {
        public:
            _EBO(const GLuint* indices, GLsizeiptr size);
            _EBO(void);

            ~_EBO();

            void _Bind(void) const;
            void _Unbind(void) const;

            _EBO(const _EBO&) = delete;
            _EBO& operator=(const _EBO&)= delete;

            // Move constructor
            _EBO(_EBO&& other) noexcept : ID(other.ID) {
                other.ID = 0;
            }

            // Move assignment
            _EBO& operator=(_EBO&& other) noexcept {
                if (this != &other) {
                    if (this->ID != 0) {
                        glDeleteBuffers(1, &this->ID);
                    }

                    this->ID = other.ID;
                    other.ID = 0;
                }

                return *this;
            }
        
        private:
            GLuint ID = 0;
    };

    inline _EBO _CreateEBO(const GLuint* indices, GLsizeiptr size) noexcept {
        return _EBO(indices, size);
    }
}
