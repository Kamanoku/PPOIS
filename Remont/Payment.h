#pragma once
#include <string>
#include "Invoice.h"
#include "Client.h"

class Payment {
private:
    int id;
    double amount;
    std::string date;
    Client client;   
    Invoice invoice; 

public:
    Payment(int id, double amount, const std::string& date, const Client& client, const Invoice& invoice);

    int getId() const;
    double getAmount() const;
    std::string getDate() const;
    Client getClient() const;
    Invoice getInvoice() const;

    void setAmount(double amount);
    void setDate(const std::string& date);
    void setClient(const Client& client);
    void setInvoice(const Invoice& invoice);

    void printDetails() const;
};
