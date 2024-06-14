#ifndef __ENGINE_H__
#define __ENGINE_H__

#include "scenario.hpp"
#include "scene.hpp"

#include <string>

class Engine
{
    Scenario scenario;
    Scene currentScene;

public:
    void LoadScenario(const std::string& filename);
    void Run();
};

#endif