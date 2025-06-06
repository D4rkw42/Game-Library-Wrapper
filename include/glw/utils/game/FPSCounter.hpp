#pragma once

namespace glw::utils::game {
    class _FPSCounter {
        public:
            void _Load(float dt) noexcept;
            int _GetFPS(void) const noexcept;
            
            void _Count(void) noexcept;
            
        private:
            int 
                FPSCount = 0,
                FPS = 0;

            float FPSCountTimeout = 1.0f;
    };
}
