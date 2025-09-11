#pragma once

#include <cstdint>
#include <array>
#include <vector>

#include <glw/utils/math/trigonometry.hpp>
#include <glw/utils/math/linear-algebra.hpp>

namespace glw::math {
    template <typename T>
    class Vec2 {
        public:
            T x, y;

            Vec2(T x, T y)                      : x(x), y(y) {};
            Vec2(const Vec2& vec)               : Vec2(vec.x, vec.y) {};
            Vec2(const std::vector<T>& vec)     : Vec2(vec[0], vec[1]) {};
            Vec2(const std::array<T, 2>& vec)   : Vec2(vec[0], vec[1]) {};

            Vec2(void) : Vec2(0.0f, 0.0f) {};
            ~Vec2() = default;

            // Operators

            constexpr Vec2 operator+(const Vec2& vec) const noexcept {
                return Vec2(this->x + vec.x, this->y + vec.y);
            }

            constexpr Vec2 operator-(const Vec2& vec) const noexcept {
                return Vec2(this->x - vec.x, this->y - vec.y);
            }

            constexpr Vec2 operator*(T value) const noexcept {
                return Vec2(this->x * value, this->y * value);
            }

            constexpr Vec2 operator/(T value) const noexcept {
                return Vec2(this->x / value, this->y / value);
            }

            constexpr void operator=(const Vec2& vec) noexcept {
                this->x = vec.x;
                this->y = vec.y;
            }

            constexpr void operator=(const std::vector<T>& vec) {
                this->x = vec[0];
                this->y = vec[1];
            }

            constexpr void operator=(const std::array<T, 2>& vec) noexcept {
                this->x = vec[0];
                this->y = vec[1];
            }

            constexpr void operator+=(const Vec2& vec) noexcept {
                this->x += vec.x;
                this->y += vec.y;
            }

            constexpr void operator-=(const Vec2& vec) noexcept {
                this->x -= vec.x;
                this->y -= vec.y;
            }

            constexpr void operator*=(T value) noexcept {
                this->x *= value;
                this->y *= value;
            }

            constexpr void operator/=(T value) noexcept {
                this->x /= value;
                this->y /= value;
            }
    };

    using Vec2i = Vec2<int>;
    using Vec2ui = Vec2<unsigned>;

    using Vec2ui16 = Vec2<std::uint16_t>;
    using Vec2ui32 = Vec2<std::uint32_t>;
    using Vec2ui64 = Vec2<std::uint64_t>;

    using Vec2f = Vec2<float>;

    // operations

    template <typename T>
    inline float Distance(const glw::math::Vec2<T>& p1, const glw::math::Vec2<T>& p2) noexcept {
        return Distance(p1.x, p1.y, p2.x, p2.y);
    }

    template <typename T>
    constexpr float AngleBetweenPoints(const glw::math::Vec2<T>& p1, const glw::math::Vec2<T>& p2) noexcept {
        return AngleBetweenPoints(p1.x, p1.y, p2.x, p2.y);
    }

    template <typename T>
    inline void DescribeVector(float magnitude, float direction, glw::math::Vec2<T>& described) noexcept {
        float decomposedX = 0.0f;
        float decomposedY = 0.0f;

        DecomposeVector(magnitude, direction, decomposedX, decomposedY);
        described = glw::math::Vec2<T>(decomposedX, decomposedY);
    }

    template <typename T>
    constexpr void RotatePoint(const glw::math::Vec2<T>& center, const glw::math::Vec2<T>& point, float rotation, glw::math::Vec2<T>& newPoint) noexcept {
        float vectorX = point.x - center.x;
        float vectorY = point.y - center.y;

        float cos = std::cos(rotation); // @TODO trocar para função otimizada no futuro
        float sin = std::sin(rotation); // @TODO trocar para função otimizada no futuro

        float xOffset = vectorX * cos - vectorY * sin;
        float yOffset = vectorX * sin + vectorY * cos;

        newPoint.x = center.x + xOffset;
        newPoint.y = center.y + yOffset;
    }

    template <typename T>
    constexpr float EscalarProduct(const glw::math::Vec2<T>& point, const glw::math::Vec2<T>& vector) {
        return point.x * vector.x + point.y * vector.y;
    }
}
