#include <glw/game/ecs/types/GameElement.hpp>

#include <glw/game/physics/physics.hpp>

glw::game::ecs::GameElement::GameElement(float x, float y, float rotation) : GameElement(glw::math::Vec2f(x, y), rotation) {}

glw::game::ecs::GameElement::GameElement(const glw::math::Vec2f& position, float rotation) {
    Transform().Position = position;
    Transform().Rotation = rotation;
}

// 

void glw::game::ecs::GameElement::LoadElement(float dt) {
    glw::game::ecs::Collider& collider = Collider();

    // load renderable

    if (!glw::game::ecs::InvalidCollider(collider)) {
        collider.Update(transform.Position, transform.Rotation);
    }
}

void glw::game::ecs::GameElement::RenderElement(const std::shared_ptr<glw::graphics::WindowWrapper>& window) {
    // load rendarable
}
