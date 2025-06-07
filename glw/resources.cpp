#include <glw/resources/resources.hpp>

void glw::resources::_GenerateResources(void) {
    glw::resources::graphics::geometry::_GenerateResources();
}

void glw::resources::_DeleteResources(void) {
    glw::resources::graphics::geometry::_DeleteResources();
}
