#pragma once

#include <string>

#include <glad/glad.h>
#include <glfw/glfw3.h>

namespace glw::defs::glfw3 {
    class Texture {
        public:
            int width, height, channels;

            Texture(const std::string& path);
            Texture(void);
            
            ~Texture();

            void Bind(void) const;
            void Unbind(void) const;
            void Activate(void) const;

            Texture(const Texture&) = delete;
            Texture& operator=(const Texture&) = delete;

            // Move constructor
            Texture(Texture&& other) noexcept : ID(other.ID) {
                other.ID = 0;

                this->width = other.width;
                this->height = other.height;
                this->channels = other.channels;
            }

            Texture& operator=(Texture&& other) noexcept {
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

    inline Texture CreateTexture(const std::string& path) {
        return Texture(path);
    }
}
