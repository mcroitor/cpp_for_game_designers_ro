#ifndef __SCENARIO_H__
#define __SCENARIO_H__

#include <string>
#include <vector>

#include "scene.hpp"

/**
 * @brief Scenario is a set of Scenes
 * 
 */
class Scenario {

    std::vector<Scene> scenes;

    public:
    /**
     * @brief Construct a new Scenario object
     * 
     */
    Scenario() = default;
    /**
     * @brief Load scenario from specified file
     * @param fileName The name of the JSON file with scenario information
     */
    void Load(const std::string&);

    /**
     * @brief Get the Scene object by its name
     * @param sceneName
     * @return Scene 
     */
    Scene GetScene(const std::string&);

};

#endif