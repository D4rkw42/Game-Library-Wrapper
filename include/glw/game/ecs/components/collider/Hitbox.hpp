#pragma once

#include <memory>

#include <glw/game/ecs/components/collider/algorithm/Circunference.hpp>
#include <glw/game/ecs/components/collider/algorithm/OOB.hpp>

#include <glw/utils/math/vec2.hpp>

namespace glw::game::ecs {
    enum HitboxType {
        RECTANGLE, CIRCUNFERENCE, TRIANGLE
    };

    class Hitbox {
        public:
            HitboxType Type;
            
            glw::math::Vec2f Position;
            float Width, Height, Rotation;

            void* algorithm;

            Hitbox(HitboxType type, const glw::math::Vec2f& position, float width, float height, float rotation);
            virtual ~Hitbox() = default;

            virtual void LoadHitbox(const glw::math::Vec2f& position, float rotation) = 0;   
    };

    class RectangleHitbox : public Hitbox {
        public:
            RectangleHitbox(const glw::math::Vec2f& position, float width, float height, float rotation);
            ~RectangleHitbox();

            void LoadHitbox(const glw::math::Vec2f& position, float rotation) override final;
    };

    class CircunferenceHitbox : public Hitbox {
        public:
            CircunferenceHitbox(const glw::math::Vec2f& position, float diameter);
            ~CircunferenceHitbox();

            void LoadHitbox(const glw::math::Vec2f& position, float rotation) override final;
    };

    // @TODO
    class TriangleHitbox : public Hitbox {};

    inline std::shared_ptr<Hitbox> CreateRectangleHitbox(const glw::math::Vec2f& position, float width, float height, float rotation) noexcept {
        std::shared_ptr<RectangleHitbox> mHitbox = std::make_shared<RectangleHitbox>(position, width, height, rotation);
        return std::dynamic_pointer_cast<Hitbox>(mHitbox);
    }

    inline std::shared_ptr<Hitbox> CreateCircunferenceHitbox(const glw::math::Vec2f& position, float diameter) noexcept {
        std::shared_ptr<CircunferenceHitbox> mHitbox = std::make_shared<CircunferenceHitbox>(position, diameter);
        return std::dynamic_pointer_cast<Hitbox>(mHitbox);
    } 
}
