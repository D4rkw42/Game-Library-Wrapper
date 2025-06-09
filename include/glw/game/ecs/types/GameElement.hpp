#pragma once

#include <memory>
#include <optional>

#include <glw/game/ecs/components/transform/Transform.hpp>
#include <glw/game/ecs/components/rigid-body/RigidBody.hpp>

#include <glw/utils/math/vec2.hpp>

namespace glw::game::ecs {
    class GameElement {
        public:
            GameElement(const glw::math::Vec2f& position, float Rotation = 0.0f);
            GameElement(float x, float y, float rotation = 0.0f);
            
            GameElement(void) = default;
            ~GameElement() = default;

        private:
            std::optional<glw::game::ecs::RigidBody> rigidBody = std::nullopt;
            
            glw::game::ecs::Transform transform;

            // Acccess to components

            constexpr glw::game::ecs::Transform& Transform(void) noexcept {
                return this->transform;
            }

            constexpr glw::game::ecs::RigidBody& RigidBody(void) noexcept {
                return this->rigidBody? *this->rigidBody : NullRigidBody;
            }

            // Component existence verification

            constexpr bool HasRigidBody(void) noexcept {
                glw::game::ecs::RigidBody& rigidBody = RigidBody();
                return !InvalidRigidBody(rigidBody);
            }
    };
}
