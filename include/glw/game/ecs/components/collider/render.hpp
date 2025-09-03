#pragma once

#include <glw/graphics/Window.hpp>
#include <glw/graphics/geometry/geometry.hpp>
#include <glw/graphics/color/Color.hpp>

#include <glw/game/ecs/components/collider/algorithm/OOB.hpp>

inline void RenderOOB(const std::shared_ptr<glw::graphics::WindowWrapper>& window, glw::game::ecs::collider::OOB& oob, const glw::graphics::Color& color) {
    glw::graphics::FillRectangle(window, oob.x, oob.y, oob.width, oob.height, oob.rotation, color);
}
