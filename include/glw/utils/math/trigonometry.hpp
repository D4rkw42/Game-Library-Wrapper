#pragma once

#include <vector>
#include <array>

namespace glw::math {
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

    inline float Distance(const std::vector<float>& p1, const std::vector<float>& p2) {
        return Distance(p1[0], p1[1], p2[0], p2[1]);
    }

    inline float Distance(const std::array<float, 2>& p1, const std::array<float, 2>& p2) noexcept {
        return Distance(p1[0], p1[1], p2[0], p2[1]);
    }

    /// @brief Gets the angle between two points
    /// @param x1 x coordinate of object 1
    /// @param y1 y coordinate of object 1
    /// @param x2 x coordinate of object 2
    /// @param y2 y coordinate of object 2
    /// @return The angle `rad`
    constexpr float AngleBetweenPoints(float x1, float y1, float x2, float y2) noexcept {
        return std::atan2(y1 - y2, x1 - x2);
    }

    constexpr float AngleBetweenPoints(const std::vector<float>& p1, const std::vector<float>& p2) {
        return AngleBetweenPoints(p1[0], p1[1], p2[0], p2[1]);
    }

    constexpr float AngleBetweenPoints(const std::array<float, 2>& p1, const std::array<float, 2>& p2) noexcept {
        return AngleBetweenPoints(p1[0], p1[1], p2[0], p2[1]);
    }

    // ** vector operations **

    /// @brief Decomposes a 2D vector (cartesian plane) to its component vectors
    /// @param magnitude vector's intensity
    /// @param direction vectors's direction `rad`
    /// @param decomposedX the vector in x-axis
    /// @param decomposedY the vector in y-axis
    constexpr void DecomposeVector(float magnitude, float direction, float& decomposedX, float& decomposedY) noexcept {
        decomposedX = magnitude * std::cos(direction);
        decomposedY = magnitude * std::sin(direction);
    }

    constexpr void DescribeVector(float magnitude, float direction, std::vector<float>& described) noexcept {
        float decomposedX = 0.0f;
        float decomposedY = 0.0f;

        DecomposeVector(magnitude, direction, decomposedX, decomposedY);
        described = { decomposedX, decomposedY };
    }

    constexpr void DescribeVector(float magnitude, float direction, std::array<float, 2>& described) noexcept {
        float decomposedX = 0.0f;
        float decomposedY = 0.0f;

        DecomposeVector(magnitude, direction, decomposedX, decomposedY);
        described = { decomposedX, decomposedY };
    }
}
