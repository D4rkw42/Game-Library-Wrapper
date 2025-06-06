#pragma once

namespace glw::game::ecs {
    /// @brief Represents the rigid body for a game element to manage physical phenomena
    class RigidBody {
        public:
            float
                velX =      0.0f, // px/s
                velY =      0.0f, // px/s
                angleVel =  0.0f; // rad/s

            float mass =    1.0f; // a.u.

            explicit RigidBody(float velX, float velY, float angleVel, float mass);

            RigidBody(void) = default;
            ~RigidBody() = default;
            
            /// @brief Changes the element velocity
            /// @param velX velocity on horizontal axis `px/s`
            /// @param velY velocity on vertical axis `px/s`
            void ChangeVelocity(float velX, float velY) noexcept;
            /// @brief Changes the element angular velocity
            /// @param vel the angular velocity `rad/s`
            void ChangeAngularVelocity(float vel) noexcept;
            /// @brief Moves the element towards the direction disired
            /// @param vel the velocity `px/s`
            /// @param angle the orientation of movement `rad`
            void MoveTowards(float vel, float angle) noexcept;

            /// @brief Gets the velocity of element on its direction
            /// @return Its velocity `px/s`
            float GetVelocity(void) const noexcept;
            /// @brief Gets the angle of element's movement direction
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
            
            float _GetWeight(float gravityAcceleration) const noexcept;
            float _GetDensity(float volume) const noexcept;

            float _GetForcesX(void) const noexcept;
            float _GetForcesY(void) const noexcept;

            /// @brief Verifies if two rigid bodies are from the same element
            /// @return `true` if they are the same
            bool operator==(const RigidBody& rigidBody) const noexcept {
                return this == &rigidBody;
            }
        
        private:
            float
                forcesX = 0.0f, // a.u * px/s^2
                forcesY = 0.0f; // a.u * px/s^2
    };

    /// @brief An invalid rigid body
    inline RigidBody NullRigidBody;

    /// @brief Verifies if the rigid body is invalid
    /// @param rigidBody the rigid body to compare
    /// @return `true` if the rigid body is invalid
    inline bool InvalidRigidBody(const glw::game::ecs::RigidBody& rigidBody) noexcept {
        return rigidBody == glw::game::ecs::NullRigidBody;    
    }
}
