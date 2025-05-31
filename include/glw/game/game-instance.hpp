#pragma once

#include <functional>

#include <glw/utils/game/fps-counter.hpp>

namespace glw::game {
    using GameInitFunction = std::function<void(void)>;
    using GameQuitFunction = std::function<void(void)>;
    using GameUpdateFunction = std::function<void(double)>;
    using GameRenderFunction = std::function<void(int)>;

    class _GameInstance {
        public:
            /// @brief Sets the init function for game instance
            /// @param callback callback function
            void SetInitFunction(const GameInitFunction& callback) noexcept;
            /// @brief Sets the quit function for game instance
            /// @param callback callback function
            void SetQuitFunction(const GameQuitFunction& callback) noexcept;
            /// @brief Sets the update function for game instance (executed with render function)
            /// @param callback callback function
            void SetUpdateFunction(const GameUpdateFunction& callback) noexcept;
            /// @brief Sets the render function for game instance (executed with update function within frame rate limit)
            /// @param callback callback function
            void SetRenderFunction(const GameRenderFunction& callback) noexcept;
            
            /// @brief Allows game instance to restart (every init/quit function are recalled)
            void Restart(void) noexcept;
            /// @brief Finishes game instance execution
            void Quit(void) noexcept;

            /// @brief Runs the game instance configured.
            /// @throws ``glw::GlwException`` if no configuration was provided
            void Run(void);

        private:
            bool
                restart = true,
                quit = false;

            GameInitFunction initCallback;
            GameQuitFunction quitCallback;
            GameUpdateFunction updateCallback;
            GameRenderFunction renderCallback;

            glw::utils::game::_FPSCounter fpsCounter;
    };
}
