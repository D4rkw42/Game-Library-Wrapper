#pragma once

#include <string>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>

constexpr const char* SHADER_FOLDER_PATH = "assets/shaders/";

namespace glw::defs::glfw3 {
    class Shader {
        public:
            Shader(const std::string& name);
            Shader(void);
            
            ~Shader();

            void Activate(void) const;

            void SetUniformi(const GLchar* uniform, GLint value) const;
            void SetUniformMat4(const GLchar* uniform, const glm::mat4& value) const;
            void SetUniformVec4(const GLchar* uniform, const glm::vec4& value) const;

            Shader(const Shader&) = delete;
            Shader& operator=(const Shader&) = delete;

            // Move Constructor
            Shader(Shader&& other) noexcept : ID(other.ID) {
                other.ID = 0;
            }

            // Move Assignment
            Shader& operator=(Shader&& other) noexcept {
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

            std::string ReadShaderFile(const std::string& fileName) const;
            void CompileErrors(GLuint shader, const char* type) const;
    };

    inline Shader CreateShader(const std::string& name) noexcept {
        return Shader(name);
    }
}
