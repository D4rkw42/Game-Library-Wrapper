#pragma once

#include <string>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>

constexpr const char* SHADER_FOLDER_PATH = "assets/shaders/";

namespace glw::defs::glfw3 {
    class _Shader {
        public:
            _Shader(const std::string& name);
            _Shader(void);
            
            ~_Shader();

            void _Activate(void) const;

            void _SetUniformi(const GLchar* uniform, GLint value) const;
            void _SetUniformMat4(const GLchar* uniform, const glm::mat4& value) const;

            _Shader(const _Shader&) = delete;
            _Shader& operator=(const _Shader&) = delete;

            // Move Constructor
            _Shader(_Shader&& other) noexcept : ID(other.ID) {
                other.ID = 0;
            }

            // Move Assignment
            _Shader& operator=(_Shader&& other) noexcept {
                if (this != &other) {
                    if (this->ID != 0) {
                        glDeleteProgram(this->ID);
                    }

                    this->ID = other.ID;
                    other.ID = 0;
                }

                return *this;
            }

        private:
            GLuint ID = 0;

            std::string _ReadShaderFile(const std::string& fileName) const;
            void _CompileErrors(GLuint shader, const char* type) const;
    };

    inline _Shader _CreateShader(const std::string& name) noexcept {
        return _Shader(name);
    }
}
