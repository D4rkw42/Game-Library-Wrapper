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
            void SetInitFunction(const GameInitFunction& callback) noexcept;
            void SetQuitFunction(const GameQuitFunction& callback) noexcept;
            void SetUpdateFunction(const GameUpdateFunction& callback) noexcept;
            void SetRenderFunction(const GameRenderFunction& callback) noexcept;
            
            void Restart(void) noexcept;
            void Quit(void) noexcept;

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
