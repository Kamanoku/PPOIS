#include "Equipment.h"
#include <iostream>

Equipment::Equipment(int id, const std::string& name, const std::string& type, double cost, const RepairOrder& repairOrder)
    : id(id), name(name), type(type), cost(cost), repairOrder(repairOrder) {
}

int Equipment::getId() const { return id; }
std::string Equipment::getName() const { return name; }
std::string Equipment::getType() const { return type; }
double Equipment::getCost() const { return cost; }
RepairOrder Equipment::getRepairOrder() const { return repairOrder; }

void Equipment::setName(const std::string& name) { this->name = name; }
void Equipment::setType(const std::string& type) { this->type = type; }
void Equipment::setCost(double cost) { this->cost = cost; }
void Equipment::setRepairOrder(const RepairOrder& repairOrder) { this->repairOrder = repairOrder; }

void Equipment::printDetails() const {
    std::cout << "Equipment ID: " << id << "\n"
        << "Name: " << name << "\n"
        << "Type: " << type << "\n"
        << "Cost: " << cost << "\n"
        << "Associated Repair Order ID: " << repairOrder.getId() << "\n";
}
