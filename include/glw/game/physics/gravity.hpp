#pragma once

#include <glw/game/ecs/components/transform/Transform.hpp>
#include <glw/game/ecs/components/rigid-body/RigidBody.hpp>

#include <glw/utils/math/vec2.hpp>

namespace glw::game::physics {
    void Gravity(const float G, const glw::game::ecs::Transform& transform, glw::game::ecs::RigidBody& rigidBody, bool horizontal = false) noexcept;
    void GravitySource(const glw::math::Vec2f& source, const float G, const glw::game::ecs::Transform& transform, glw::game::ecs::RigidBody& rigidBody) noexcept;
}
