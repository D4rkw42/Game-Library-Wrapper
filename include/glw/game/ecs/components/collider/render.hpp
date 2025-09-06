#pragma once

#include <glw/graphics/Window.hpp>
#include <glw/graphics/geometry/geometry.hpp>
#include <glw/graphics/color/Color.hpp>

#include <glw/game/ecs/components/collider/algorithm/OOB.hpp>
#include <glw/game/ecs/components/collider/algorithm/Circunference.hpp>

namespace glw::game::ecs {
    inline void RenderOOB(const std::shared_ptr<glw::graphics::WindowWrapper>& window, const glw::game::ecs::collider::OOB* oob, const glw::graphics::Color& color) {
        glw::graphics::FillRectangle(window, oob->x, oob->y, oob->width, oob->height, oob->rotation, color);
    }

    inline void RenderCircunference(const std::shared_ptr<glw::graphics::WindowWrapper>& window, glw::game::ecs::collider::Circunference* circunference, const glw::graphics::Color& color) {
        glw::graphics::FillCircunference(window, circunference->x, circunference->y, circunference->diameter, circunference->rotation, color);
    }
}
