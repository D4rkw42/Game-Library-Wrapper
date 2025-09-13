#pragma once

#include <glw/graphics/Window.hpp>
#include <glw/graphics/geometry/geometry.hpp>
#include <glw/graphics/color/Color.hpp>

#include <glw/game/ecs/components/collider/algorithm/OOB.hpp>
#include <glw/game/ecs/components/collider/algorithm/Circunference.hpp>

namespace glw::game::ecs {
    inline void RenderOOB(const std::shared_ptr<glw::graphics::WindowWrapper>& window, const glw::game::ecs::OOB* oob, const glw::graphics::Color& color) {
        glw::graphics::StrokeRectangle(window, oob->x, oob->y, oob->width, oob->height, 1.0f, oob->rotation, color);
    }

    inline void RenderCircunference(const std::shared_ptr<glw::graphics::WindowWrapper>& window, glw::game::ecs::Circunference* circunference, const glw::graphics::Color& color) {
        glw::graphics::StrokeCircunference(window, circunference->x, circunference->y, circunference->diameter, 1.0f, color);
    }
}
