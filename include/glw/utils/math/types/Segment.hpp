#pragma once

#include <array>
#include <vector>

namespace glw::math {
    /// @brief Definition of math segment
    struct Segment {
        struct Func {
            float k, n;
        };

        struct Equation {
            Func x, y;
        };

        std::array<float, 2> origin, destination;
        Equation equation;

        Segment(const std::array<float, 2>& origin, const std::array<float, 2>& destination) : origin(origin), destination(destination) {
            this->equation.x.k = destination[0] - origin[0];
            this->equation.x.n = origin[0];
            this->equation.y.k = destination[1] - origin[1];
            this->equation.y.n = origin[1];
        }

        Segment(void) = default;

        Segment(const Segment&) = delete;
        Segment& operator=(const Segment&) = delete;

        Segment(Segment&& other) noexcept {
            this->equation = other.equation;
            this->origin = other.origin;
            this->destination = other.destination;
        }

        Segment& operator=(Segment&& other) noexcept {
            this->equation = other.equation;
            this->origin = other.origin;
            this->destination = other.destination;
            return *this;
        }

        bool CheckSegmentPoint(const std::array<float, 2>& point) const noexcept {
            bool horizontalAxis, verticalAxis;

            if (this->equation.x.k > 0) {
                horizontalAxis = point[0] >= this->origin[0] && point[0] <= this->destination[0];
            } else {
                horizontalAxis = point[0] >= this->destination[0] && point[0] <= this->origin[0];
            }

            if (this->equation.y.k > 0) {
                verticalAxis = point[1] >= this->origin[1] && point[1] <= this->destination[1];
            } else {
                verticalAxis = point[1] >= this->destination[1] && point[1] <= this->origin[1];
            }

            return horizontalAxis && verticalAxis;
        }
    };
}
