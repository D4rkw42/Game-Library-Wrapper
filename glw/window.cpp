#include <glw/graphics/window.hpp>

glw::graphics::_Window::_Window(const std::string& title, int width, int height) {
    this->window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
    // verificar se a janela foi criada
}

glw::graphics::_Window::~_Window() {
    glfwDestroyWindow(this->window);
}

GLFWwindow* glw::graphics::_Window::_Get(void) const noexcept {
    return this->window;
}

void glw::graphics::_Window::_UseContext(void) const noexcept {
    glfwMakeContextCurrent(_Get());
}
