#pragma once

#include <glw/utils/math/math.hpp>

namespace glw::game::ecs {
    struct Circunference {
        float x, y, diameter, rotation; // this only have rotation because visual glitches

        Circunference(float x, float y, float diameter, float rotation) {
            this->x = x;
            this->y = y;
            this->diameter = diameter;
            this->rotation = rotation;
        }
    };

    inline bool CheckCircunferenceCollision(const Circunference* objectA, const Circunference* objectB) noexcept {
        float minDist = (objectA->diameter + objectB->diameter) / 2;
        float dist = glw::math::Distance(objectA->x, objectA->y, objectB->x, objectB->y);

        return dist < minDist;
    }
}
