#pragma once

#include <array>

#include <glw/utils/math/trigonometry.hpp>

namespace glw::math {
    struct Circunference {
        std::array<float, 2> center;
        float diameter;

        std::array<float, 3> equation;

        Circunference(const std::array<float, 2>& center, float diameter) {
            this->center = center;
            this->diameter = diameter;

            this->equation = std::array<float, 3> { center[0], center[1], 1.0f/4 * diameter * diameter };
        }

        Circunference(void) = default;

        Circunference(const Circunference&) = delete;
        Circunference& operator=(const Circunference&) = delete;

        Circunference(Circunference&& other) noexcept {
            this->center = other.center;
            this->diameter = other.diameter;
            this->equation = other.equation;
        }

        Circunference& operator=(Circunference&& other) noexcept {
            this->center = other.center;
            this->diameter = other.diameter;
            this->equation = other.equation;
            return *this;
        }

        bool CheckCircunferencePoint(const std::array<float, 2>& point) const noexcept {
            float dist = glw::math::Distance(point, this->center);
            return dist <= this->diameter / 2 + 0.01f;
        }
    };
}
