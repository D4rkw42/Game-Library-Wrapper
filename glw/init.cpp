#include <glw/entry/init.hpp>
#include <glw/entry/libs.hpp>

#include <glw/resources/resources.hpp>

bool glw::Init(void) {
    // Initializing libs

    bool glfw3 = glw::_InitGLFW3();

    if (!glfw3) {
        return false;
    }

    return true;
}

void glw::Shutdown(void) {
    // delete all resources when shuting down
    glw::resources::_DeleteResources();

    // Shuting libs down
    glw::_ShutdownGLFW3();
}
