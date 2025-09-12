#pragma once

#include <array>

#include <glw/utils/math/math.hpp>

namespace glw::game::ecs::collider {
    class OOB {
        public:
            float x, y, width, height, rotation;

            std::array<float, 2> 
                axis[2],
                vertices[4];

            OOB(float x, float y, float width, float height, float rotation) {
                this->x = x;
                this->y = y;
                this->width = width;
                this->height = height;
                this->rotation = rotation;

                CalculateAxis();
                CalculateVertices();
            }

            inline void CalculateAxis(void) noexcept {
                this->axis[0] = { std::cos(this->rotation), std::sin(this->rotation) };
                this->axis[1] = { -std::sin(this->rotation), std::cos(this->rotation) };
            }

            inline void CalculateVertices(void) {
                for (int i = 0; i < 4; ++i) {
                    int xOffsetFactor = (i < 2)? 1 : -1;
                    int yOffsetFactor = (i > 0 && i < 3)? -1 : 1;

                    this->vertices[i] = {
                        this->x + this->width / 2 * xOffsetFactor * this->axis[0][0] + this->height / 2 * yOffsetFactor * this->axis[1][0],
                        this->y + this->width / 2 * xOffsetFactor * this->axis[0][1] + this->height / 2 * yOffsetFactor * this->axis[1][1]
                    };
                }
            }
    };

    inline std::array<float, 2> ProjectOOB(const OOB* oob, const std::array<float, 2> axis) noexcept {
        float min = glw::math::Dot(oob->vertices[0], axis);
        float max = min;

        for (int i = 0; i < 4; ++i) {
            float proj = glw::math::Dot(oob->vertices[i], axis);

            if (proj > max) {
                max = proj;
            }

            if (proj < min) {
                min = proj;
            }
        }

        return std::array<float, 2> { min, max };
    }

    constexpr bool OOBIntervalOverlap(const std::array<float, 2>& interval1, const std::array<float, 2>& interval2) noexcept {
        return !(interval1[1] <= interval2[0] || interval2[1] <= interval1[0]);
    }

    inline bool CheckOOBCollision(const OOB* objectA, const OOB* objectB) noexcept {
        const std::array<float, 2> axes[4] = { objectA->axis[0], objectA->axis[1], objectB->axis[0], objectB->axis[1] };

        // @TODO Apply AABB collision test before to lower proccessing

        for (int i = 0; i < 4; ++i) {
            const std::array<float, 2>& axis = axes[i];

            const std::array<float, 2> projA = ProjectOOB(objectA, axis);
            const std::array<float, 2> projB = ProjectOOB(objectB, axis);

            if (!OOBIntervalOverlap(projA, projB)) {
                return false;
            }
        }

        return true;
    }
}
