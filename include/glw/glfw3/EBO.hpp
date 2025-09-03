#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace glw::defs::glfw3 {
    class EBO {
        public:
            EBO(const GLuint* indices, GLsizeiptr size);
            EBO(void);

            ~EBO();

            void Bind(void) const;
            void Unbind(void) const;

            EBO(const EBO&) = delete;
            EBO& operator=(const EBO&)= delete;

            // Move constructor
            EBO(EBO&& other) noexcept : ID(other.ID) {
                other.ID = 0;
            }

            // Move assignment
            EBO& operator=(EBO&& other) noexcept {
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

    inline EBO CreateEBO(const GLuint* indices, GLsizeiptr size) noexcept {
        return EBO(indices, size);
    }
}
