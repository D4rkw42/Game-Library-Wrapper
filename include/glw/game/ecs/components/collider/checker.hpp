#pragma once

#include <glw/game/ecs/components/collider/Hitbox.hpp>

namespace glw::game::ecs {
    bool _CheckHitboxCollision(const std::shared_ptr<Hitbox>& hitbox1, const std::shared_ptr<Hitbox>& hitbox2);

    // Collision options

    bool _CheckRectangleToRectangleCollision(const std::shared_ptr<Hitbox>& hitbox1, const std::shared_ptr<Hitbox>& hitbox2);
    bool _CheckCircunferenceToCircunferenceCollision(const std::shared_ptr<Hitbox>& hitbox1, const std::shared_ptr<Hitbox>& hitbox2);
    bool _CheckRectangleToCircunferenceCollision(const std::shared_ptr<Hitbox>& hitbox1, const std::shared_ptr<Hitbox>& hitbox2);
}
