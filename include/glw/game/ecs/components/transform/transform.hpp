#pragma once

namespace glw::game::ecs {
    /// @brief Represents the absolute position and oriention of a game element in the world
    class Transform {
        public:
            float
                x =     0.0f, // px
                y =     0.0f, // px
                angle = 0.0f; // rad
            
            explicit Transform(float x, float y, float angle);

            Transform(void) = default;
            ~Transform() = default;

            /// @brief Moves the element inscrementing position by velocity
            /// @param velX velocity on horizontal axis `px/s`
            /// @param velY velocity on vertical axis `px/s`
            void Translate(float velX, float velY) noexcept;
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
            /// @param angle orientation `rad`
            void ChangeAngle(float angle) noexcept;

            /// @brief Verifies if two transforms are from the same element
            /// @return `true` if they are the same
            bool operator==(const glw::game::ecs::Transform& transform) const noexcept {
                return this == &transform;
            }
    };

    /// @brief An invalid transform
    inline Transform NullTransform;

    /// @brief Verifies if the transform is invalid
    /// @param transform the transform to compare
    /// @return `true` if the transform is invalid
    inline bool InvalidTransform(const glw::game::ecs::Transform& transform) noexcept {
        return transform == glw::game::ecs::NullTransform;
    }
}
