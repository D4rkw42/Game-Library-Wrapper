#pragma once

#include <string>

#include <glad/glad.h>
#include <glfw/glfw3.h>

namespace glw::defs::glfw3 {
    class _Texture {
        public:
            int width, height, channels;

            _Texture(const std::string& path);
            _Texture(void);
            
            ~_Texture();

            void _Bind(void) const;
            void _Unbind(void) const;
            void _Activate(void) const;

            _Texture(const _Texture&) = delete;
            _Texture& operator=(const _Texture&) = delete;

            // Move constructor
            _Texture(_Texture&& other) noexcept : ID(other.ID) {
                other.ID = 0;

                this->width = other.width;
                this->height = other.height;
                this->channels = other.channels;
            }

            _Texture& operator=(_Texture&& other) noexcept {
                if (this != &other) {
                    if (this->ID != 0) {
                        glDeleteTextures(1, &this->ID);
                    }

                    this->ID = other.ID;
                    other.ID = 0;
                    
                    this->width = other.width;
                    this->height = other.height;
                    this->channels = other.channels;
                }

                return *this;
            }

        private:
            GLuint ID = 0;
    };

    inline _Texture _CreateTexture(const std::string& path) {
        return _Texture(path);
    }
}
