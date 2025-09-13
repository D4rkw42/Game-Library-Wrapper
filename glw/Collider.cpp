#include <glw/game/ecs/components/collider/Collider.hpp>

#include <array>

#include <glw/game/ecs/components/collider/hitbox-checker.hpp>
#include <glw/utils/math/math.hpp>

glw::game::ecs::Collider::Collider(const glw::math::Vec2f& position, float rotation): Position(position), Rotation(rotation) {}

void glw::game::ecs::Collider::Update(const glw::math::Vec2f& position, float rotation) noexcept {
    glw::math::Vec2f positionDiff = position - this->Position;
    this->Position = position;

    float rotationDiff = rotation - this->Rotation;
    this->Rotation = rotation;

    for (const std::shared_ptr<glw::game::ecs::Hitbox>& hitbox : this->HitboxList) {
        glw::math::Vec2f newPosition = hitbox->Position + positionDiff;
        float newRotation = hitbox->Rotation + rotationDiff;

        std::array<float, 2>
            center { this->Position.x, this->Position.y },
            position { newPosition.x, newPosition.y },
            newRotatedPosition { 0.0f, 0.0f };

        glw::math::RotatePoint(center, position, rotationDiff, newRotatedPosition);
        
        hitbox->UpdateHitbox({ newRotatedPosition[0], newRotatedPosition[1] }, newRotation);
    }
}

bool glw::game::ecs::Collider::Check(Collider& other) const {
    for (const std::shared_ptr<glw::game::ecs::Hitbox>& hitbox1 : this->HitboxList) {
        for (const std::shared_ptr<glw::game::ecs::Hitbox>& hitbox2 : other.HitboxList) {
            if (glw::game::ecs::CheckHitboxCollision(hitbox1, hitbox2)) {
                return true;
            }
        }
    }

    return false;
}

void glw::game::ecs::Collider::Render(const std::shared_ptr<glw::graphics::WindowWrapper>& window) const {
    for (const std::shared_ptr<glw::game::ecs::Hitbox>& hitbox : this->HitboxList) {
        hitbox->RenderHitbox(window, this->isColliding);
    }
}

void glw::game::ecs::Collider::AddRectangle(const glw::math::Vec2f& position, float width, float height, float rotation) noexcept {
    const std::shared_ptr<glw::game::ecs::Hitbox> hitbox = glw::game::ecs::CreateRectangleHitbox(this->Position + position, width, height, rotation);
    RegisterHitbox(hitbox);
}

void glw::game::ecs::Collider::AddCircunference(const glw::math::Vec2f& position, float diameter, float rotation) noexcept {
    const std::shared_ptr<glw::game::ecs::Hitbox> hitbox = glw::game::ecs::CreateCircunferenceHitbox(this->Position + position, diameter, rotation);
    RegisterHitbox(hitbox);
}

void glw::game::ecs::Collider::RegisterHitbox(const std::shared_ptr<glw::game::ecs::Hitbox>& hitbox) noexcept {
    this->HitboxList.push_back(hitbox);
}
