#pragma once
#include <string>
#include "Client.h"
#include "Employee.h"

class RepairOrder {
private:
    int id;
    std::string description;
    double cost;
    Client client;         
    Employee technician;   

public:
    RepairOrder(int id, const std::string& description, double cost, const Client& client, const Employee& technician);

    int getId() const;
    std::string getDescription() const;
    double getCost() const;
    Client getClient() const;
    Employee getTechnician() const;

    void setDescription(const std::string& description);
    void setCost(double cost);
    void setClient(const Client& client);
    void setTechnician(const Employee& technician);

    void printDetails() const;
};
