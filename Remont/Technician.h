#pragma once
#include <string>
#include "RepairOrder.h"

class Technician {
private:
    int id;
    std::string name;
    int experienceYears;
    std::string specialization;
    RepairOrder currentOrder; 

public:
    Technician(int id, const std::string& name, int experienceYears, const std::string& specialization, const RepairOrder& currentOrder);

    int getId() const;
    std::string getName() const;
    int getExperienceYears() const;
    std::string getSpecialization() const;
    RepairOrder getCurrentOrder() const;

    void setName(const std::string& name);
    void setExperienceYears(int experienceYears);
    void setSpecialization(const std::string& specialization);
    void setCurrentOrder(const RepairOrder& currentOrder);

    void printDetails() const;
};
