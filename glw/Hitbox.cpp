#include <glw/game/ecs/components/collider/Hitbox.hpp>

glw::game::ecs::Hitbox::Hitbox(const glw::game::ecs::HitboxType type, const glw::math::Vec2f& position, float width, float height, float rotation)
    : Type(type), Position(position), Width(width), Height(height) {}

// Rectangle Hitbox

glw::game::ecs::RectangleHitbox::RectangleHitbox(const glw::math::Vec2f& position, float width, float height, float rotation)
    : Hitbox(glw::game::ecs::HitboxType::RECTANGLE, position, width, height, rotation)
{
    this->algorithm = static_cast<void*>(new glw::game::ecs::collider::_OOB(position.x, position.y, width, height, rotation));
}

glw::game::ecs::RectangleHitbox::~RectangleHitbox() {
    delete static_cast<glw::game::ecs::collider::_OOB*>(this->algorithm);
}

void glw::game::ecs::RectangleHitbox::LoadHitbox(const glw::math::Vec2f& position, float rotation) {
    glw::game::ecs::collider::_OOB* oob = static_cast<glw::game::ecs::collider::_OOB*>(this->algorithm);

    this->Position = position;
    this->Rotation = rotation;

    oob->x = position.x;
    oob->y = position.y;
    oob->rotation = rotation;
}

// circunference hitbox

glw::game::ecs::CircunferenceHitbox::CircunferenceHitbox(const glw::math::Vec2f& position, float diameter)
    : Hitbox(glw::game::ecs::HitboxType::CIRCUNFERENCE, position, diameter, diameter, 0.0f)
{
    this->algorithm = static_cast<void*>(new glw::game::ecs::collider::_Circunference(position.x, position.y, diameter));
}

glw::game::ecs::CircunferenceHitbox::~CircunferenceHitbox() {
    delete static_cast<glw::game::ecs::collider::_Circunference*>(this->algorithm);
}

void glw::game::ecs::CircunferenceHitbox::LoadHitbox(const glw::math::Vec2f& position, float rotation) {
    glw::game::ecs::collider::_Circunference* circunference = static_cast<glw::game::ecs::collider::_Circunference*>(this->algorithm);

    this->Position = position;

    circunference->x = position.x;
    circunference->y = position.y;
}
