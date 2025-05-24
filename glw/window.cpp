#include <glw/graphics/window.hpp>


glw::graphics::_Window::_Window(const std::string& title, int width, int height) {
    this->window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
    // verificar se a janela foi criada

    _UseContext();

    gladLoadGL();
    glEnable(GL_DEPTH_TEST);
}

glw::graphics::_Window::~_Window() {
    glfwDestroyWindow(this->window);
}

void glw::graphics::_Window::Render(void) const noexcept {
    _UseContext();
    glfwSwapBuffers(_Get());
}

void glw::graphics::_Window::Clear(int red, int green, int blue, float alpha) const noexcept {
    _UseContext();

    float glRed = static_cast<float>(red)/255;
    float glGreen = static_cast<float>(green)/255;
    float glBlue = static_cast<float>(blue)/255;
    float glAlpha = alpha;

    glClearColor(glRed, glGreen, glBlue, glAlpha);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

bool glw::graphics::_Window::CloseEvent(void) const noexcept {
    return glfwWindowShouldClose(_Get());
}

GLFWwindow* glw::graphics::_Window::_Get(void) const noexcept {
    return this->window;
}

void glw::graphics::_Window::_UseContext(void) const noexcept {
    glfwMakeContextCurrent(_Get());
}
