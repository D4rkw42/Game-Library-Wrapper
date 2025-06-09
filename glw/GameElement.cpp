#include <glw/game/ecs/types/GameElement.hpp>

glw::game::ecs::GameElement::GameElement(float x, float y, float rotation) : GameElement(glw::math::Vec2f(x, y), rotation) {}

glw::game::ecs::GameElement::GameElement(const glw::math::Vec2f& position, float rotation) {
    Transform().Position = position;
    Transform().Rotation = rotation;

    this->rigidBody = glw::game::ecs::RigidBody();
}
