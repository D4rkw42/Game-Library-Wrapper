#pragma once

#include <glw/utils/math/vec2.hpp>

namespace glw::game::ecs {
    /// @brief Represents the rigid body for a game element to manage physical phenomena
    class RigidBody {
        public:
            glw::math::Vec2f Velocity, Acceleration, PreviousAcceleration; // px/s, px/s^2;
            float RotationVelocity = 0.0f; // rad/s
            
            float Restitution = 1.0f; // a.u
            float Mass = 1.0f; // a.u.

            float
                StaticAttrition     = 1.0f,
                DynamicAttriction   = 0.8f;

            // forces currently applied on body
            glw::math::Vec2f Forces; // a.u * px/s^2

            explicit RigidBody(float velX, float velY, float rotationVel, float mass);

            RigidBody(void) = default;
            ~RigidBody() = default;
            
            /// @brief Changes the element velocity
            /// @param velX velocity on horizontal axis `px/s`
            /// @param velY velocity on vertical axis `px/s`
            void ChangeVelocity(float velX, float velY) noexcept;
            /// @brief Changes the element velocity
            /// @param velocity the new velocity
            void ChangeVelocity(const glw::math::Vec2f& velocity) noexcept;

            /// @brief Changes the element angular velocity
            /// @param vel the angular velocity `rad/s`
            void ChangeAngularVelocity(float vel) noexcept;
            /// @brief Moves the element towards the direction disired
            /// @param vel the velocity `px/s`
            /// @param rotation the orientation of movement `rad`
            void MoveTowards(float vel, float rotation) noexcept;

            /// @brief Gets the velocity of element on its direction
            /// @return Its velocity `px/s`
            float GetVelocity(void) const noexcept;
            /// @brief Gets the rotation of element's movement direction
            /// @return Its movement direction `rad`
            float GetMovementDirection(void) const noexcept;
            
            /// @brief Applies an action force to the rigid body. The reaction force is applied automatically
            /// @param source the rigid body that gives origin to the force
            /// @param magnitude force's intensity
            /// @param direction  force's direction `rad`
            void ApplyActionForce(RigidBody& source, float magnitude, float direction) noexcept;
            /// @brief Applies a force to the element
            /// @param magnitude force's intensity
            /// @param direction force's direction `rad`
            void ApplyForce(float magnitude, float direction) noexcept;
            
            float GetWeight(float gravityAcceleration) const noexcept;
            float GetDensity(float volume) const noexcept;

            /// @brief Verifies if two rigid bodies are from the same element
            /// @return `true` if they are the same
            constexpr bool operator==(const RigidBody& rigidBody) const noexcept {
                return this == &rigidBody;
            }

            /// @brief Verifies if two rigid bodies are not from the same element
            /// @return `true` if they are different
            constexpr bool operator!=(const RigidBody& rigidBody) const noexcept {
                return this != &rigidBody;
            }
    };

    /// @brief An invalid rigid body
    inline RigidBody NullRigidBody;

    /// @brief Verifies if the rigid body is invalid
    /// @param rigidBody the rigid body to compare
    /// @return `true` if the rigid body is invalid
    constexpr bool InvalidRigidBody(const glw::game::ecs::RigidBody& rigidBody) noexcept {
        return rigidBody == glw::game::ecs::NullRigidBody;    
    }
}
