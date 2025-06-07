#pragma once

#include <cstdint>

namespace glw::math {
    template <typename T>
    class Vec2 {
        public:
            T x, y;

            Vec2(T x, T y) : x(x), y(y) {};
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
    using Vec2d = Vec2<double>;
}
