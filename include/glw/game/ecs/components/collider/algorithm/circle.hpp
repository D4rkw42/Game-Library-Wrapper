#pragma once

#include <glw/utils/math/math.hpp>

namespace glw::game::ecs::collider {
    struct _Circle {
        float x, y, radius;

        _Circle(float x, float y, float radius) {
            this->x = x;
            this->y = y;
            this->radius = radius;
        }
    };

    inline bool _CheckCircleCollision(const _Circle& objectA, const _Circle& objectB) noexcept {
        float minDist = (objectA.radius + objectB.radius) / 2;
        float dist = glw::math::Distance(objectA.x, objectA.y, objectB.x, objectB.y);

        return dist < minDist;
    }
}
