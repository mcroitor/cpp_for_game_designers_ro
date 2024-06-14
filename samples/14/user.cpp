#include <iostream>
#include <string>

class User
{
    std::string firstName;
    std::string lastName;

public:
    User(const std::string &fn, const std::string &ln) : firstName(fn), lastName(ln) {}
    std::string ToString() const
    {
        return firstName + " " + lastName;
    }
    virtual std::string Role() const
    {
        return std::string("Undefined");
    }
};

class Manager : public User
{
public:
    Manager(const std::string &fn, const std::string &ln) : User(fn, ln) {}
    virtual std::string Role() const {
        return std::string("Manager");
    }
};

void printRole(const User &user){
    std::cout << user.ToString() << ": " << user.Role() << std::endl;
}

int main() {

    printRole(User("Unknown", "User"));
    printRole(Manager("Awesome", "Manager"));
    return 0;
}