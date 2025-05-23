#pragma once

#include <string>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace glw::defs::glwf3 {
    class _Shader {
        public:
            _Shader(const std::string& vertShaderPath, const std::string& fragShaderPath);
            ~_Shader();

            GLuint GetShaderID(void) const noexcept;

        private:
            GLuint ID;

            std::string ReadShaderFile(const std::string& path) const noexcept;
    };

    inline _Shader CreateShader(const std::string& vertShaderPath, const std::string& fragShaderPath) {
        return _Shader(vertShaderPath, fragShaderPath);
    }
}
