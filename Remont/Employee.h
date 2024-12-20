#pragma once
#include <string>
#include "Department.h"

class Employee {
private:
    int id;
    std::string name;
    int age;
    double salary;
    Department department; // Ассоциация: Employee связан с Department

public:
    Employee(int id, const std::string& name, int age, double salary, const Department& dept);

    int getId() const;
    std::string getName() const;
    int getAge() const;
    double getSalary() const;
    Department getDepartment() const;

    void setName(const std::string& name);
    void setAge(int age);
    void setSalary(double salary);
    void setDepartment(const Department& dept);

    void printDetails() const;
};
