#include <glw/game/physics/gravity.hpp>

#include <glw/utils/math/math.hpp>

void glw::game::physics::Gravity(const float G, const glw::game::ecs::Transform& transform, glw::game::ecs::RigidBody& rigidBody, bool horizontal) noexcept {
    rigidBody.ApplyForce(G * rigidBody.Mass, horizontal? glw::math::Rad(180) : glw::math::Rad(270));
}

void glw::game::physics::GravitySource(const glw::math::Vec2f& source, const float G, const glw::game::ecs::Transform& transform, glw::game::ecs::RigidBody& rigidBody) noexcept {
    float angle = glw::math::AngleBetweenPoints(source.x, source.y, transform.Position.x, transform.Position.y);
    rigidBody.ApplyForce(G * rigidBody.Mass, angle);
}
