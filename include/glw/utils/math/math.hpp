#pragma once

#include <cmath>
#include <array>

#include <glw/utils/math/vec2.hpp>

namespace glw::math {
    /// @brief PI constant value
    constexpr float PI = 3.1415927f;

    // math operations

    /// @brief Measures the distance between two points
    /// @param x1 x coordinate of first point
    /// @param y1 y coordinate of first point
    /// @param x2 x coordinate of second point
    /// @param y2 y coordinate of second point
    /// @return The distance between them
    inline float Distance(float x1, float y1, float x2, float y2) noexcept {
        float distX = x1 - x2;
        float distY = y1 - y2;

        return std::sqrt(distX * distX + distY * distY);
    }

    constexpr float Rad(float degree) noexcept {
        return degree * PI / 180;
    }

    // vector operations

    /// @brief Decomposes a 2D vector (cartesian plane) to its component vectors
    /// @param magnitude vector's intensity
    /// @param direction vectors's direction `rad`
    /// @param decomposedX the vector in x-axis
    /// @param decomposedY the vector in y-axis
    constexpr void DecomposeVector(float magnitude, float direction, float& decomposedX, float& decomposedY) noexcept {
        decomposedX = magnitude * std::cos(direction);
        decomposedY = magnitude * std::sin(direction);
    }

    // linear algebra

    /// @brief Calculates the escalar product
    /// @param point the point projected in the vector
    /// @param vector the vector to calculate the projectio
    /// @return The escalar product
    constexpr float EscalarProduct(const std::array<float, 2>& point, const std::array<float, 2>& vector) noexcept {
        return point[0] * vector[0] + point[1] * vector[1];
    }
}
