#pragma once
#include <string>
#include "RepairOrder.h"

class Equipment {
private:
    int id;
    std::string name;
    std::string type;
    double cost;
    RepairOrder repairOrder; // Ассоциация: оборудование связано с заказом на ремонт

public:
    Equipment(int id, const std::string& name, const std::string& type, double cost, const RepairOrder& repairOrder);

    int getId() const;
    std::string getName() const;
    std::string getType() const;
    double getCost() const;
    RepairOrder getRepairOrder() const;

    void setName(const std::string& name);
    void setType(const std::string& type);
    void setCost(double cost);
    void setRepairOrder(const RepairOrder& repairOrder);

    void printDetails() const;
};
