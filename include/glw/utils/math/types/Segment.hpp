#pragma once

#include <array>
#include <vector>

namespace glw::math {
    /// @brief Definition of math segment
    struct Segment {
        std::array<float, 2> origin, destination;

        Segment(const std::array<float, 2>& origin, const std::array<float, 2>& destination) {
            this->origin = origin;
            this->destination = destination;
        }

        // y = ax + b
        inline std::array<float, 2> GetEquation(void) const noexcept {
            float x1 = this->origin[0];
            float y1 = this->origin[1];

            float x2 = this->destination[0];
            float y2 = this->destination[1];

            float a = (y2 - y1) / (x2 - x1);
            float b = y1 - a * x1;

            return std::array<float, 2> { a, b }; // a, b
        }
    };
}
