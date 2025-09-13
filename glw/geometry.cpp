#include <glw/graphics/geometry/geometry.hpp>

#include <glw/resources/graphics/geometry.hpp>

void glw::graphics::FillRectangle(const std::shared_ptr<glw::graphics::Window> &window, int x, int y, float width, float height, float rotation, const glw::graphics::Color &color) {
    if (window == nullptr || color.a <= 0.0f) {
        return;
    }

    glw::resources::graphics::geometry::rectangle->Fill(window, x, y, width, height, rotation, color);
}

void glw::graphics::StrokeRectangle(const std::shared_ptr<glw::graphics::Window>& window, int x, int y, float width, float height, float border, float rotation, const glw::graphics::Color& color) {
    if (window == nullptr || color.a <= 0.0f) {
        return;
    }

    glw::resources::graphics::geometry::rectangle->Stroke(window, x, y, width, height, border, rotation, color);
}

void glw::graphics::FillCircunference(const std::shared_ptr<glw::graphics::Window>& window, int x, int y, float diameter, const glw::graphics::Color& color) {
    if (window == nullptr || color.a <= 0.0f) {
        return;
    }

    glw::resources::graphics::geometry::circunference->Fill(window, x, y, diameter, color);
}

void glw::graphics::StrokeCircunference(const std::shared_ptr<glw::graphics::Window>& window, int x, int y, float diameter, float border, const glw::graphics::Color& color) {
    if (window == nullptr || color.a <= 0.0f) {
        return;
    }

    glw::resources::graphics::geometry::circunference->Stroke(window, x, y, diameter, border, color);
}
