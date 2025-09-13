#include <array>

#include <glw/game/ecs/components/collider/hitbox-checker.hpp>

#include <glw/game/ecs/components/collider/algorithm/Circunference.hpp>
#include <glw/game/ecs/components/collider/algorithm/OOB.hpp>

#include <glw/game/ecs/components/collider/algorithm/cross-check.hpp>

bool glw::game::ecs::CheckHitboxCollision(const std::shared_ptr<glw::game::ecs::Hitbox>& hitbox1, const std::shared_ptr<glw::game::ecs::Hitbox>& hitbox2) {
    if (hitbox1->Type == glw::game::ecs::HitboxType::RECTANGLE && hitbox2->Type == glw::game::ecs::HitboxType::RECTANGLE) {
        return glw::game::ecs::CheckRectangleToRectangleCollision(hitbox1, hitbox2);
    } else if (hitbox1->Type == glw::game::ecs::HitboxType::CIRCUNFERENCE && hitbox2->Type == glw::game::ecs::HitboxType::CIRCUNFERENCE) {
        return CheckCircunferenceToCircunferenceCollision(hitbox1, hitbox2);
    } else if (hitbox1->Type == glw::game::ecs::HitboxType::RECTANGLE && hitbox2->Type == glw::game::ecs::HitboxType::CIRCUNFERENCE) {
        return CheckRectangleToCircunferenceCollision(hitbox1, hitbox2);
    } else if (hitbox1->Type == glw::game::ecs::HitboxType::CIRCUNFERENCE && hitbox2->Type == glw::game::ecs::HitboxType::RECTANGLE) {
        return CheckRectangleToCircunferenceCollision(hitbox2, hitbox1);
    }

    return false;
}

//

bool glw::game::ecs::CheckRectangleToRectangleCollision(const std::shared_ptr<glw::game::ecs::Hitbox>& hitbox1, const std::shared_ptr<glw::game::ecs::Hitbox>& hitbox2) {
    glw::game::ecs::OOB
        * oob1 = static_cast<glw::game::ecs::OOB*>(hitbox1->algorithm),
        * oob2 = static_cast<glw::game::ecs::OOB*>(hitbox2->algorithm);

    return glw::game::ecs::CheckOOBCollision(oob1, oob2);
}

bool glw::game::ecs::CheckCircunferenceToCircunferenceCollision(const std::shared_ptr<glw::game::ecs::Hitbox>& hitbox1, const std::shared_ptr<glw::game::ecs::Hitbox>& hitbox2) {
    glw::game::ecs::Circunference
        * circunference1 = static_cast<glw::game::ecs::Circunference*>(hitbox1->algorithm),
        * circunference2 = static_cast<glw::game::ecs::Circunference*>(hitbox2->algorithm);
    
    return glw::game::ecs::CheckCircunferenceCollision(circunference1, circunference2);
}

/*
 * Hitbox 1 is type rectangle
 * Hitbox 2 is type circunference
 */
bool glw::game::ecs::CheckRectangleToCircunferenceCollision(const std::shared_ptr<Hitbox>& hitbox1, const std::shared_ptr<Hitbox>& hitbox2) {
    glw::game::ecs::OOB* oob = static_cast<glw::game::ecs::OOB*>(hitbox1->algorithm);
    glw::game::ecs::Circunference* circunference = static_cast<glw::game::ecs::Circunference*>(hitbox2->algorithm);

    return glw::game::ecs::CheckOOBvsCircunferenceCollision(oob, circunference);
}
