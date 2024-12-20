#include "Payment.h"
#include <iostream>

Payment::Payment(int id, double amount, const std::string& date, const Client& client, const Invoice& invoice)
    : id(id), amount(amount), date(date), client(client), invoice(invoice) {
}

int Payment::getId() const { return id; }
double Payment::getAmount() const { return amount; }
std::string Payment::getDate() const { return date; }
Client Payment::getClient() const { return client; }
Invoice Payment::getInvoice() const { return invoice; }

void Payment::setAmount(double amount) { this->amount = amount; }
void Payment::setDate(const std::string& date) { this->date = date; }
void Payment::setClient(const Client& client) { this->client = client; }
void Payment::setInvoice(const Invoice& invoice) { this->invoice = invoice; }

void Payment::printDetails() const {
    std::cout << "Payment ID: " << id << "\n"
        << "Amount: " << amount << "\n"
        << "Date: " << date << "\n"
        << "Client: " << client.getName() << "\n"
        << "Invoice ID: " << invoice.getId() << "\n";
}
