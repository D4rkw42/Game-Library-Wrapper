#include <glw/graphics/geometry/geometry.hpp>

#include <glw/resources/graphics/geometry.hpp>

void glw::graphics::FillRectangle(const std::shared_ptr<glw::graphics::Window> &window, int x, int y, float width, float height, float rotation, const glw::graphics::Color &color) {
    if (window == nullptr) {
        return;
    }

    glw::resources::graphics::geometry::rectangle->Render(window, x, y, width, height, rotation, color);
}

void glw::graphics::StrokeRectangle(void) {}

void glw::graphics::FillCircunference(const std::shared_ptr<glw::graphics::Window>& window, int x, int y, float diameter, float rotation, const glw::graphics::Color& color) {
    if (window == nullptr) {
        return;
    }

    glw::resources::graphics::geometry::circunference->Render(window, x, y, diameter, diameter, rotation, color);
}

void glw::graphics::StrokeCircunference(void) {};
