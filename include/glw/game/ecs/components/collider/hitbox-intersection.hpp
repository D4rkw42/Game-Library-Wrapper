#pragma once

#include <glw/game/ecs/components/collider/Hitbox.hpp>

#include <vector>

#include <glw/utils/math/types/vec2.hpp>

namespace glw::game::ecs {
    void FindHitboxIntersection(const std::shared_ptr<glw::game::ecs::Hitbox>& hitbox1, const std::shared_ptr<glw::game::ecs::Hitbox>& hitbox2, std::vector<glw::math::Vec2f>& intersections);

    void FindRectangleToRectangleIntersection(const std::shared_ptr<glw::game::ecs::Hitbox>& hitbox1, const std::shared_ptr<glw::game::ecs::Hitbox>& hitbox2, std::vector<glw::math::Vec2f>& intersections);
    void FindCircunferenceToCircunferenceIntersection(const std::shared_ptr<glw::game::ecs::Hitbox>& hitbox1, const std::shared_ptr<glw::game::ecs::Hitbox>& hitbox2, std::vector<glw::math::Vec2f>& intersections);
    void FindRectangleToCircunferenceIntersection(const std::shared_ptr<glw::game::ecs::Hitbox>& hitbox1, const std::shared_ptr<glw::game::ecs::Hitbox>& hitbox2, std::vector<glw::math::Vec2f>& intersections);
}
