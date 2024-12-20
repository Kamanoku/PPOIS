#include "Invoice.h"
#include <iostream>

Invoice::Invoice(int id, double totalAmount, const std::string& issueDate, const Client& client, const RepairOrder& repairOrder)
    : id(id), totalAmount(totalAmount), issueDate(issueDate), client(client), repairOrder(repairOrder) {
}

int Invoice::getId() const { return id; }
double Invoice::getTotalAmount() const { return totalAmount; }
std::string Invoice::getIssueDate() const { return issueDate; }
Client Invoice::getClient() const { return client; }
RepairOrder Invoice::getRepairOrder() const { return repairOrder; }

void Invoice::setTotalAmount(double totalAmount) { this->totalAmount = totalAmount; }
void Invoice::setIssueDate(const std::string& issueDate) { this->issueDate = issueDate; }
void Invoice::setClient(const Client& client) { this->client = client; }
void Invoice::setRepairOrder(const RepairOrder& repairOrder) { this->repairOrder = repairOrder; }

void Invoice::printDetails() const {
    std::cout << "Invoice ID: " << id << "\n"
        << "Total Amount: " << totalAmount << "\n"
        << "Issue Date: " << issueDate << "\n"
        << "Client: " << client.getName() << "\n"
        << "Associated Repair Order ID: " << repairOrder.getId() << "\n";
}
