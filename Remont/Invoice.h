#pragma once
#include <string>
#include "Client.h"
#include "RepairOrder.h"

class Invoice {
private:
    int id;
    double totalAmount;
    std::string issueDate;
    Client client;        
    RepairOrder repairOrder; 

public:
    Invoice(int id, double totalAmount, const std::string& issueDate, const Client& client, const RepairOrder& repairOrder);

    int getId() const;
    double getTotalAmount() const;
    std::string getIssueDate() const;
    Client getClient() const;
    RepairOrder getRepairOrder() const;

    void setTotalAmount(double totalAmount);
    void setIssueDate(const std::string& issueDate);
    void setClient(const Client& client);
    void setRepairOrder(const RepairOrder& repairOrder);

    void printDetails() const;
};
