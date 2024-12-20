#include "Employee.h"
#include <iostream>

Employee::Employee(int id, const std::string& name, int age, double salary, const Department& dept)
    : id(id), name(name), age(age), salary(salary), department(dept) {
}

int Employee::getId() const { return id; }
std::string Employee::getName() const { return name; }
int Employee::getAge() const { return age; }
double Employee::getSalary() const { return salary; }
Department Employee::getDepartment() const { return department; }

void Employee::setName(const std::string& name) { this->name = name; }
void Employee::setAge(int age) { this->age = age; }
void Employee::setSalary(double salary) { this->salary = salary; }
void Employee::setDepartment(const Department& dept) { department = dept; }

void Employee::printDetails() const {
    std::cout << "Employee ID: " << id << "\n"
        << "Name: " << name << "\n"
        << "Age: " << age << "\n"
        << "Salary: " << salary << "\n"
        << "Department: " << department.getName() << "\n";
}
