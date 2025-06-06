#include <glw/graphics/Window.hpp>

glw::graphics::_Window::_Window(const std::string& title, int width, int height) {
    this->window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
    // verificar se a janela foi criada

    _UseContext();
    
    glfwSwapInterval(1);
    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
    glDisable(GL_CULL_FACE);

    Update();
}

glw::graphics::_Window::~_Window() {
    glfwDestroyWindow(this->window);
}
void glw::graphics::_Window::Update(void) {
    _UseContext();
    
    glfwGetWindowSize(_Get(), &this->width, &this->height);
    glViewport(0, 0, this->width, this->height);
}

void glw::graphics::_Window::Render(void) const {
    _UseContext();
    glfwSwapBuffers(_Get());
}

void glw::graphics::_Window::Clear(int red, int green, int blue) const {
    _UseContext();

    float glRed = static_cast<float>(red)/255;
    float glGreen = static_cast<float>(green)/255;
    float glBlue = static_cast<float>(blue)/255;

    glClearColor(glRed, glGreen, glBlue, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

bool glw::graphics::_Window::CloseEvent(void) const {
    return glfwWindowShouldClose(_Get());
}

GLFWwindow* glw::graphics::_Window::_Get(void) const noexcept {
    return this->window;
}

void glw::graphics::_Window::_UseContext(void) const {
    if (glfwGetCurrentContext() != this->window) {
        glfwMakeContextCurrent(_Get());
    }
}

// window configuration

void glw::graphics::_Window::_DepthTestConfig(bool enable) const noexcept {
    if (enable) {
        glEnable(GL_DEPTH_TEST);
        glDepthFunc(GL_GEQUAL);
        return;
    }

    glDisable(GL_DEPTH_TEST);
    glDepthFunc(GL_NEVER);
}
