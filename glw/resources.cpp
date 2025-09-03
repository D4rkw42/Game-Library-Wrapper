#include <glw/resources/resources.hpp>

void glw::resources::GenerateResources(void) {
    glw::resources::graphics::geometry::GenerateResources();
}

void glw::resources::DeleteResources(void) {
    glw::resources::graphics::geometry::DeleteResources();
}
