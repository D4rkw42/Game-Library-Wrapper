#include <glw/game/ecs/components/transform/Transform.hpp>

#include <glw/utils/math/math.hpp>

glw::game::ecs::Transform::Transform(float x, float y, float width, float height, float rotation)
    : Position(x, y), Width(width), Height(height), Rotation(rotation) {}

void glw::game::ecs::Transform::Translate(float x, float y) noexcept {
    this->Position.x += x;
    this->Position.y += y;
}

void glw::game::ecs::Transform::Move(float x, float y) noexcept {
    this->Position.x = x;
    this->Position.y = y;
}

void glw::game::ecs::Transform::LookAt(float x, float y, bool opposite) noexcept {
    float rotation = opposite?
        glw::math::OppositeAngle(glw::math::AngleBetweenPoints(this->Position.x, this->Position.y, x, y)) :
        glw::math::AngleBetweenPoints(this->Position.x, this->Position.y, x, y);

    ChangeRotation(rotation);
}

void glw::game::ecs::Transform::ChangeRotation(float rotation) noexcept {
    this->Rotation = rotation;
}
