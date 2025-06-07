#include <glw/game/ecs/components/transform/Transform.hpp>

#include <cmath>

glw::game::ecs::Transform::Transform(float x, float y, float rotation) : Position(x, y), Rotation(rotation) {}

void glw::game::ecs::Transform::Translate(float velX, float velY) noexcept {
    Translate(glw::math::Vec2f(velX, velY));
}

void glw::game::ecs::Transform::Translate(const glw::math::Vec2f& velocity) noexcept {
    this->Position += velocity;
}

void glw::game::ecs::Transform::Move(float x, float y) noexcept {
    this->Position.x = x;
    this->Position.y = y;
}

void glw::game::ecs::Transform::LookAt(float x, float y, bool opposite) noexcept {
    float rotation = opposite?
        -std::atan2(y - this->Position.y, x - this->Position.x) :
        std::atan2(y - this->Position.y, x - this->Position.x);

    ChangeRotation(rotation);
}

void glw::game::ecs::Transform::ChangeRotation(float rotation) noexcept {
    this->Rotation = rotation;
}
