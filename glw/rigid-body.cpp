#include <glw/game/ecs/components/rigid-body/rigid-body.hpp>

#include <glw/utils/math/math.hpp>

glw::game::ecs::RigidBody::RigidBody(float velX, float velY, float angleVel, float mass)
    : velX(velX), velY(velY), angleVel(angleVel), mass(mass) {}

void glw::game::ecs::RigidBody::ChangeVelocity(float velX, float velY) noexcept {
    this->velX = velX;
    this->velY = velY;
}

void glw::game::ecs::RigidBody::ChangeAngularVelocity(float vel) noexcept {
    this->angleVel = vel;
}

void glw::game::ecs::RigidBody::MoveTowards(float vel, float angle) noexcept {
    this->velX = vel * std::cos(angle);
    this->velY = vel * std::sin(angle);
}

float glw::game::ecs::RigidBody::GetVelocity(void) const noexcept {
    return std::sqrt(this->velX * this->velX + this->velY * this->velY);
}

float glw::game::ecs::RigidBody::GetMovementDirection(void) const noexcept {
    return std::atan2(this->velY, this->velX);
}

void glw::game::ecs::RigidBody::ApplyActionForce(RigidBody& source, float magnitude, float direction) noexcept {
    ApplyForce(magnitude, direction);
    source.ApplyForce(magnitude, -direction);
}

void glw::game::ecs::RigidBody::ApplyForce(float magnitude, float direction) noexcept {
    float forceX, forceY;
    glw::math::DecomposeVector(magnitude, direction, forceX, forceY);

    this->forcesX += forceX;
    this->forcesY += forceY;
}

float glw::game::ecs::RigidBody::_GetWeight(float gravityAcceleration) const noexcept {
    return this->mass * gravityAcceleration;
}

float glw::game::ecs::RigidBody::_GetDensity(float volume) const noexcept {
    return this->mass / volume;
}

float glw::game::ecs::RigidBody::_GetForcesX(void) const noexcept {
    return this->forcesX;
}

float glw::game::ecs::RigidBody::_GetForcesY(void) const noexcept {
    return this->forcesY;
}
