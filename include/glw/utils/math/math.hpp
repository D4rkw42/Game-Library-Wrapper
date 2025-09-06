#pragma once

#include <cmath>
#include <array>

#include <glw/utils/math/vec2.hpp>

namespace glw::math {
    /// @brief PI constant value
    constexpr float PI = 3.1415927f;

    // ** math operations **

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

    /// @brief Converts degree to rad
    /// @param degree the angle `degree`
    /// @return The angle converted `rad`
    constexpr float Rad(float degree) noexcept {
        return degree * PI / 180;
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


    /// @brief Rotates a point relative to a center
    /// @param center the center of rotation
    /// @param point the point to be rotated
    /// @param rotation the rotation `rad`
    /// @param newPoint the ne w point
    constexpr void RotatePoint(const std::array<float, 2>& center, const std::array<float, 2>& point, float rotation, std::array<float, 2>& newPoint) noexcept {
        float vectorX = point[0] - center[0];
        float vectorY = point[1] - center[1];

        float cos = std::cos(rotation); // @TODO trocar para função otimizada no futuro
        float sin = std::sin(rotation); // @TODO trocar para função otimizada no futuro

        float xOffset = vectorX * cos - vectorY * sin;
        float yOffset = vectorX * sin + vectorY * cos;

        newPoint[0] = center[0] + xOffset;
        newPoint[1] = center[1] + yOffset;
    }

    // * linear algebra ** 

    /// @brief Calculates the escalar product
    /// @param point the point projected in the vector
    /// @param vector the vector to calculate the projection
    /// @return The escalar product
    constexpr float EscalarProduct(const std::array<float, 2>& point, const std::array<float, 2>& vector) noexcept {
        return point[0] * vector[0] + point[1] * vector[1];
    }
}
