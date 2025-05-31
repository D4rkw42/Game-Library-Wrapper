#include <glw/game/game-instance.hpp>

#include <chrono>
#include <thread>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

using namespace std::chrono;
using namespace std::literals::chrono_literals;

// temporary
constexpr int FPS_LIMIT = 120;

void glw::game::_GameInstance::SetInitFunction(const glw::game::GameInitFunction& callback) noexcept {
    this->initCallback = callback;
}

void glw::game::_GameInstance::SetQuitFunction(const glw::game::GameQuitFunction& callback) noexcept {
    this->quitCallback = callback;
}

void glw::game::_GameInstance::SetUpdateFunction(const glw::game::GameUpdateFunction& callback) noexcept {
    this->updateCallback = callback;
}

void glw::game::_GameInstance::SetRenderFunction(const glw::game::GameRenderFunction& callback) noexcept {
    this->renderCallback = callback;
}

void glw::game::_GameInstance::Restart(void) noexcept {
    this->restart = true;
    Quit();
}

void glw::game::_GameInstance::Quit(void) noexcept {
    this->quit = true;
}

void glw::game::_GameInstance::Run(void) {
    const GameInitFunction& initCallback = this->initCallback;
    const GameQuitFunction& quitCallback = this->quitCallback;
    const GameUpdateFunction& updateCallback = this->updateCallback;
    const GameRenderFunction& renderCallback = this->renderCallback;

    while (this->restart) {
        this->restart = false;

        initCallback();
        
        time_point prevTime = steady_clock::now();
        time_point currTime = prevTime;

        constexpr double execTimeStep = 1.0 / FPS_LIMIT;
        double execCountdown = 0;
        double dt = 0;

        while (!this->quit) {
            glfwPollEvents();

            currTime = steady_clock::now();
            double loopCycleDt = duration<double>(currTime - prevTime).count();
            prevTime = currTime;

            execCountdown -= loopCycleDt;
            dt += loopCycleDt;

            this->fpsCounter._Load(loopCycleDt);
            int fps = this->fpsCounter._GetFPS();

            if (execCountdown <= 0) {
                execCountdown += execTimeStep;

                updateCallback(dt);
                renderCallback(fps);
                this->fpsCounter._Count();
                
                dt = 0;
            }

            std::this_thread::sleep_for(1ms);
        }

        quitCallback();
    }
}
