#include <glw/entry/init.hpp>
#include <glw/entry/libs.hpp>

bool glw::Init(void) {
    bool glfw3 = glw::_InitGLFW3();

    return glfw3;
}

bool glw::Shutdown(void) {
    glw::_ShutdownGLFW3();
}
