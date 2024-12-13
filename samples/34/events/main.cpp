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

/**
 * @brief event types
 */
enum class event_t
{
    no_event = 0,
    sys_exit = 1,
    animal_hungry,
    animal_very_hungry,
    animal_full,
    player_feed,
};

std::ostream &operator<<(std::ostream &out, event_t evt)
{
    switch (evt)
    {
    case event_t::no_event:
        out << "no_event";
        break;
    case event_t::sys_exit:
        out << "sys_exit";
        break;
    case event_t::animal_hungry:
        out << "animal_hungry";
        break;
    case event_t::animal_very_hungry:
        out << "animal_very_hungry";
        break;
    case event_t::animal_full:
        out << "animal_full";
        break;
    case event_t::player_feed:
        out << "player_feed";
        break;
    }
    return out;
}

/**
 * @brief event queue type
 */

class EventQueue
{
    std::deque<event_t> events;
    std::mutex mutex;

public:
    void Push(event_t evt)
    {
        std::lock_guard<std::mutex> lock(mutex);
        events.push_back(evt);
    }
    event_t Pop()
    {
        std::lock_guard<std::mutex> lock(mutex);
        event_t evt = events.front();
        events.pop_front();
        return evt;
    }
    bool Empty()
    {
        std::lock_guard<std::mutex> lock(mutex);
        return events.empty();
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
    event_t GenerateEvent()
    {
        int tmp = gen() % 100 + 1;

        if (tmp > 30)
        {
            ++is_hungry;
        }
        if (is_hungry == 0)
        {
            return event_t::animal_full;
        }
        if (is_hungry < hungry_threshold)
        {
            return event_t::animal_hungry;
        }
        return event_t::animal_very_hungry;
    }
    void Eat()
    {
        is_hungry = 0;
    }

    std::string_view GetName() const
    {
        return name;
    }
};

/**
 * @brief event queue
 */
EventQueue eventQueue;
/**
 * @brief A cat
 */
Cat cat("Garfield");

// --------- event handlers --------------------------------

struct abstract_handler
{
    virtual void operator()() = 0;
};

struct sys_exit_handler : abstract_handler
{
    virtual void operator()()
    {
        exit(0);
    }
};

struct ai_hungry_handler : abstract_handler
{
    virtual void operator()()
    {
        std::cout << "Cat is hungry\n";
    }
};

struct ai_very_hungry_handler : abstract_handler
{
    virtual void operator()()
    {
        std::cout << "Cat is very hungry, he goes to find another Master\n";
        eventQueue.Push(event_t::sys_exit);
    }
};

struct ai_full_handler : abstract_handler
{
    virtual void operator()()
    {
        std::cout << "Cat is full, goes to sleep.\n";
    }
};
struct player_feed_handler : abstract_handler
{
    virtual void operator()()
    {
        cat.Eat();
        std::cout << "Cat is fed\n";
        eventQueue.Push(event_t::animal_full);
    }
};

// --------- end event handlers ----------------------------

std::map<event_t, abstract_handler *> handler_map = {
    {event_t::sys_exit, new sys_exit_handler()},
    {event_t::animal_hungry, new ai_hungry_handler()},
    {event_t::animal_full, new ai_full_handler()},
    {event_t::animal_very_hungry, new ai_very_hungry_handler()},
    {event_t::player_feed, new player_feed_handler()},
};

event_t get_event()
{
    if (eventQueue.IsEmpty())
    {
        return event_t::no_event;
    }
    return eventQueue.Pop();
}

void event_loop()
{
    int feed;
    while (true)
    {
        event_t evt = get_event();
        // std::cout << "Event: " << evt << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        if (handler_map.find(evt) != handler_map.end())
        {
            (*handler_map.at(evt))();
        }
    }
}

void born()
{
    while (true)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
        event_t event = cat.GenerateEvent();
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
        if (data == "mouse")
        {
            eventQueue.Push(event_t::player_feed);
        }
        else if (data == "exit")
        {
            eventQueue.Push(event_t::sys_exit);
        }
    }
}

int main()
{
    std::thread thread(born);
    std::thread event_loop_thread(event_loop);
    std::thread user_thread(user);
    thread.join();
    event_loop_thread.join();
    user_thread.join();
    return 0;
}