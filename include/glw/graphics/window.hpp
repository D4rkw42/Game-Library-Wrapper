#pragma once

#include <memory>
#include <string>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace glw::graphics {
    class _Window {
        public:
            _Window(const std::string& title, int width, int height);
            ~_Window();

            void Render(void) const noexcept;
            void Clear(int red = 255, int green = 255, int blue = 255, float alpha = 1.0f) const noexcept;

            bool CloseEvent(void) const noexcept;

            GLFWwindow* _Get(void) const noexcept;
            void _UseContext(void) const noexcept;

        private:
            GLFWwindow* window;
    };

    inline std::shared_ptr<_Window> CreateWindow(const std::string& title, int width, int height) {
        return std::make_shared<_Window>(title, width, height);
    }

    using Window = _Window;
}
