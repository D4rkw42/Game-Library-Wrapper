#pragma once

#include <glw/game/ecs/components/collider/Hitbox.hpp>

namespace glw::game::ecs {
    bool CheckHitboxCollision(const std::shared_ptr<Hitbox>& hitbox1, const std::shared_ptr<Hitbox>& hitbox2);

    // Collision options

    bool CheckRectangleToRectangleCollision(const std::shared_ptr<Hitbox>& hitbox1, const std::shared_ptr<Hitbox>& hitbox2);
    bool CheckCircunferenceToCircunferenceCollision(const std::shared_ptr<Hitbox>& hitbox1, const std::shared_ptr<Hitbox>& hitbox2);
    bool CheckRectangleToCircunferenceCollision(const std::shared_ptr<Hitbox>& hitbox1, const std::shared_ptr<Hitbox>& hitbox2);
}
