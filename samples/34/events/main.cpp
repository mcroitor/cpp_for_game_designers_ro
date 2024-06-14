#include <iostream>
#include <deque>
#include <thread>
#include <random>
#include <chrono>
#include <map>

enum class event_t
{
    no_event = 0,
    sys_exit = 1,
    ai_angry,
    ai_full,
    player_feed,
};

using event_queue_t = std::deque<event_t>;

class AI
{
    std::mt19937_64 gen;
    bool is_angry;

public:
    AI() : gen{std::chrono::system_clock::now().time_since_epoch().count()}, is_angry{false} {}
    event_t generate_event()
    {
        int tmp = gen() % 100;
        if (tmp == 0)
        {
            is_angry = true;
            return event_t::ai_angry;
        }
        return event_t::ai_full;
    }
    void eat()
    {
        is_angry = false;
    }
};

event_queue_t event_queue;
AI cat;

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

struct ai_angry_handler : abstract_handler
{
    virtual void operator()()
    {
        std::cout << "Cat is angry\n";
    }
};

struct ai_full_handler : abstract_handler
{
    virtual void operator()()
    {
        std::cout << "Cat is full\n";
    }
};
struct player_feed_handler : abstract_handler
{
    virtual void operator()()
    {
        cat.eat();
        event_queue.push_back(event_t::ai_full);
    }
};

// --------- end event handlers ----------------------------
std::map<event_t, abstract_handler*> handler_map = {
    {event_t::sys_exit, new sys_exit_handler()},
    {event_t::ai_angry, new ai_angry_handler()},
    {event_t::ai_full, new ai_full_handler()},
    {event_t::player_feed, new player_feed_handler()},
};

event_t get_event()
{
    auto it = event_queue.begin();
    while (it == event_queue.end())
    {
    }
    event_t evt = event_queue.front();
    event_queue.pop_front();
    return evt;
}

void event_loop()
{
    int feed;
    while (true)
    {
        event_t evt = get_event();
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
        std::this_thread::sleep_for(std::chrono::milliseconds(20));
        event_t event = cat.generate_event();
        if (event == event_t::ai_angry)
        {
            event_queue.push_back(event);
        }
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
            event_queue.push_back(event_t::player_feed);
        }
        else if (data == "exit")
        {
            event_queue.push_back(event_t::sys_exit);
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