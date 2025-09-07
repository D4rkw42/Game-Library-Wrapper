#include <glw/game/ecs/types/GameElement.hpp>

#include <glw/game/physics/physics.hpp>
#include <glw/graphics/geometry/geometry.hpp> // @TEMPORARY

glw::game::ecs::GameElement::GameElement(float x, float y, float rotation) : GameElement(glw::math::Vec2f(x, y), rotation) {}

glw::game::ecs::GameElement::GameElement(const glw::math::Vec2f& position, float rotation) {
    Transform().Position = position;
    Transform().Rotation = rotation;
}

// 

void glw::game::ecs::GameElement::LoadElement(float dt) {
    glw::game::ecs::Transform& transform = Transform();
    glw::game::ecs::Collider& collider = Collider();

    glw::game::physics::integrators::VelocityVerlet(transform, RigidBody(), dt);

    transform.Rotation += RigidBody().RotationVelocity * dt;

    if (!glw::game::ecs::InvalidCollider(collider)) {
        collider.Update(transform.Position, transform.Rotation);
    }
}

void glw::game::ecs::GameElement::RenderElement(const std::shared_ptr<glw::graphics::WindowWrapper>& window) {
    // @TEMPORARY
    glw::graphics::FillRectangle(window, Transform().Position.x, Transform().Position.y, Transform().Width, Transform().Height, Transform().Rotation, glw::graphics::Colors::BLACK);
}
