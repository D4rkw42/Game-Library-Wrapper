#pragma once

#include <glw/graphics/Window.hpp>
#include <glw/graphics/geometry/geometry.hpp>
#include <glw/graphics/color/Color.hpp>

#include <glw/game/ecs/components/collider/algorithm/OOB.hpp>

inline void _RenderOOB(const std::shared_ptr<glw::graphics::_WindowWrapper>& window, glw::game::ecs::collider::_OOB& oob, const glw::graphics::Color& color) {
    glw::graphics::FillRectangle(window, oob.x, oob.y, oob.width, oob.height, oob.rotation, color);
}
