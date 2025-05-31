#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace glw::defs::glfw3 {
    class _VBO {
        public:
            _VBO(const GLfloat* vertices, GLsizeiptr size);
            _VBO(void);
            
            ~_VBO();

            void _Bind(void) const;
            void _Unbind(void) const;

            _VBO(const _VBO&) = delete;
            _VBO& operator=(const _VBO&) = delete;

            // Move constructor
            _VBO(_VBO&& other) noexcept : ID(other.ID) {
                other.ID = 0;
            }

            // Move assigment
            _VBO& operator=(_VBO&& other) noexcept {
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

    inline _VBO _CreateVBO(const GLfloat* vertices, GLsizeiptr size) noexcept {
        return _VBO(vertices, size);
    }
}
