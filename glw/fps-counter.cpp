#include <glw/utils/game/fps-counter.hpp>

void glw::utils::game::_FPSCounter::_Load(double dt) noexcept {
    this->FPSCountTimeout -= dt;

    if (this->FPSCountTimeout <= 0) {
        this->FPSCountTimeout += 1.0;
        this->FPS = this->FPSCount;
        this->FPSCount = 0;
    }
}

void glw::utils::game::_FPSCounter::_Count(void) noexcept {
    this->FPSCount++;
}

int glw::utils::game::_FPSCounter::_GetFPS(void) const noexcept {
    return this->FPS;
}
