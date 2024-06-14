#include <string>
#include <iostream>

enum class gender_type
{
    nonbinary,
    male,
    female,
};

using birth_year_type = short;

class student
{
    std::string name_;
    gender_type gender_;
    birth_year_type birth_year_;
    std::string group_;

public:
    student() = default;
    student(
        const std::string& name, 
        const gender_type& gender, 
        const birth_year_type& birth_year, 
        const std::string& group);
    void print() const;
    const std::string& get_name() const;
};

int main()
{
    std::string name = "Gicu";
    student student1{name, gender_type::male, 2002, "FL2101"};

    student1.print();

    student1.get_name() += "oops";
    student1.print();

    return 0;
}

student::student(
        const std::string& name, 
        const gender_type& gender, 
        const birth_year_type& birth_year, 
        const std::string& group)
{
    // equal (*this).name = name;
    name_ = name;
    gender_ = gender;
    birth_year_ = birth_year;
    group_ = group;
}

void student::print() const {
    std::cout << this->name_ << " "
        << this->group_
        << std::endl;
}

const std::string& student::get_name() const {
    return name_;
}