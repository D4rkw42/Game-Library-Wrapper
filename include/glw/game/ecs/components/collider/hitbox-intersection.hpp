#pragma once

#include <glw/game/ecs/components/collider/Hitbox.hpp>

#include <vector>

#include <glw/utils/math/types/vec2.hpp>

namespace glw::game::ecs {
    std::vector<glw::math::Vec2f> FindHitboxIntersection(const std::shared_ptr<glw::game::ecs::Hitbox>& hitbox1, const std::shared_ptr<glw::game::ecs::Hitbox>& hitbox2);

    std::vector<glw::math::Vec2f> FindRectangleToRectangleIntersection(const std::shared_ptr<glw::game::ecs::Hitbox>& hitbox1, const std::shared_ptr<glw::game::ecs::Hitbox>& hitbox2);
    std::vector<glw::math::Vec2f> FindCircunferenceToCircunferenceIntersection(const std::shared_ptr<glw::game::ecs::Hitbox>& hitbox1, const std::shared_ptr<glw::game::ecs::Hitbox>& hitbox2);
    std::vector<glw::math::Vec2f> FindRectangleToCircunferenceIntersection(const std::shared_ptr<glw::game::ecs::Hitbox>& hitbox1, const std::shared_ptr<glw::game::ecs::Hitbox>& hitbox2);
}
