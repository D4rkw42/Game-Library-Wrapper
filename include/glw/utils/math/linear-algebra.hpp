#pragma once

#include <vector>
#include <array>

namespace glw::math {
    /// @brief Rotates a point relative to a center
    /// @param center the center of rotation
    /// @param point the point to be rotated
    /// @param rotation the rotation `rad`
    /// @param newPoint the new point
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

    constexpr void RotatePoint(const std::vector<float>& center, const std::vector<float>& point, float rotation, std::vector<float>& newPoint) {
        float vectorX = point[0] - center[0];
        float vectorY = point[1] - center[1];

        float cos = std::cos(rotation); // @TODO trocar para função otimizada no futuro
        float sin = std::sin(rotation); // @TODO trocar para função otimizada no futuro

        float xOffset = vectorX * cos - vectorY * sin;
        float yOffset = vectorX * sin + vectorY * cos;

        newPoint[0] = center[0] + xOffset;
        newPoint[1] = center[1] + yOffset;
    }

    constexpr void RotatePoint(float centerX, float centerY, float pointX, float pointY, float rotation, float& newPointX, float& newPointY) noexcept {
        float vectorX = pointX - centerX;
        float vectorY = pointY - centerY;

        float cos = std::cos(rotation); // @TODO trocar para função otimizada no futuro
        float sin = std::sin(rotation); // @TODO trocar para função otimizada no futuro

        float xOffset = vectorX * cos - vectorY * sin;
        float yOffset = vectorX * sin + vectorY * cos;

        newPointX = centerX + xOffset;
        newPointY = centerY + yOffset;
    }

    // * linear algebra ** 

    /// @brief Calculates the escalar product
    /// @param point the point projected in the vector
    /// @param vector the vector to calculate the projection
    /// @return The escalar product
    constexpr float Dot(const std::array<float, 2>& point, const std::array<float, 2>& vector) noexcept {
        return point[0] * vector[0] + point[1] * vector[1];
    }

    constexpr float Dot(const std::vector<float>& point, const std::vector<float>& vector) {
        return point[0] * vector[0] + point[1] * vector[1];
    }

    constexpr float Dot(float pointX, float pointY, float vectorX, float vectorY) {
        return pointX * vectorX + pointY * vectorY;
    }
}
