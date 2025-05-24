#pragma once

#include <string>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace glw::defs::glfw3 {
    class _Shader {
        public:
            _Shader(const std::string& name, const std::string& path);
            ~_Shader();

            void _Activate(void) const;
            GLuint _GetShaderID(void) const noexcept;

            void _SetUniformi(const GLchar* uniform, GLint value);

        private:
            GLuint ID;

            std::string _ReadShaderFile(const std::string& path) const noexcept;
    };

    inline _Shader _CreateShader(const std::string& name, const std::string& path) {
        return _Shader(name, path);
    }
}
