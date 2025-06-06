#include <glw/game/ecs/components/transform/Transform.hpp>

#include <cmath>

glw::game::ecs::Transform::Transform(float x, float y, float angle) : x(x), y(y), angle(angle) {}

void glw::game::ecs::Transform::Translate(float velX, float velY) noexcept {
    this->x += velX;
    this->y += velY;
}

void glw::game::ecs::Transform::Move(float x, float y) noexcept {
    this->x = x;
    this->y = y;
}

void glw::game::ecs::Transform::LookAt(float x, float y, bool opposite) noexcept {
    float angle = opposite?
        -std::atan2(y - this->y, x - this->x) :
        std::atan2(y - this->y, x - this->x);

    ChangeAngle(angle);
}

void glw::game::ecs::Transform::ChangeAngle(float angle) noexcept {
    this->angle = angle;
}
