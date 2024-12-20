#include "Service.h"
#include <iostream>

Service::Service(int id, const std::string& name, double price, const RepairOrder& repairOrder)
    : id(id), name(name), price(price), repairOrder(repairOrder) {
}

int Service::getId() const { return id; }
std::string Service::getName() const { return name; }
double Service::getPrice() const { return price; }
RepairOrder Service::getRepairOrder() const { return repairOrder; }

void Service::setName(const std::string& name) { this->name = name; }
void Service::setPrice(double price) { this->price = price; }
void Service::setRepairOrder(const RepairOrder& repairOrder) { this->repairOrder = repairOrder; }

void Service::printDetails() const {
    std::cout << "Service ID: " << id << "\n"
        << "Name: " << name << "\n"
        << "Price: " << price << "\n"
        << "Associated Repair Order ID: " << repairOrder.getId() << "\n";
}
