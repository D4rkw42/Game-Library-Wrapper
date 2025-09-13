#pragma once

#include <cmath>

#include <glw/game/ecs/components/transform/Transform.hpp>
#include <glw/game/ecs/components/rigid-body/RigidBody.hpp>

#include <glw/utils/math/types/vec2.hpp>

namespace glw::game::physics::integrator {
    inline void Kinematic(glw::game::ecs::Transform& transform, glw::game::ecs::RigidBody& rigidBody, float dt) noexcept {
        glw::math::Vec2f acc = rigidBody.Forces / rigidBody.Mass;
        rigidBody.PreviousAcceleration = rigidBody.Acceleration;
        rigidBody.Acceleration = acc;

        rigidBody.Velocity += rigidBody.Acceleration * dt;
        transform.Position += rigidBody.Velocity * dt + rigidBody.Acceleration * (1.0f/2 * dt * dt);
    }

    inline void Euler(glw::game::ecs::Transform& transform, glw::game::ecs::RigidBody& rigidBody, float dt) noexcept {
        glw::math::Vec2f acc = rigidBody.Forces / rigidBody.Mass;
        rigidBody.PreviousAcceleration = rigidBody.Acceleration;
        rigidBody.Acceleration = acc;

        transform.Position += rigidBody.Velocity * dt;
        rigidBody.Velocity += acc * dt;
    }

    inline void EulerCromer(glw::game::ecs::Transform& transform, glw::game::ecs::RigidBody& rigidBody, float dt) noexcept {
        glw::math::Vec2f acc = rigidBody.Forces / rigidBody.Mass;
        rigidBody.PreviousAcceleration = rigidBody.Acceleration;
        rigidBody.Acceleration = acc;

        rigidBody.Velocity += acc * dt;
        transform.Position += rigidBody.Velocity * dt;
    }

    inline void VelocityVerlet(glw::game::ecs::Transform& transform, glw::game::ecs::RigidBody& rigidBody, float dt) noexcept {
        rigidBody.Velocity += rigidBody.Acceleration * (0.5f * dt);
        transform.Position += rigidBody.Velocity * dt;

        glw::math::Vec2f acc = rigidBody.Forces / rigidBody.Mass;
        rigidBody.PreviousAcceleration = rigidBody.Acceleration;
        rigidBody.Acceleration = acc;

        rigidBody.Velocity += rigidBody.Acceleration * (0.5f * dt);
    }

    inline void Leapfrog(glw::game::ecs::Transform& transform, glw::game::ecs::RigidBody& rigidBody, float dt) noexcept {
        glw::math::Vec2f vHalf = rigidBody.Velocity + rigidBody.Acceleration * (0.5f * dt);
        transform.Position += vHalf * dt;

        glw::math::Vec2f acc = rigidBody.Forces / rigidBody.Mass;
        rigidBody.PreviousAcceleration = rigidBody.Acceleration;
        rigidBody.Acceleration = acc;

        rigidBody.Velocity = vHalf + acc * (0.5f * dt);
    }

    inline void Beeman(glw::game::ecs::Transform& transform, glw::game::ecs::RigidBody& rigidBody, float dt) noexcept {
        glw::math::Vec2f
            prevAcc = rigidBody.PreviousAcceleration,
            acc = rigidBody.Acceleration,
            newAcc = glw::math::Vec2f();

        transform.Position += rigidBody.Velocity * dt + (acc * 2.0f/3 * dt * dt) - (prevAcc * 1.0f/6 * dt * dt);

        newAcc = rigidBody.Forces / rigidBody.Mass;

        rigidBody.Velocity += newAcc * (1.0f/3 * dt) + acc * (5.0f/6 * dt) - prevAcc * (1.0f/6 * dt);

        rigidBody.PreviousAcceleration = acc;
        rigidBody.Acceleration = newAcc;
    }
}
