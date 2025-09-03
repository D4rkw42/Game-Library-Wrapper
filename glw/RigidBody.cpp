#include <glw/game/ecs/components/rigid-body/RigidBody.hpp>

#include <glw/utils/math/math.hpp>

glw::game::ecs::RigidBody::RigidBody(float velX, float velY, float rotationVel, float mass)
    : Velocity(velX, velY), RotationVelocity(rotationVel), Mass(mass) {}

void glw::game::ecs::RigidBody::ChangeVelocity(float velX, float velY) noexcept {
    ChangeVelocity(glw::math::Vec2f(velX, velY));
}

void glw::game::ecs::RigidBody::ChangeVelocity(const glw::math::Vec2f& velocity) noexcept {
    this->Velocity = velocity;
}

void glw::game::ecs::RigidBody::ChangeAngularVelocity(float vel) noexcept {
    this->RotationVelocity = vel;
}

void glw::game::ecs::RigidBody::MoveTowards(float vel, float rotation) noexcept {
    this->Velocity.x = vel * std::cos(rotation);
    this->Velocity.y = vel * std::sin(rotation);
}

float glw::game::ecs::RigidBody::GetVelocity(void) const noexcept {
    return std::sqrt(
        this->Velocity.x * this->Velocity.x +
        this->Velocity.y * this->Velocity.y
    );
}

float glw::game::ecs::RigidBody::GetMovementDirection(void) const noexcept {
    return std::atan2(this->Velocity.y, this->Velocity.x);
}

void glw::game::ecs::RigidBody::ApplyActionForce(glw::game::ecs::RigidBody& source, float magnitude, float direction) noexcept {
    ApplyForce(magnitude, direction);
    source.ApplyForce(magnitude, glw::math::OppositeAngle(direction));
}

void glw::game::ecs::RigidBody::ApplyForce(float magnitude, float direction) noexcept {
    float forceX, forceY;
    glw::math::DecomposeVector(magnitude, direction, forceX, forceY);

    this->Forces.x += forceX;
    this->Forces.y += forceY;
}

float glw::game::ecs::RigidBody::GetWeight(float gravityAcceleration) const noexcept {
    return this->Mass * gravityAcceleration;
}

float glw::game::ecs::RigidBody::GetDensity(float volume) const noexcept {
    return this->Mass / volume;
}
