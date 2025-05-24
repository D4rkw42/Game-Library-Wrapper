#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glw/glfw3/VBO.hpp>

namespace glw::defs::glfw3 {
    class _VAO {
        public:
            _VAO(void);
            ~_VAO();

            void _LinkAttribute(glw::defs::glfw3::_VBO& VBO, GLuint layout, GLuint numComponents, GLenum type, GLsizeiptr stride, void* offset);

            void _Bind(void) const;
            void _Unbind(void) const;

        private:
            GLuint ID;
    };

    inline _VAO _CreateVAO(void) {
        return _VAO();
    }
}
