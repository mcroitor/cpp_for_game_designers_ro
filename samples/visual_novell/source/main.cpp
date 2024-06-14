#include "engine.hpp"
#include <iostream>

std::string scenarioPath = "../resources/scenario.json";

int main() {
    std::cout << "game start..." << std::endl;
    Engine engine;
    engine.LoadScenario(scenarioPath);
    engine.Run();
    std::cout << "game done" << std::endl;
    return 0;
}