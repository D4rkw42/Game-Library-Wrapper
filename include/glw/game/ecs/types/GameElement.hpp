#pragma once

#include <memory>
#include <optional>

#include <glw/graphics/Window.hpp>

#include <glw/game/ecs/components/transform/Transform.hpp>
#include <glw/game/ecs/components/rigid-body/RigidBody.hpp>
#include <glw/game/ecs/components/collider/Collider.hpp>

#include <glw/utils/math/vec2.hpp>

namespace glw::game::ecs {
    class GameElement {
        public:
            GameElement(const glw::math::Vec2f& position, float Rotation = 0.0f);
            GameElement(float x, float y, float rotation = 0.0f);
            
            GameElement(void) = default;
            ~GameElement() = default;

            // Acccess to components
    
            constexpr glw::game::ecs::Transform& Transform(void) noexcept {
                return this->transform;
            }

            constexpr glw::game::ecs::RigidBody& RigidBody(void) noexcept {
                return this->rigidBody;
            }

            constexpr glw::game::ecs::Collider& Collider(void) noexcept {
                return this->collider? *this->collider : NullCollider;
            } 
    
            // Component existence verification
    
            constexpr bool HasCollider(void) noexcept {
                const glw::game::ecs::Collider& collider = Collider();
                return !InvalidCollider(collider);
            }

        private:
            std::optional<glw::game::ecs::Collider> collider = std::nullopt;
            
            glw::game::ecs::Transform transform;
            glw::game::ecs::RigidBody rigidBody;

        public:
            // System controlling and mandadory function calling

            void LoadElement(float dt); // atualiza definições do elemento. Chama as atualizações de Transform. Usado apenas quando não se aplica física da lib
            void RenderElement(const std::shared_ptr<glw::graphics::WindowWrapper>& window); // renderiza o elemento. Executa as funções internas de Renderable
    };
}
