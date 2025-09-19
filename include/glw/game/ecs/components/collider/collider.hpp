#pragma once

#include <glw/graphics/Window.hpp>

#include <vector>

#include <glw/game/ecs/components/collider/Hitbox.hpp>

#include <glw/utils/math/types/vec2.hpp>

namespace glw::game::ecs {
    class Collider {
        public:
            HitboxList HitboxList;

            glw::math::Vec2f Position, Center;

            float
                Width = 0.0f,
                Height = 0.0f;

            float Rotation = 0.0f;

            // Registers if the collider is under collision
            bool isColliding = false;

            explicit Collider(const glw::math::Vec2f& position, float rotation);
            
            Collider(void) = default;
            ~Collider() = default;

            void Update(const glw::math::Vec2f& position, float rotation) noexcept;
            bool Check(const Collider& other) const noexcept;

            std::vector<glw::math::Vec2f> FindIntersections(const Collider& other) const noexcept;

            void Render(const std::shared_ptr<glw::graphics::WindowWrapper>& window) const;
            void RenderLimits(const std::shared_ptr<glw::graphics::WindowWrapper>& window) const;

            // Criação de hitbox
            void AddRectangle(const glw::math::Vec2f& position, float width, float height, float rotation = 0.0f) noexcept;
            void AddCircunference(const glw::math::Vec2f& position, float diameter, float rotation = 0.0f) noexcept;

            /// @brief Verifies if two colliders are from the same element
            /// @return `true` if they are the same
            constexpr bool operator==(const glw::game::ecs::Collider& collider) const noexcept {
                return this == &collider;
            }

            /// @brief Verifies if two colliders are not from the same element
            /// @return `true` if they are different
            constexpr bool operator!=(const glw::game::ecs::Collider& collider) const noexcept {
                return this != &collider;
            }

        private:
            void RegisterHitbox(const std::shared_ptr<glw::game::ecs::Hitbox>& hitbox) noexcept;

            void DynamicComputingEvaluate(const glw::math::Vec2f& reference, const std::array<float, 2>& point, std::array<float, 4>& limits, std::array<std::array<float, 2>, 4>& points) const noexcept;
            void ComputeDynamicSize(void) noexcept;
    };

    inline bool CheckCollision(const Collider& collider1, const Collider& collider2) {
        return collider1.Check(collider2);
    };

    inline std::vector<glw::math::Vec2f> FindCollisionIntersections(const Collider& collider1, const Collider& collider2) {
        return collider1.FindIntersections(collider2);
    }

    void RenderCollisionIntersections(const std::shared_ptr<glw::graphics::Window>& window, const std::vector<glw::math::Vec2f>& intersections);

    /// @brief An invalid collider
    inline Collider NullCollider;

    /// @brief Verifies if the collider is invalid
    /// @param collider the collider to compare
    /// @return `true` if the collider is invalid
    constexpr bool InvalidCollider(const glw::game::ecs::Collider& collider) noexcept {
        return collider == glw::game::ecs::NullCollider;
    }
}
