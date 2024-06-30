#pragma once
#include <vector>
#include <string>
#include "Flat.h"

class Building {
private:
    std::string address;
    std::vector<Flat*> flats;

public:
    Building(std::string address) : address(address) {}

    ~Building() {
        for (auto flat : flats) {
            delete flat;
        }
    }

    void addFlat(Flat* f) {
        flats.push_back(f);
    }

    void addResident(Resident* r, int flatNum) {
        if (flatNum >= 0 && flatNum < flats.size()) {
            flats[flatNum]->addResident(r);
        }
    }

    std::string getAddress() const {
        return address;
    }

    void setAddress(std::string address) {
        this->address = address;
    }

    void showAllFlatsList() const {
        for (auto flat : flats) {
            flat->showResidents();
        }
    }

    void showAllResidentsList() const {
        for (auto flat : flats) {
            flat->showResidents();
        }
    }

    void showResidentsListByFlat(int n) const {
        if (n >= 0 && n < flats.size()) {
            flats[n]->showResidents();
        }
    }

    void addResident(Resident r, int flatNum) {
        if (flatNum >= 0 && flatNum < flats.size()) {
            flats[flatNum]->addResident(r);
        }
    }
};

