#pragma once

#include <cmath>

namespace glw::game::ecs {
    struct AABB {
        float x, y, width, height;

        AABB(float x, float y, float width, float height) {
            this->x = x;
            this->y = y;
            this->width = width;
            this->height = height;
        }
    };

    inline bool CheckAABBCollision(const AABB& objectA, const AABB& objectB) noexcept {
        float minDistX = (objectA.width + objectB.width) / 2;
        float minDistY = (objectA.height + objectA.height) / 2;

        float distX = std::abs(objectA.x - objectB.x);
        float distY = std::abs(objectA.y - objectB.y);

        return distX < minDistX && distY < minDistY;
    }
}
