#pragma once

#include <glw/utils/math/vec2.hpp>

namespace glw::game::ecs {
    /// @brief Represents the absolute position and oriention of a game element in the world
    class Transform {
        public:
            glw::math::Vec2f Position;
            float Rotation = 0.0f;

            float
                Width = 0.0f,
                Height = 0.0f;

            explicit Transform(float x, float y, float width, float height, float rotation);

            Transform(void) = default;
            ~Transform() = default;

            /// @brief Moves the element incrementing position by deslocation
            /// @param x deslocation on horizontal axis `px`
            /// @param y deslocation on vertical axis `px`
            void Translate(float x, float y) noexcept;

            /// @brief Moves the element to the desired position
            /// @param x coordinate x `px`
            /// @param y coordinate y `px`
            void Move(float x, float y) noexcept;

            /// @brief Makes the element to look at the direction informed
            /// @param x the x coordinate to look at `px`
            /// @param y the y coordinate to look at `px`
            /// @param opposite if the element has to look in the opposite direction (default: `false`)
            void LookAt(float x, float y, bool opposite = false) noexcept;

            /// @brief Changes element's orientation
            /// @param rotation orientation `rad`
            void ChangeRotation(float rotation) noexcept;

            /// @brief Verifies if two transforms are from the same element
            /// @return `true` if they are the same
            constexpr bool operator==(const glw::game::ecs::Transform& transform) const noexcept {
                return this == &transform;
            }

            /// @brief Verifies if two transforms are not from the same element
            /// @return `true` if they are different
            constexpr bool operator!=(const glw::game::ecs::Transform& transform) const noexcept {
                return this != &transform;
            }
    };

    /// @brief An invalid transform
    inline Transform NullTransform;

    /// @brief Verifies if the transform is invalid
    /// @param transform the transform to compare
    /// @return `true` if the transform is invalid
    constexpr bool InvalidTransform(const glw::game::ecs::Transform& transform) noexcept {
        return transform == glw::game::ecs::NullTransform;
    }
}
