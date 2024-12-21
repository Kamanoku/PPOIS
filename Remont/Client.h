#pragma once
#include <string>
#include "Employee.h"

class Client {
private:
    int id;
    std::string name;
    std::string phone;
    Employee assignedEmployee; // Ассоциация: Client связан с Employee

public:
    Client(int id, const std::string& name, const std::string& phone, const Employee& employee);

    int getId() const;
    std::string getName() const;
    std::string getPhone() const;
    Employee getAssignedEmployee() const;

    void setName(const std::string& name);
    void setPhone(const std::string& phone);
    void setAssignedEmployee(const Employee& employee);

    void printDetails() const;
};
