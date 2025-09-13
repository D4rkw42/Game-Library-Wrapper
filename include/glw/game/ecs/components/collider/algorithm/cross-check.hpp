#pragma once

#include <array>

#include <glw/game/ecs/components/collider/algorithm/OOB.hpp>
#include <glw/game/ecs/components/collider/algorithm/Circunference.hpp>

#include <glw/utils/math/math.hpp>

namespace glw::game::ecs {
    inline bool CheckOOBvsCircunferenceCollision(const glw::game::ecs::OOB* oob, const glw::game::ecs::Circunference* circunference) {
        std::array<float, 2> pointRect = { oob->x, oob->y };
        std::array<float, 2> pointCirc = { circunference->x, circunference->y };
        std::array<float, 2> localPointCirc;

        glw::math::RotatePoint(pointRect, pointCirc, -oob->rotation, localPointCirc);

        localPointCirc[0] -= oob->x;
        localPointCirc[1] -= oob->y;

        float closestX = glw::math::Clamp(localPointCirc[0], -oob->width/2, oob->width/2);
        float closestY = glw::math::Clamp(localPointCirc[1], -oob->height/2, oob->height/2);

        float dist = glw::math::Distance(localPointCirc[0], localPointCirc[1], closestX, closestY);

        return dist < circunference->diameter/2;
    }
}
