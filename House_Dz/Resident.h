#pragma once
#pragma once
#include <string>

class Resident {
private:
    std::string name;
    int age;

public:
    Resident(std::string name, int age) : name(name), age(age) {}

    std::string getName() const {
        return name;
    }

    void setName(std::string name) {
        this->name = name;
    }

    Resident(const Resident& other) : name(other.name), age(other.age) {}

    Resident& operator=(const Resident& other) {
        if (this != &other) {
            name = other.name;
            age = other.age;
        }
        return *this;
    }
};
