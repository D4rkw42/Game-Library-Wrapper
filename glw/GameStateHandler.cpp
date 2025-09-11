#include <glw/game/GameStateHandler.hpp>

glw::game::GameStateHandler::~GameStateHandler() {
    for (auto& [ID, _] : this->states) {
        DeleteState(ID);
    }
}

//

#include <iostream>

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
    std::shared_ptr<glw::game::IGameState> state = GetState();
    
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

    const float renderStep = 1.0f / RENDER_STEP;
    const float updateStep = 1.0f / UPDATE_STEP;

    this->FPSCounter.Load(dt);

    this->updateCountdown -= dt;
    this->renderCountdown -= dt;

    // Update is fixed for deterministic behavior
    if (this->updateCountdown <= 0.0f) {
        this->updateCountdown += updateStep;
        state->Update(updateStep);
    }

    // Render can be unlimited or limited by user
    if (this->renderCountdown <= 0.0f) {
        this->renderCountdown += renderStep;

        state->Render(FPSCounter.GetFPS());
        this->FPSCounter.Count();
    }
}

void glw::game::GameStateHandler::RestartState(void) {
    std::shared_ptr<glw::game::IGameState> state = GetState();

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

std::shared_ptr<glw::game::IGameState> glw::game::GameStateHandler::GetState(void) noexcept {
    if (this->currStateID != "none") {
        return this->states[this->currStateID];
    }
    
    return nullptr;
}
