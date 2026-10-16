#include <string>
#include <iostream>

using std::string;
using std::cout;

class Human
{

private:
    string Name;
    string Surname;
    int BirthYear;
public:
//    Human(): Name {"Gicu"}, Surname {"Stirbu"}, BirthYear {2007} {
//    }

    Human() = default;

    Human(string name, string surname, int birthYear):
        Name {name},
        Surname {surname},
        BirthYear {birthYear}
    {
    }

    Human(const Human& human):
        Name {human.Name},
        Surname {human.Surname},
        BirthYear {human.BirthYear} {}

    ~Human() = default;

    string GetName() const {
        return Name;
    }

    string GetSurname() const {
        return Surname;
    }

    int GetBirtYear() const {
        return BirthYear;
    }
};

int main() {
    Human gicu;

    Human ion {"Ion", "Humanoid", 2008};

    Human copieIon = Human(ion);

    cout << gicu.GetName() << ", " << gicu.GetSurname() << ", " << gicu.GetBirtYear();

    return 0;
}