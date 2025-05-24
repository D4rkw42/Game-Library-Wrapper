#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace glw::defs::glfw3 {
    class _VBO {
        public:
            _VBO(GLfloat* vertices, GLsizeiptr size);
            ~_VBO();

            void _Bind(void) const;
            void _Unbind(void) const;

        private:
            GLuint ID;
    };

    inline _VBO _CreateVAO(GLfloat* vertices, GLsizeiptr size) {
        return _VBO(vertices, size);
    }
}
