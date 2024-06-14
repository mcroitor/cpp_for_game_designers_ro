# example

```cpp

class Event {
    std::string name;
    std::string message;
    std::string nextScene;
}

class Scene{
    std::string name;
    std::vector<Event> events;
public:
    void Draw();
    Event GetEvent();
}

class Game {
    std::vector<Scene> scenario;

public:
    Scene start();
    Scene end();
    Scene Do(Event event);
};

int main() {
    Game game;
    auto currentScene = game.start();
    while(currentScene != game.end()) {
        currentScene.draw();
        Event event = currentScene.getEvent();
        currentScene = game.Do(event);
    }

}
```
