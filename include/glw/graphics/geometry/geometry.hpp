#pragma once

#include <glw/graphics/Window.hpp>
#include <glw/graphics/color/Color.hpp>

namespace glw::graphics {
    void FillRectangle(const std::shared_ptr<glw::graphics::Window>& window, int x, int y, float width, float height, float angle, const glw::graphics::Color& color);
    void StrokeRectangle(const std::shared_ptr<glw::graphics::Window>& window, int x, int y, float weight, float angle, const glw::graphics::Color& color);
}
