#include <glw/game/ecs/components/collider/Collider.hpp>

#include <array>
#include <functional>

#include <glw/game/ecs/components/collider/hitbox-checker.hpp>
#include <glw/game/ecs/components/collider/hitbox-intersection.hpp>

#include <glw/graphics/geometry/geometry.hpp>

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

    ComputeDynamicSize();
}

bool glw::game::ecs::Collider::Check(const glw::game::ecs::Collider& other) const noexcept {
    for (const std::shared_ptr<glw::game::ecs::Hitbox>& hitbox1 : this->HitboxList) {
        for (const std::shared_ptr<glw::game::ecs::Hitbox>& hitbox2 : other.HitboxList) {
            if (glw::game::ecs::CheckHitboxCollision(hitbox1, hitbox2)) {
                return true;
            }
        }
    }

    return false;
}

std::vector<glw::math::Vec2f> glw::game::ecs::Collider::FindIntersections(const glw::game::ecs::Collider& other) const noexcept {
    std::vector<glw::math::Vec2f> intersections;

    // waits min colision between two rectangular hitbox (16 points of max collision)
    const int memory = this->HitboxList.size() * other.HitboxList.size() * 4;
    intersections.reserve(memory);

    for (const std::shared_ptr<glw::game::ecs::Hitbox>& hitbox1 : this->HitboxList) {
        for (const std::shared_ptr<glw::game::ecs::Hitbox>& hitbox2 : other.HitboxList) {
            glw::game::ecs::FindHitboxIntersection(hitbox1, hitbox2, intersections);
        }
    }

    return intersections;
}

void glw::game::ecs::Collider::Render(const std::shared_ptr<glw::graphics::WindowWrapper>& window) const {
    for (const std::shared_ptr<glw::game::ecs::Hitbox>& hitbox : this->HitboxList) {
        hitbox->RenderHitbox(window, this->isColliding);
    }
}

void glw::game::ecs::Collider::RenderLimits(const std::shared_ptr<glw::graphics::WindowWrapper>& window) const {
    glw::graphics::StrokeRectangle(window, this->Center.x, this->Center.y, this->Width, this->Height, 1.0f, 0.0f, glw::graphics::Colors::BLUE);
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

//

void glw::game::ecs::Collider::DynamicComputingEvaluate(const glw::math::Vec2f& reference, const std::array<float, 2>& point, std::array<float, 4>& limits, std::array<std::array<float, 2>, 4>& points) const noexcept {
    float distX = point[0] - reference.x;
    float distY = reference.y - point[1];

    if (distX < limits[0]) {
        limits[0] = distX;
        points[0] = point;
    }

    if (distX > limits[1]) {
        limits[1] = distX;
        points[1] = point;
    }

    if (distY > limits[2]) {
        limits[2] = distY;
        points[2] = point;
    }

    if (distY < limits[3]) {
        limits[3] = distY;
        points[3] = point;
    }
};

void glw::game::ecs::Collider::ComputeDynamicSize(void) noexcept {
    if (this->HitboxList.size() < 1) {
        return;
    }
    
    // 0 is left, 1 is right, 2 is top, 3 is bottom
    std::array<float, 4> limits = { 0.0f, 0.0f, 0.0f, 0.0f };
    std::array<std::array<float, 2>, 4> points;

    const glw::math::Vec2f reference = (this->HitboxList.size() > 1)? this->Position : this->HitboxList[0]->Position;

    for (const std::shared_ptr<glw::game::ecs::Hitbox>& hitbox : this->HitboxList) {
        switch (hitbox->Type) {
            case glw::game::ecs::HitboxType::RECTANGLE: {
                const glw::game::ecs::OOB* oob = glw::game::ecs::GetRectangleHitboxAlgorithm(hitbox);

                for (const std::array<float, 2>& point : oob->vertices) {
                    DynamicComputingEvaluate(reference, point, limits, points);
                }

                break;
            }
            
            case glw::game::ecs::HitboxType::CIRCUNFERENCE: {
                const glw::game::ecs::Circunference* circ = glw::game::ecs::GetCircunferenceHitboxAlgorithm(hitbox);

                std::array<float, 2> point;

                for (float a = 0.0f; a < glw::math::DEG360; a += glw::math::DEG90) {
                    point = { circ->x + std::cos(a) * circ->diameter/2, circ->y + std::sin(a) * circ->diameter/2 };
                    DynamicComputingEvaluate(reference, point, limits, points);
                }

                break;
            }

            case glw::game::ecs::HitboxType::TRIANGLE: {
                break; // @TODO
            }
        };
    }

    this->Center.x = (points[1][0] + points[0][0]) / 2;
    this->Center.y = (points[2][1] + points[3][1]) / 2;

    this->Width = limits[1] - limits[0];
    this->Height = limits[2] - limits[3];
}

//

// utils

void glw::game::ecs::RenderCollisionIntersections(const std::shared_ptr<glw::graphics::Window>& window, const std::vector<glw::math::Vec2f>& intersections) {
    for (const glw::math::Vec2f& point : intersections) {
        glw::graphics::FillCircunference(window, point.x, point.y, 3.5f, glw::graphics::Colors::BLUE);
    }
}
