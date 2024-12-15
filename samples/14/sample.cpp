#include <iostream>

struct Human {
    std::string first_name;
    std::string last_name;
    virtual void print() const = 0;
};

struct Student : Human {
    Student() {
        first_name = "Student";
        last_name = "Good";
    }
    Student(const std::string& first_name, const std::string& last_name) {
        this->first_name = first_name;
        this->last_name = last_name;
    }
    Student(const Student& s) {
        first_name = s.first_name;
        last_name = s.last_name;
    }

    static Student CreateStudentFromFirstName(const std::string& first_name) {
        return Student(first_name, "Good");
    }
    static Student CreateStudentFromLastName(const std::string& last_name) {
        return Student("Student", last_name);
    }
    
    void print() const {
        std::cout << "Student" << std::endl;
    }
};

struct Lecturer : Human {
    void print() const {
        std::cout << "Lecturer" << std::endl;
    }
};

void print(const Human& h) {
    h.print();
}

float min(float a, float b) {
    return a < b ? a : b;
}

int main() {
    // Human h;
    Student s {};
    Student s1 {"John", "Doe"};
    Student s2 {s1};

    Student s3 = Student::CreateStudentFromFirstName("John");
    Student s4 = s.CreateStudentFromLastName("Doe");

    Lecturer l;

    // print(h);
    print(s);
    print(l);

    int a = 5;
    int b = 3;
    std::cout << min(a, b) << std::endl;

    float c = 5.5;
    float d = 3.3;
    std::cout << min(c, d) << std::endl;

    return 0;
}
