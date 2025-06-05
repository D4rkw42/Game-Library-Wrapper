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

            std::string title;
            int width, height;

            /// @brief Updates window definitions 
            void Update(void);
            /// @brief Renders the window swaping the backbuffer with the frontbuffer
            void Render(void) const;

            /// @brief Clears the window with the RGB color specified (standard color white). The accepted values are between 0 and 255 (no exception is throwed)
            /// @param red red color
            /// @param green green color
            /// @param blue blue color
            void Clear(int red = 255, int green = 255, int blue = 255) const;

            /// @brief Verify if a close window event was emitted
            /// @return `true` if the user requested it
            bool CloseEvent(void) const;

            GLFWwindow* _Get(void) const noexcept;
            void _UseContext(void) const;

            // window configuration

            void _DepthTestConfig(bool enable) const noexcept;

        private:
            GLFWwindow* window;
    };

    /// @brief Creates a window
    /// @param title the title of the window
    /// @param width window's initial width
    /// @param height window's initial height
    /// @return A smart point for the window
    inline std::shared_ptr<_Window> CreateWindow(const std::string& title, int width, int height) noexcept {
        return std::make_shared<_Window>(title, width, height);
    }

    /// @brief Represents a window to be managed
    using Window = _Window;
}
