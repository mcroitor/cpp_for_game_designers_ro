#include "event.hpp"

Event::Event(
    const std::string &name,
    const std::string &message,
    const std::string &nextScene) : 
        _name(name),
        _message(message),
        _nextScene(nextScene)
{
}

Event::Event(const Event &other) : _name(other._name),
                                   _message(other._message),
                                   _nextScene(other._nextScene)
{
}

std::string Event::GetName() const
{
    return _name;
}

std::string Event::GetMessage() const
{
    return _message;
}

std::string Event::GetNextScene() const
{
    return _nextScene;
}

std::string Event::ToJSON() const
{
    return std::string("{\"name\":\"") + this->GetName() +
           std::string("\",\"message\":\"") + this->GetMessage() +
           std::string("\",\"sceneName\":\"") + this->GetNextScene() +
           std::string("\"}");
}

bool operator==(const Event &left, const Event &right)
{
    return left.GetName() == right.GetName();
}