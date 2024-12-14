#include <iostream>
#include <deque>
#include <thread>
#include <random>
#include <chrono>
#include <map>
#include <algorithm>
#include <iterator>
#include <mutex>
#include <string>
#include <memory>

class Cat;
/**
 * @brief event type
 */
struct Event
{
    enum Type
    {
        NO_EVENT,
        SYSTEM_EXIT,
        ANIMAL_HUNGRY,
        ANIMAL_VERY_HUNGRY,
        ANIMAL_FULL,
        PLAYER_FEED
    };
    Type type;
    Cat *cat;
};

std::ostream &operator<<(std::ostream &out, const Event &evt)
{
    switch (evt.type)
    {
    case Event::Type::NO_EVENT:
        out << "NO_EVENT";
        break;
    case Event::Type::SYSTEM_EXIT:
        out << "SYSTEM_EXIT";
        break;
    case Event::Type::ANIMAL_HUNGRY:
        out << "ANIMAL_HUNGRY";
        break;
    case Event::Type::ANIMAL_VERY_HUNGRY:
        out << "ANIMAL_VERY_HUNGRY";
        break;
    case Event::Type::ANIMAL_FULL:
        out << "ANIMAL_FULL";
        break;
    case Event::Type::PLAYER_FEED:
        out << "PLAYER_FEED";
        break;
    }
    return out;
}

/**
 * @brief event queue type
 */

class EventQueue
{
    std::deque<Event> events;
    std::mutex mutex;

public:
    void Push(Event evt)
    {
        std::lock_guard<std::mutex> lock(mutex);
        events.push_back(evt);
    }
    Event Pop()
    {
        std::lock_guard<std::mutex> lock(mutex);
        Event evt = events.front();
        events.pop_front();
        return evt;
    }
    bool IsEmpty()
    {
        std::lock_guard<std::mutex> lock(mutex);
        return events.empty();
    }
};

/**
 * @brief Cat class
 */
class Cat
{
    const int hungry_threshold = 5;
    std::mt19937_64 gen;
    int is_hungry;
    std::string name;

public:
    Cat(std::string_view name) : gen(std::chrono::system_clock::now().time_since_epoch().count()),
                                 is_hungry{0},
                                 name{name}
    {
    }
    Event GenerateEvent()
    {
        int tmp = gen() % 100 + 1;

        if (tmp > 70 - is_hungry * 10)
        {
            ++is_hungry;
        }
        if (is_hungry == 0)
        {
            return Event{.type = Event::Type::ANIMAL_FULL, .cat = this};
        }
        if (is_hungry < hungry_threshold)
        {
            return Event{.type = Event::Type::ANIMAL_HUNGRY, .cat = this};
        }
        return Event{.type = Event::Type::ANIMAL_VERY_HUNGRY, .cat = this};
    }
    void Eat()
    {
        is_hungry = 0;
    }

    std::string_view GetName() const
    {
        return name;
    }

    int GetHungryLevel() const
    {
        return is_hungry;
    }
};

/**
 * @brief event queue
 */
EventQueue eventQueue;
std::deque <std::shared_ptr<Cat>> cats;

// --------- event handlers --------------------------------

struct abstract_handler
{
    virtual void operator()(const Event &event) = 0;
};

struct SYSTEM_EXIT_handler : abstract_handler
{
    virtual void operator()(const Event &event)
    {
        exit(0);
    }
};

struct ai_hungry_handler : abstract_handler
{
    virtual void operator()(const Event &event)
    {
        std::cout << event.cat->GetName()
                  << " is hungry, hungry level: "
                  << event.cat->GetHungryLevel()
                  << std::endl;
    }
};

struct ai_very_hungry_handler : abstract_handler
{
    virtual void operator()(const Event &event)
    {
        std::cout << event.cat->GetName()
                  << " is very hungry, he goes to find another Master]"
                  << std::endl;
        eventQueue.Push(Event{.type = Event::Type::SYSTEM_EXIT});
    }
};

struct ai_full_handler : abstract_handler
{
    virtual void operator()(const Event &event)
    {
        std::cout << event.cat->GetName()
                  << " is full, goes to sleep."
                  << std::endl;
    }
};
struct PLAYER_FEED_handler : abstract_handler
{
    virtual void operator()(const Event &event)
    {
        event.cat->Eat();
        std::cout << event.cat->GetName()
                  << " is fed"
                  << std::endl;
        eventQueue.Push(Event{.type = Event::Type::ANIMAL_FULL, .cat = event.cat});
    }
};

// --------- end event handlers ----------------------------

std::map<Event::Type, abstract_handler *> handler_map = {
    {Event::Type::SYSTEM_EXIT, new SYSTEM_EXIT_handler()},
    {Event::Type::ANIMAL_HUNGRY, new ai_hungry_handler()},
    {Event::Type::ANIMAL_FULL, new ai_full_handler()},
    {Event::Type::ANIMAL_VERY_HUNGRY, new ai_very_hungry_handler()},
    {Event::Type::PLAYER_FEED, new PLAYER_FEED_handler()},
};

Event get_event()
{
    if (eventQueue.IsEmpty())
    {
        return Event{.type = Event::Type::NO_EVENT};
    }
    return eventQueue.Pop();
}

void event_loop()
{
    while (true)
    {
        Event evt = get_event();
        // std::cout << "Event: " << evt << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        if (handler_map.find(evt.type) != handler_map.end())
        {
            (*handler_map.at(evt.type))(evt);
        }
    }
}

void bornTom()
{
    auto cat = std::make_shared<Cat>("Tom");
    cats.push_back(cat);
    while (true)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
        Event event = cat->GenerateEvent();
        eventQueue.Push(event);
    }
}

void bornGarfield()
{
    auto cat = std::make_shared<Cat>("Garfield");
    cats.push_back(cat);
    while (true)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
        Event event = cat->GenerateEvent();
        eventQueue.Push(event);
    }
}

void user()
{
    std::string data;
    while (true)
    {
        std::cout << "enter smth" << std::endl;
        std::cin >> data;
        if (data == "exit")
        {
            eventQueue.Push(Event {.type = Event::Type::SYSTEM_EXIT});
        }
        else
        {
            auto it = std::find_if(
                cats.begin(), 
                cats.end(), [&data](std::shared_ptr<Cat> cat) {
                return cat->GetName() == data;
            });

            if (it == cats.end())
            {
                std::cout << "No such cat: "
                    << data
                    << std::endl;
                continue;
            }

            eventQueue.Push(Event{.type = Event::Type::PLAYER_FEED, .cat = (*it).get()});
        }
    }
}

int main()
{
    std::jthread threadTom(bornTom);
    std::jthread threadGarfield(bornGarfield);
    std::jthread user_thread(user);
    std::jthread event_loop_thread(event_loop);

    return 0;
}