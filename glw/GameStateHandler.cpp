#include <glw/game/GameStateHandler.hpp>

using namespace std::literals::chrono_literals;

// @TEMPORARY change to suitable user configuration eventually
constexpr int FPS = 60;

glw::game::GameStateHandler::~GameStateHandler() {
    for (auto& [ID, _] : this->states) {
        DeleteState(ID);
    }
}

//

void glw::game::GameStateHandler::CreateState(const std::string& ID, const std::shared_ptr<glw::game::IGameState>& state) noexcept {
    this->states[ID] = state;
}

void glw::game::GameStateHandler::DeleteState(const std::string& ID) {
    if (this->states.find(ID) != this->states.end()) {
        this->states[ID]->Shutdown();
        this->states[ID] = nullptr;
    }
}

void glw::game::GameStateHandler::LoadStates(void) {
    std::shared_ptr<glw::game::IGameState> state = _GetState();
    
    if (state == nullptr) {
        return;
    }

    if (this->needInitializeState) {
        this->needInitializeState = false;
        state->Init();
    }
    
    this->currTime = std::chrono::steady_clock::now();
    float dt = std::chrono::duration<float>(this->currTime - this->prevTime).count();
    this->prevTime = this->currTime;

    this->FPSCounter._Load(dt);

    const float executionStep = 1.0f / FPS;

    this->executionCountdown -= dt;

    if (this->executionCountdown <= 0.0f) {
        this->executionCountdown += executionStep;

        state->Update(dt);
        state->Render(FPSCounter._GetFPS());
        this->FPSCounter._Count();
    }
}

void glw::game::GameStateHandler::RestartState(void) {
    std::shared_ptr<glw::game::IGameState> state = _GetState();

    if (state != nullptr) {
        NextState(this->currStateID);
    }
}

void glw::game::GameStateHandler::NextState(const std::string& ID) {
    if (this->states.find(ID) == this->states.end()) {
        return;
    }

    if (this->currStateID != "none") {
        this->states[this->currStateID]->Shutdown();
    }

    this->currStateID = ID;
    this->needInitializeState = true;
}

std::shared_ptr<glw::game::IGameState> glw::game::GameStateHandler::_GetState(void) noexcept {
    if (this->currStateID != "none") {
        return this->states[this->currStateID];
    }
    
    return nullptr;
}
