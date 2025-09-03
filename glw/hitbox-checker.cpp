#include <array>

#include <glw/game/ecs/components/collider/checker.hpp>

#include <glw/game/ecs/components/collider/algorithm/Circunference.hpp>
#include <glw/game/ecs/components/collider/algorithm/OOB.hpp>

#include <glw/utils/math/math.hpp>

bool glw::game::ecs::_CheckHitboxCollision(const std::shared_ptr<glw::game::ecs::Hitbox>& hitbox1, const std::shared_ptr<glw::game::ecs::Hitbox>& hitbox2) {
    if (hitbox1->Type == glw::game::ecs::HitboxType::RECTANGLE && hitbox2->Type == glw::game::ecs::HitboxType::RECTANGLE) {
        return glw::game::ecs::_CheckRectangleToRectangleCollision(hitbox1, hitbox2);
    } else if (hitbox1->Type == glw::game::ecs::HitboxType::CIRCUNFERENCE && hitbox2->Type == glw::game::ecs::HitboxType::CIRCUNFERENCE) {
        return _CheckCircunferenceToCircunferenceCollision(hitbox1, hitbox2);
    } else if (hitbox1->Type == glw::game::ecs::HitboxType::RECTANGLE && hitbox2->Type == glw::game::ecs::HitboxType::CIRCUNFERENCE) {
        return _CheckRectangleToCircunferenceCollision(hitbox1, hitbox2);
    } else if (hitbox1->Type == glw::game::ecs::HitboxType::CIRCUNFERENCE && hitbox2->Type == glw::game::ecs::HitboxType::RECTANGLE) {
        return _CheckRectangleToCircunferenceCollision(hitbox2, hitbox1);
    }

    return false;
}

//

bool glw::game::ecs::_CheckRectangleToRectangleCollision(const std::shared_ptr<glw::game::ecs::Hitbox>& hitbox1, const std::shared_ptr<glw::game::ecs::Hitbox>& hitbox2) {
    glw::game::ecs::collider::_OOB
        * oob1 = static_cast<glw::game::ecs::collider::_OOB*>(hitbox1->algorithm),
        * oob2 = static_cast<glw::game::ecs::collider::_OOB*>(hitbox2->algorithm);

    return glw::game::ecs::collider::_CheckOOBCollision(oob1, oob2);
}

bool glw::game::ecs::_CheckCircunferenceToCircunferenceCollision(const std::shared_ptr<glw::game::ecs::Hitbox>& hitbox1, const std::shared_ptr<glw::game::ecs::Hitbox>& hitbox2) {
    glw::game::ecs::collider::_Circunference
        * circunference1 = static_cast<glw::game::ecs::collider::_Circunference*>(hitbox1->algorithm),
        * circunference2 = static_cast<glw::game::ecs::collider::_Circunference*>(hitbox2->algorithm);
    
    return glw::game::ecs::collider::_CheckCircunferenceCollision(circunference1, circunference2);
}

/*
 * Hitbox 1 is type rectangle
 * Hitbox 2 is type circunference
 */
bool glw::game::ecs::_CheckRectangleToCircunferenceCollision(const std::shared_ptr<Hitbox>& hitbox1, const std::shared_ptr<Hitbox>& hitbox2) {
    glw::game::ecs::collider::_OOB* oob = static_cast<glw::game::ecs::collider::_OOB*>(hitbox1->algorithm);
    glw::game::ecs::collider::_Circunference* circunference = static_cast<glw::game::ecs::collider::_Circunference*>(hitbox2->algorithm);

    std::array<float, 2> pointRect = { oob->x, oob->y };
    std::array<float, 2> pointCirc = { circunference->x, circunference->y };
    std::array<float, 2> localPointCirc;

    glw::math::RotatePoint(pointRect, pointCirc, -oob->rotation, localPointCirc);

    float closestX = glw::math::Clamp(localPointCirc[0], -oob->width/2, oob->width/2);
    float closestY = glw::math::Clamp(localPointCirc[1], -oob->height/2, oob->height/2);

    float dist = glw::math::Distance(localPointCirc[0], localPointCirc[1], closestX, closestY);

    return dist < circunference->diameter/2;
}
