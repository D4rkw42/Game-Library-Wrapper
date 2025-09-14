#pragma once

#include <memory>
#include <chrono>
#include <unordered_map>
#include <string>

#include <glw/game/IGameState.hpp>
#include <glw/utils/game/FPSCounter.hpp>

// @TEMPORARY change to suitable FPS render user configuration eventually
constexpr int RENDER_STEP = 60;
constexpr int UPDATE_STEP = 120; // non-configurable

namespace glw::game {
    /// @brief A handler to manage and run your game states
    class GameStateHandler {
        public:
            GameStateHandler(void) = default;
            ~GameStateHandler();

            /// @brief Creates an identified game state
            /// @param ID the ID of the state
            /// @param state a pointer to the state
            void CreateState(const std::string& ID, const std::shared_ptr<glw::game::IGameState>& state) noexcept;
            /// @brief Deletes a state from the handler by its ID
            /// @param ID the ID of the state
            void DeleteState(const std::string& ID);

            /// @brief Initializes and runs the current state
            void LoadStates(void);

            /// @brief Restarts the current state
            void RestartState(void);
            /// @brief Shuts the current state down and starts another state
            /// @param ID the ID of the new state
            void NextState(const std::string& ID);

        private:
            std::unordered_map<std::string, std::shared_ptr<glw::game::IGameState>> states;
            std::string currStateID = "none";

            bool needInitializeState = true;
            bool restart = false;

            std::chrono::time_point<std::chrono::steady_clock> 
                prevTime = std::chrono::steady_clock::now(),
                currTime = prevTime;

            float
                updateCountdown = 0.0f,
                renderCountdown = 0.0f;

            glw::utils::game::FPSCounter FPSCounter;

            std::shared_ptr<glw::game::IGameState> GetState(void) noexcept;
    };
}
