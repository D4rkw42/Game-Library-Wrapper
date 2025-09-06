#pragma once

#include <glw/graphics/Window.hpp>

#include <glw/game/ecs/components/collider/Hitbox.hpp>
#include <glw/game/ecs/components/collider/checker.hpp>

#include <glw/utils/math/vec2.hpp>

namespace glw::game::ecs {
    class Collider {
        public:
            HitboxList HitboxList;

            glw::math::Vec2f Position;
            float Rotation = 0.0f;

            // Registers if the collider is under collision
            bool isColliding = false;

            explicit Collider(const glw::math::Vec2f& position, float rotation);
            
            Collider(void);
            ~Collider() = default;

            void Update(const glw::math::Vec2f& position, float rotation) noexcept;
            bool Check(Collider& other) const;

            void Render(const std::shared_ptr<glw::graphics::WindowWrapper>& window) const;

            // Criação de hitbox
            void AddRectangle(const glw::math::Vec2f& position, float width, float height, float rotation = 0.0f) noexcept;
            void AddCircunference(const glw::math::Vec2f& position, float diameter, float rotation = 0.0f) noexcept;

        private:
            void RegisterHitbox(const std::shared_ptr<glw::game::ecs::Hitbox>& hitbox) noexcept;
    };

    inline bool CheckCollision(Collider& collider1, Collider& collider2) {
        return collider1.Check(collider2);
    };
}
