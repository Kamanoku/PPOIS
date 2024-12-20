#pragma once
#include <string>
#include "RepairOrder.h"

class Service {
private:
    int id;
    std::string name;
    double price;
    RepairOrder repairOrder; // Ассоциация: услуга связана с заказом на ремонт

public:
    Service(int id, const std::string& name, double price, const RepairOrder& repairOrder);

    int getId() const;
    std::string getName() const;
    double getPrice() const;
    RepairOrder getRepairOrder() const;

    void setName(const std::string& name);
    void setPrice(double price);
    void setRepairOrder(const RepairOrder& repairOrder);

    void printDetails() const;
};
