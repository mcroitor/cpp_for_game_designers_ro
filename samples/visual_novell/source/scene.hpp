#ifndef __SCENE_H__
#define __SCENE_H__

#include "event.hpp"
#include "painter.hpp"
#include <string>
#include <vector>

/**
 * @brief Scene represent a state of game
 * 
 */
class Scene
{
    /**
     * @brief scene name, used as identifier
     * 
     */
    std::string _name;

    std::vector<std::string> _messages;

    /**
     * @brief Each scene has a set of events
     * 
     */
    std::vector<Event> _events;

public:
    /**
     * @brief Default constructor, but use factory method to create new instance
     * 
     */
    Scene() = default;
    /**
     * @brief Construct a new Scene object from other Scene instance
     * 
     */
    Scene(const Scene& other);

    /**
     * @brief Load scene description from JSON and create new instance
     * @param json Scene description
     * @return Scene 
     */
    static Scene Load(const std::string& json);

    /**
     * @brief draw the scene
     * 
     * @param painter - object for communication with console / screen
     */
    void Draw(const Painter& painter);
    /**
     * @brief Get the Event object
     * 
     * @param eventName 
     * @return Event 
     */
    Event GetEvent(const std::string& eventName) const;

    /**
     * @brief Get the Name object
     * 
     * @return std::string 
     */
    std::string GetName() const;
};

/**
 * @brief compare two Scene objects
 * 
 * @param left 
 * @param right 
 * @return true left == right
 * @return false left != right
 */
bool operator==(const Scene& left, const Scene& right);
bool operator!=(const Scene& left, const Scene& right);

#endif