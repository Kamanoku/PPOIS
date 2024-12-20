#include "SparePart.h"
#include <iostream>

SparePart::SparePart(int id, const std::string& name, double price, int stock, const RepairOrder& repairOrder)
    : id(id), name(name), price(price), stock(stock), repairOrder(repairOrder) {
}

int SparePart::getId() const { return id; }
std::string SparePart::getName() const { return name; }
double SparePart::getPrice() const { return price; }
int SparePart::getStock() const { return stock; }
RepairOrder SparePart::getRepairOrder() const { return repairOrder; }

void SparePart::setName(const std::string& name) { this->name = name; }
void SparePart::setPrice(double price) { this->price = price; }
void SparePart::setStock(int stock) { this->stock = stock; }
void SparePart::setRepairOrder(const RepairOrder& repairOrder) { this->repairOrder = repairOrder; }

void SparePart::printDetails() const {
    std::cout << "Spare Part ID: " << id << "\n"
        << "Name: " << name << "\n"
        << "Price: " << price << "\n"
        << "Stock: " << stock << "\n"
        << "Associated Repair Order ID: " << repairOrder.getId() << "\n";
}
