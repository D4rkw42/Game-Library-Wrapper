#include <glw/graphics/Window.hpp>

#include <glw/system.hpp>
#include <glw/resources/resources.hpp>

glw::graphics::WindowWrapper::WindowWrapper(const std::string& title, int width, int height) {
        // user can recreate the wrapper. The current window is safety cleared
        if (glw::system::window != NULL) {
            glw::resources::DeleteResources();
            glfwDestroyWindow(glw::system::window);
            glw::system::window = NULL;
        }

        glw::system::window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
        // verificar se a janela foi criada

        glfwMakeContextCurrent(glw::system::window);
        
        glfwSwapInterval(1);
        gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
        glDisable(GL_CULL_FACE);

        Update();

        // when a window is created, all resources have to be generated
        glw::resources::GenerateResources();
}

glw::graphics::WindowWrapper::~WindowWrapper() {
    // when the window is deleted, all resource have to be deleted also
    glw::resources::DeleteResources();
    glfwDestroyWindow(glw::system::window);
    glw::system::window = NULL;
}

void glw::graphics::WindowWrapper::Update(void) {
    glfwGetWindowSize(glw::system::window, &this->Width, &this->Height);
    glViewport(0, 0, this->Width, this->Height);
}

void glw::graphics::WindowWrapper::Render(void) const {
    glfwSwapBuffers(glw::system::window);
}

void glw::graphics::WindowWrapper::Clear(int red, int green, int blue) const {
    float glRed = static_cast<float>(red)/255;
    float glGreen = static_cast<float>(green)/255;
    float glBlue = static_cast<float>(blue)/255;

    glClearColor(glRed, glGreen, glBlue, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

bool glw::graphics::WindowWrapper::CloseEvent(void) const {
    return glfwWindowShouldClose(glw::system::window);
}

// window configuration

void glw::graphics::WindowWrapper::BlendingConfig(bool enable) const noexcept {
    if (enable) {
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        return;
    }

    glDisable(GL_BLEND);
}

void glw::graphics::WindowWrapper::DepthTestConfig(bool enable) const noexcept {
    if (enable) {
        glEnable(GL_DEPTH_TEST);
        glDepthFunc(GL_GEQUAL);
        return;
    }

    glDisable(GL_DEPTH_TEST);
}
