#pragma once

#include <string>

#include <glad/glad.h>
#include <glfw/glfw3.h>

namespace glw::defs::glfw3 {
    class _Texture {
        public:
            int width, height, channels;

            _Texture(const std::string& path);
            ~_Texture();

            void _Bind(void) const;
            void _Unbind(void) const;

        private:
            GLuint ID;
    };

    inline _Texture _CreateTexture(const std::string& path) {
        return _Texture(path);
    }
}
