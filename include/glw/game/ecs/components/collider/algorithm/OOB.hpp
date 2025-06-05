#pragma once

#include <array>

#include <glw/utils/math/math.hpp>

namespace glw::game::ecs::collider {
    class _OOB {
        public:
            float x, y, width, height, angle;

            std::array<float, 2> 
                axis[2],
                vertices[4];

            _OOB(float x, float y, float width, float height, float angle) {
                this->x = x;
                this->y = y;
                this->width = width;
                this->height = height;
                this->angle = angle;

                _CalculateAxis();
                _CalculateVertices();
            }

            inline void _CalculateAxis(void) noexcept {
                this->axis[0] = { std::cos(this->angle), std::sin(this->angle) };
                this->axis[1] = { -std::sin(this->angle), std::cos(this->angle) };
            }

            inline void _CalculateVertices(void) {
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

    inline std::array<float, 2> _ProjectOOB(const _OOB& oob, const std::array<float, 2>& axis) noexcept {
        float min = glw::math::EscalarProduct(oob.vertices[0], axis);
        float max = min;

        for (int i = 0; i < 4; ++i) {
            float proj = glw::math::EscalarProduct(oob.vertices[i], axis);

            if (proj > max) {
                max = proj;
            }

            if (proj < min) {
                min = proj;
            }
        }

        return std::array<float, 2> { min, max };
    }

    constexpr bool _OOBIntervalOverlap(const std::array<float, 2>& interval1, const std::array<float, 2>& interval2) noexcept {
        return !(interval1[1] <= interval2[0] || interval2[1] <= interval1[0]);
    }

    inline bool _CheckOOBCollision(const _OOB& objectA, const _OOB& objectB) noexcept {
        const std::array<float, 2> axes[4] = { objectA.axis[0], objectA.axis[1], objectB.axis[0], objectB.axis[1] };

        // @TODO Apply AABB collision test before to lower proccessing

        for (int i = 0; i < 4; ++i) {
            const std::array<float, 2>& axis = axes[i];

            const std::array<float, 2> projA = _ProjectOOB(objectA, axis);
            const std::array<float, 2> projB = _ProjectOOB(objectB, axis);

            if (!_OOBIntervalOverlap(projA, projB)) {
                return false;
            }
        }

        return true;
    }
}
