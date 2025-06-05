#pragma once

#include <cmath>

namespace glw::game::ecs::collider {
    struct _AABB {
        float x, y, width, height;

        _AABB(float x, float y, float width, float height) {
            this->x = x;
            this->y = y;
            this->width = width;
            this->height = height;
        }
    };

    inline bool _CheckAABBCollision(const _AABB& objectA, const _AABB& objectB) noexcept {
        float minDistX = (objectA.width + objectB.width) / 2;
        float minDistY = (objectA.height + objectA.height) / 2;

        float distX = std::abs(objectA.x - objectB.x);
        float distY = std::abs(objectA.y - objectB.y);

        return distX < minDistX && distY < minDistY;
    }
}
