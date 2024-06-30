#include "Building.h"
#include "Flat.h"
#include "Resident.h"

int main() {
    
    Resident* resident1 = new Resident("Иван" , 18 );
    Resident* resident2 = new Resident("Анна" , 43);
    Resident* resident3 = new Resident("Сергей" , 26);

   
    Flat* flat1 = new Flat(2, 50.0);
    flat1->addResident(*resident1);
    flat1->addResident(*resident2);

    
    Flat* flat2 = new Flat(1, 30.0);
    flat2->addResident(*resident3);

   
    Building* building = new Building("ул. Ленина, 1");
    building->addFlat(flat1);
    building->addFlat(flat2);

    std::cout << std::endl;
    building->showAllFlatsList();

    std::cout << std::endl;
    building->showAllResidentsList();

    std::cout << std::endl;
    building->showResidentsListByFlat(0);

    delete building;

    return 0;
}