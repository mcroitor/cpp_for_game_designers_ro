#ifndef __EVENT_H__
#define __EVENT_H__

#include <string>

/**
 * @brief Game event
 *
 */
class Event
{
    /**
     * @brief event name
     *
     */
    std::string _name;
    /**
     * @brief event message
     *
     */
    std::string _message;
    /**
     * @brief event change game to this scene
     *
     */
    std::string _nextScene;

public:
    /**
     * @brief Construct a new Event object
     * @param const std::string& name
     * @param const std::string& message
     * @param const std::string& nextScene
     */
    Event(const std::string &name, const std::string &message, const std::string &nextScene);
    Event(const Event& other);

    /**
     * @brief Get the Event Name
     *
     * @return std::string
     */
    std::string GetName() const;

    /**
     * @brief Get the Event Message
     *
     * @return std::string
     */
    std::string GetMessage() const;

    /**
     * @brief Get the Scene Name for redirection
     *
     * @return std::string
     */
    std::string GetNextScene() const;

    /**
     * @brief Create a JSON representation of the Event object
     *
     * @return std::string
     */
    std::string ToJSON() const;
};

/**
 * @brief Compare to Event objects
 *
 * @param left
 * @param tight
 * @return true - objects are equal
 * @return false - objects are different
 */
bool operator==(const Event &left, const Event &right);

/**
 * @brief empty event object, lazy to use pointers for checking
 * 
 */
const Event NO_EVENT("", "", "");

#endif