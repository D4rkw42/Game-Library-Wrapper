#pragma once

#include <cmath>
#include <vector>
#include <array>

#include <glw/utils/math/constants.hpp>

namespace glw::math {
/// @brief Converts degree to rad
    /// @param degree the angle `degree`
    /// @return The angle converted `rad`
    constexpr float Rad(float degree) noexcept {
        return degree * glw::math::PI / 180;
    }

    /// @brief Calculates the opposite angle (aka antipodal angle)
    /// @param rad the angle `rad`
    /// @return The opposite angle in the circunference `rad`
    constexpr float OppositeAngle(float rad) noexcept {
        rad += Rad(180);
        return (rad >= Rad(360))? rad - Rad(360) : rad;
    }

    /// @brief Clamps a value to the range
    /// @param value the value to clamp
    /// @param max the max value
    /// @param min the min value
    /// @return The clamped value
    constexpr float Clamp(float value, float min, float max) noexcept {
        if (value > max) {
            return max;
        } else if (value < min) {
            return min;
        }

        return value;
    }
}
