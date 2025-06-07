#include <glw/graphics/geometry/geometry.hpp>

#include <glw/resources/graphics/geometry.hpp>

void glw::graphics::FillRectangle(const std::shared_ptr<glw::graphics::Window> &window, int x, int y, float width, float height, float angle, const glw::graphics::Color &color) {
    if (window == nullptr) {
        return;
    }

    glw::resources::graphics::geometry::rectangle->_Render(window, x, y, width, height, angle, color);
}

void glw::graphics::StrokeRectangle(const std::shared_ptr<glw::graphics::Window>& window, int x, int y, float weight, float angle, const glw::graphics::Color& color) {
    if (window == nullptr) {
        return;
    }
}
