#include <glw/game/ecs/components/collider/Hitbox.hpp>

#include <glw/game/ecs/components/collider/render.hpp>

glw::game::ecs::Hitbox::Hitbox(const glw::game::ecs::HitboxType type, const glw::math::Vec2f& position, float width, float height, float rotation)
    : Type(type), Position(position), Width(width), Height(height) {}

// Rectangle Hitbox

glw::game::ecs::RectangleHitbox::RectangleHitbox(const glw::math::Vec2f& position, float width, float height, float rotation)
    : Hitbox(glw::game::ecs::HitboxType::RECTANGLE, position, width, height, rotation)
{
    this->algorithm = static_cast<void*>(new glw::game::ecs::OOB(position.x, position.y, width, height, rotation));
    UpdateHitbox(position, rotation);
}

glw::game::ecs::RectangleHitbox::~RectangleHitbox() {
    delete static_cast<glw::game::ecs::OOB*>(this->algorithm);
}

void glw::game::ecs::RectangleHitbox::UpdateHitbox(const glw::math::Vec2f& position, float rotation) {
    glw::game::ecs::OOB* oob = static_cast<glw::game::ecs::OOB*>(this->algorithm);

    this->Position = position;
    this->Rotation = rotation;

    oob->x = position.x;
    oob->y = position.y;
    oob->rotation = rotation;

    oob->CalculateAxis();
    oob->CalculateVertices();
}

void glw::game::ecs::RectangleHitbox::RenderHitbox(const std::shared_ptr<glw::graphics::WindowWrapper>& window, bool isColliding) {
    glw::game::ecs::OOB* oob = static_cast<glw::game::ecs::OOB*>(this->algorithm);

    const glw::graphics::Color color = isColliding? glw::graphics::Colors::GREEN : glw::graphics::Colors::RED;
    glw::game::ecs::RenderOOB(window, oob, color);
}

// circunference hitbox

glw::game::ecs::CircunferenceHitbox::CircunferenceHitbox(const glw::math::Vec2f& position, float diameter, float rotation)
    : Hitbox(glw::game::ecs::HitboxType::CIRCUNFERENCE, position, diameter, diameter, rotation)
{
    this->algorithm = static_cast<void*>(new glw::game::ecs::Circunference(position.x, position.y, diameter, rotation));
    UpdateHitbox(position, rotation);
}

glw::game::ecs::CircunferenceHitbox::~CircunferenceHitbox() {
    delete static_cast<glw::game::ecs::Circunference*>(this->algorithm);
}

void glw::game::ecs::CircunferenceHitbox::UpdateHitbox(const glw::math::Vec2f& position, float rotation) {
    glw::game::ecs::Circunference* circunference = static_cast<glw::game::ecs::Circunference*>(this->algorithm);

    this->Position = position;
    this->Rotation = rotation;

    circunference->x = position.x;
    circunference->y = position.y;
    circunference->rotation = rotation;
}

void glw::game::ecs::CircunferenceHitbox::RenderHitbox(const std::shared_ptr<glw::graphics::WindowWrapper>& window, bool isColliding) {
    glw::game::ecs::Circunference* circunference = static_cast<glw::game::ecs::Circunference*>(this->algorithm);

    const glw::graphics::Color color = isColliding? glw::graphics::Colors::GREEN : glw::graphics::Colors::RED;
    glw::game::ecs::RenderCircunference(window, circunference, color);
}
