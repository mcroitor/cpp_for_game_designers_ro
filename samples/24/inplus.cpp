#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <format>
#include <ranges>

struct Date
{
    int year;
    int month;
    int day;

    std::string toString() const
    {
        return std::format("{:04}-{:02}-{:02}", year, month, day);
    }
};

bool operator<(Date left, Date right)
{
    return left.toString() < right.toString();
}

Date operator"" _dt(unsigned long long int value)
{
    Date date;
    date.day = value % 100;
    date.year = value / 10000;
    date.month = (value % 10000) / 100; // (value / 100) % 100
    return date;
}

struct Student
{
    std::string firstName;
    std::string lastName;
    Date birthDate;
};

std::ostream &operator<<(std::ostream &out, const Student &student)
{
    out << std::format("| {:<12} | {:<12} | {:>12} |", student.lastName, student.firstName, student.birthDate.toString());
    return out;
}

bool operator<(const Student &left, const Student &right)
{
    return left.lastName < right.lastName;
}

bool cmpByDate(const Student &left, const Student &right)
{
    return left.birthDate < right.birthDate;
}

int main()
{
    {
        MySmartPointer<Student> ptr(new Student);
        MySmartPointer<Student> ptr2(new Student{"Sample", "Ok", 20101});
        (*ptr).firstName = "Gicu";
        ptr->lastName = "Stirbu";
        ptr = ptr2;
    }
    auto cmp = [](const auto &left, const auto &right)
    { return left.birthDate < right.birthDate; };
    auto cmpL = [](const auto &left, const auto &right)
    { return left.lastName < right.lastName; };
    std::vector<Student> students = {
        {"Miroslav", "Rotari", 20040710_dt},
        {"Alexandru", "Rosca", 20040422_dt},
        {"Cristian", "Balan", 20041102_dt},
        {"Dana", "Samcov", 20040220_dt},
        {"Emiliana", "Sorbala", 20041130_dt},
        {"Alexandru", "Trusov", 20040229_dt},
    };

    // std::sort(students.begin(), students.end());
    std::ranges::sort(students, cmpL);

    for (const auto &student : students)
    {
        std::cout << student << std::endl;
    }
    std::cout << std::string(46, '-') << std::endl;
    std::sort(students.begin(), students.end(), cmpByDate);

    for (const auto &student : students)
    {
        std::cout << student << std::endl;
    }

    std::cout << std::string(46, '-') << std::endl;
    std::sort(
        students.begin(),
        students.end(),
        cmp);

    for (const auto &student : students)
    {
        std::cout << student << std::endl;
    }

    std::string name = "Alexandru";
    std::vector<Student> result;
    std::copy_if(
        students.begin(),
        students.end(),
        std::back_inserter(result),
        [name](auto student)
        { return student.firstName == name; });

    std::cout << std::string(46, '-') << std::endl;
    for (const auto &student : result)
    {
        std::cout << student << std::endl;
    }

    // select students born till 2004-07-01
    std::cout << std::string(46, '-') << std::endl;
    auto r = students |
             std::ranges::views::filter([](const Student &student)
                                        { return student.birthDate < 20040701_dt; }) |
             std::ranges::views::take(2) |
             std::ranges::views::drop(1);

    std::ranges::for_each(r, [](const Student &student)
                          { std::cout << student << std::endl; });
    return 0;
}

// f(x) = y, g(x) = y ==> f # g = f(g(x))
// auto operator | (container, adapter);