#pragma once

#include <memory>
#include <type_traits>

namespace glw::game {
    /// @brief Represents the state of the game. State controlls what is happening in the game and what is been displayed
    class IGameState {
        public:
            IGameState(void) = default;

            /// @brief Initializes the state
            virtual void Init(void) const = 0;
            /// @brief Shutdown the state
            virtual void Shutdown(void) const = 0;
            /// @brief Loads updates of the state
            /// @param dt time elapsed after the last execution
            virtual void Update(float dt) const = 0;
            /// @brief Loads rendering of the state 
            /// @param fps fps rate of the last period `1s`   
            virtual void Render(int fps) const = 0;
    };

    /// @brief Creates a custom game state of `IGameStateType` type
    /// @tparam IGameStateType The custom game state derived from `glw::game::IGameState`
    /// @return A pointer to the state
    /// @exception Throws a compile-time exception if `IGameStateType` is not derived from `glw::game::IGameState`
    template <class IGameStateType>
    inline std::shared_ptr<IGameState> CreateGameState(void) noexcept {
        static_assert(std::is_base_of<IGameState, IGameStateType>::value, "You must only provide a IGameStateType class derived from IGameState");
        
        std::shared_ptr<IGameStateType> mState = std::make_shared<IGameStateType>();
        return std::dynamic_pointer_cast<IGameState>(mState);
    }
}
