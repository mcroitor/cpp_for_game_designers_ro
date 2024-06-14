#include "defines.hpp"
#include "engine.hpp"

void Engine::LoadScenario(const std::string &filename)
{
    // TODO: add implementation
    scenario.Load(filename);
    currentScene = scenario.GetScene(FIRST_SCENE);
}

void Engine::Run()
{
    // TODO: Add implementation
    Painter painter;
    while (currentScene != scenario.GetScene(LAST_SCENE)) {
        currentScene.Draw(painter);
    }
}