#pragma once

#include <glw/utils/math/math.hpp>

namespace glw::game::ecs::collider {
    struct Circunference {
        float x, y, diameter;

        Circunference(float x, float y, float diameter) {
            this->x = x;
            this->y = y;
            this->diameter = diameter;
        }
    };

    inline bool CheckCircunferenceCollision(const Circunference* objectA, const Circunference* objectB) noexcept {
        float minDist = (objectA->diameter + objectB->diameter) / 2;
        float dist = glw::math::Distance(objectA->x, objectA->y, objectB->x, objectB->y);

        return dist < minDist;
    }
}
