#include "Client.h"
#include <iostream>

Client::Client(int id, const std::string& name, const std::string& phone, const Employee& employee)
    : id(id), name(name), phone(phone), assignedEmployee(employee) {
}

int Client::getId() const { return id; }
std::string Client::getName() const { return name; }
std::string Client::getPhone() const { return phone; }
Employee Client::getAssignedEmployee() const { return assignedEmployee; }

void Client::setName(const std::string& name) { this->name = name; }
void Client::setPhone(const std::string& phone) { this->phone = phone; }
void Client::setAssignedEmployee(const Employee& employee) { assignedEmployee = employee; }

void Client::printDetails() const {
    std::cout << "Client ID: " << id << "\n"
        << "Name: " << name << "\n"
        << "Phone: " << phone << "\n"
        << "Assigned Employee: " << assignedEmployee.getName() << "\n";
}
