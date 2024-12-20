#include "RepairOrder.h"
#include <iostream>

RepairOrder::RepairOrder(int id, const std::string& description, double cost, const Client& client, const Employee& technician)
    : id(id), description(description), cost(cost), client(client), technician(technician) {
}

int RepairOrder::getId() const { return id; }
std::string RepairOrder::getDescription() const { return description; }
double RepairOrder::getCost() const { return cost; }
Client RepairOrder::getClient() const { return client; }
Employee RepairOrder::getTechnician() const { return technician; }

void RepairOrder::setDescription(const std::string& description) { this->description = description; }
void RepairOrder::setCost(double cost) { this->cost = cost; }
void RepairOrder::setClient(const Client& client) { this->client = client; }
void RepairOrder::setTechnician(const Employee& technician) { this->technician = technician; }

void RepairOrder::printDetails() const {
    std::cout << "Order ID: " << id << "\n"
        << "Description: " << description << "\n"
        << "Cost: " << cost << "\n"
        << "Client: " << client.getName() << "\n"
        << "Technician: " << technician.getName() << "\n";
}
