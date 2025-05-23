#pragma once

#include <memory>
#include <string>

#include <GLFW/glfw3.h>

namespace glw::graphics {
    class _Window {
        public:
            _Window(const std::string& title, int width, int height);
            ~_Window();

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
