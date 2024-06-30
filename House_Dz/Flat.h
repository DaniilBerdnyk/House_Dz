#pragma once
#include<iostream>
#include <vector>
#include "Resident.h"

class Flat {
private:
    int rooms;
    float square;
    std::vector<Resident*> residents;

public:
    Flat(int rooms, float square) : rooms(rooms), square(square) {}

    ~Flat() {
        for (auto resident : residents) {
            delete resident;
        }
    }

    void addResident(Resident* r) {
        residents.push_back(r);
    }

    int getRooms() const {
        return rooms;
    }

    void setRooms(int rooms) {
        this->rooms = rooms;
    }

    float getSquare() const {
        return square;
    }

    void setSquare(float square) {
        this->square = square;
    }

    void showResidents() const {
        for (auto resident : residents) {
            std::cout << resident->getName() << std::endl;
        }
    }


    //2
    Flat(const Flat& other) : rooms(other.rooms), square(other.square) {
        for (auto resident : other.residents) {
            residents.push_back(new Resident(*resident));
        }
    }

    Flat& operator=(const Flat& other) {
        if (this != &other) {
            rooms = other.rooms;
            square = other.square;
            for (auto resident : residents) {
                delete resident;
            }
            residents.clear();
            for (auto resident : other.residents) {
                residents.push_back(new Resident(*resident));
            }
        }
        return *this;
    }

    //3
    void addResident(Resident r) {
        residents.push_back(new Resident(r));
    }

};
