#pragma once

#include <glw/graphics/Window.hpp>
#include <glw/graphics/color/Color.hpp>

namespace glw::graphics {
    // Rectangle/Square
    void FillRectangle(const std::shared_ptr<glw::graphics::Window>& window, int x, int y, float width, float height, float rotation, const glw::graphics::Color& color);
    void StrokeRectangle(void);

    // Circunference
    void FillCircunference(const std::shared_ptr<glw::graphics::Window>& window, int x, int y, float diameter, float rotation, const glw::graphics::Color& color);
    void StrokeCircunference(void);
}
