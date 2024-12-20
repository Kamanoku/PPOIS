#include "Technician.h"
#include <iostream>

Technician::Technician(int id, const std::string& name, int experienceYears, const std::string& specialization, const RepairOrder& currentOrder)
    : id(id), name(name), experienceYears(experienceYears), specialization(specialization), currentOrder(currentOrder) {
}

int Technician::getId() const { return id; }
std::string Technician::getName() const { return name; }
int Technician::getExperienceYears() const { return experienceYears; }
std::string Technician::getSpecialization() const { return specialization; }
RepairOrder Technician::getCurrentOrder() const { return currentOrder; }

void Technician::setName(const std::string& name) { this->name = name; }
void Technician::setExperienceYears(int experienceYears) { this->experienceYears = experienceYears; }
void Technician::setSpecialization(const std::string& specialization) { this->specialization = specialization; }
void Technician::setCurrentOrder(const RepairOrder& currentOrder) { this->currentOrder = currentOrder; }

void Technician::printDetails() const {
    std::cout << "Technician ID: " << id << "\n"
        << "Name: " << name << "\n"
        << "Experience Years: " << experienceYears << "\n"
        << "Specialization: " << specialization << "\n"
        << "Current Repair Order ID: " << currentOrder.getId() << "\n";
}
