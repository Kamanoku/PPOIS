#pragma once
#include <string>
#include "RepairOrder.h"

class Material {
private:
    int id;
    std::string name;
    double cost;
    int quantity;
    RepairOrder repairOrder; 

public:
    Material(int id, const std::string& name, double cost, int quantity, const RepairOrder& repairOrder);

    int getId() const;
    std::string getName() const;
    double getCost() const;
    int getQuantity() const;
    RepairOrder getRepairOrder() const;

    void setName(const std::string& name);
    void setCost(double cost);
    void setQuantity(int quantity);
    void setRepairOrder(const RepairOrder& repairOrder);

    void printDetails() const;
};
