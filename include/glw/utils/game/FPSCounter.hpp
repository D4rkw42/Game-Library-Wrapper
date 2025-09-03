#pragma once

namespace glw::utils::game {
    class FPSCounter {
        public:
            void Load(float dt) noexcept;
            int GetFPS(void) const noexcept;
            
            void Count(void) noexcept;
            
        private:
            int 
                FPSCount = 0,
                FPS = 0;

            float FPSCountTimeout = 1.0f;
    };
}
