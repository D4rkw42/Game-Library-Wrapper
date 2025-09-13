#pragma once

#include <array>

namespace glw::math {
    struct Circunference {
        std::array<float, 2> center;
        float diameter;

        Circunference(const std::array<float, 2>& center, float diameter) {
            this->center = center;
            this->diameter = diameter;
        }

        // (x - a)^2 + (y - b)^2 = r^2
        inline std::array<float, 3> GetEquation(void) const noexcept {
            return std::array<float, 3> { -center[0], -center[1], 1.0f/4 * diameter * diameter }; // a, b, r^2
        }
    };
}
