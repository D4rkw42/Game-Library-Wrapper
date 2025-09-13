#pragma once

#include <glw/graphics/Window.hpp>
#include <glw/graphics/color/Color.hpp>

namespace glw::graphics {
    // Rectangle/Square
    void FillRectangle(const std::shared_ptr<glw::graphics::Window>& window, int x, int y, float width, float height, float rotation, const glw::graphics::Color& color);
    void StrokeRectangle(const std::shared_ptr<glw::graphics::Window>& window, int x, int y, float width, float height, float border, float rotation, const glw::graphics::Color& color);

    // Circunference
    void FillCircunference(const std::shared_ptr<glw::graphics::Window>& window, int x, int y, float diameter, const glw::graphics::Color& color);
    void StrokeCircunference(const std::shared_ptr<glw::graphics::Window>& window, int x, int y, float diameter, float border, const glw::graphics::Color& color);
}
