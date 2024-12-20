#pragma once
#include <string>
#include "RepairOrder.h"

class SparePart {
private:
    int id;
    std::string name;
    double price;
    int stock;
    RepairOrder repairOrder; // Ассоциация: запасная часть связана с заказом на ремонт

public:
    SparePart(int id, const std::string& name, double price, int stock, const RepairOrder& repairOrder);

    int getId() const;
    std::string getName() const;
    double getPrice() const;
    int getStock() const;
    RepairOrder getRepairOrder() const;

    void setName(const std::string& name);
    void setPrice(double price);
    void setStock(int stock);
    void setRepairOrder(const RepairOrder& repairOrder);

    void printDetails() const;
};
