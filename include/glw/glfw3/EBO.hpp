#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace glw::defs::glfw3 {
    class _EBO {
        public:
            _EBO(GLuint* indices, GLsizeiptr size);
            ~_EBO();

            void _Bind(void) const;
            void _Unbind(void) const;

        private:
            GLuint ID;
    };

    inline _EBO _CreateEBO(GLuint* indices, GLsizeiptr size) {
        return _EBO(indices, size);
    }
}
