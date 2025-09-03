#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace glw::defs::glfw3 {
    class VBO {
        public:
            VBO(const GLfloat* vertices, GLsizeiptr size);
            VBO(void);
            
            ~VBO();

            void Bind(void) const;
            void Unbind(void) const;

            VBO(const VBO&) = delete;
            VBO& operator=(const VBO&) = delete;

            // Move constructor
            VBO(VBO&& other) noexcept : ID(other.ID) {
                other.ID = 0;
            }

            // Move assigment
            VBO& operator=(VBO&& other) noexcept {
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

    inline VBO CreateVBO(const GLfloat* vertices, GLsizeiptr size) noexcept {
        return VBO(vertices, size);
    }
}
