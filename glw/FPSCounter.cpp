#include <glw/utils/game/FPSCounter.hpp>

void glw::utils::game::FPSCounter::Load(float dt) noexcept {
    this->FPSCountTimeout -= dt;

    if (this->FPSCountTimeout <= 0) {
        this->FPSCountTimeout += 1.0;
        this->FPS = this->FPSCount;
        this->FPSCount = 0;
    }
}

void glw::utils::game::FPSCounter::Count(void) noexcept {
    this->FPSCount++;
}

int glw::utils::game::FPSCounter::GetFPS(void) const noexcept {
    return this->FPS;
}
