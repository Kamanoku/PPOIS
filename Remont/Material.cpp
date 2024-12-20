#include "Material.h"
#include <iostream>

Material::Material(int id, const std::string& name, double cost, int quantity, const RepairOrder& repairOrder)
    : id(id), name(name), cost(cost), quantity(quantity), repairOrder(repairOrder) {
}

int Material::getId() const { return id; }
std::string Material::getName() const { return name; }
double Material::getCost() const { return cost; }
int Material::getQuantity() const { return quantity; }
RepairOrder Material::getRepairOrder() const { return repairOrder; }

void Material::setName(const std::string& name) { this->name = name; }
void Material::setCost(double cost) { this->cost = cost; }
void Material::setQuantity(int quantity) { this->quantity = quantity; }
void Material::setRepairOrder(const RepairOrder& repairOrder) { this->repairOrder = repairOrder; }

void Material::printDetails() const {
    std::cout << "Material ID: " << id << "\n"
        << "Name: " << name << "\n"
        << "Cost: " << cost << "\n"
        << "Quantity: " << quantity << "\n"
        << "Associated Repair Order ID: " << repairOrder.getId() << "\n";
}
