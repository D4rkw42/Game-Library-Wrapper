#include <glw/entry/libs.hpp>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

bool glw::_InitGLFW3(void) {
    bool success = glfwInit() == GLFW_TRUE;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    glfwWindowHint(GLFW_DEPTH_BITS, 24);
    
    return success;
}

void glw::_ShutdownGLFW3(void) {
    glfwTerminate();
}
