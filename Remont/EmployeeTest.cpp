#include"pch.h"
#include "../REMONT/Employee.h"
#include "../REMONT/Employee.cpp"
#include "../REMONT/Department.h"
#include <gtest/gtest.h>
#include <sstream>


TEST(EmployeeTest, ConstructorTest) {
    Department dept(1, "HR");
    Employee emp(100, "Alice", 30, 50000.0, dept);

    EXPECT_EQ(emp.getId(), 100);
    EXPECT_EQ(emp.getName(), "Alice");
    EXPECT_EQ(emp.getAge(), 30);
    EXPECT_DOUBLE_EQ(emp.getSalary(), 50000.0);
    EXPECT_EQ(emp.getDepartment().getName(), "HR");
}


TEST(EmployeeTest, GettersTest) {
    Department dept(2, "Finance");
    Employee emp(101, "Bob", 40, 60000.0, dept);

    EXPECT_EQ(emp.getId(), 101);
    EXPECT_EQ(emp.getName(), "Bob");
    EXPECT_EQ(emp.getAge(), 40);
    EXPECT_DOUBLE_EQ(emp.getSalary(), 60000.0);
    EXPECT_EQ(emp.getDepartment().getName(), "Finance");
}


TEST(EmployeeTest, SettersTest) {
    Department initialDept(3, "IT");
    Employee emp(102, "Charlie", 25, 40000.0, initialDept);

    emp.setName("Updated Charlie");
    emp.setAge(26);
    emp.setSalary(45000.0);

    Department newDept(4, "Engineering");
    emp.setDepartment(newDept);

    EXPECT_EQ(emp.getName(), "Updated Charlie");
    EXPECT_EQ(emp.getAge(), 26);
    EXPECT_DOUBLE_EQ(emp.getSalary(), 45000.0);
    EXPECT_EQ(emp.getDepartment().getName(), "Engineering");
}


TEST(EmployeeTest, PrintDetailsTest) {
    Department dept(5, "Support");
    Employee emp(103, "Diana", 35, 55000.0, dept);

    std::ostringstream output;
    std::streambuf* oldCoutBuffer = std::cout.rdbuf();
    std::cout.rdbuf(output.rdbuf());

    emp.printDetails();

    std::cout.rdbuf(oldCoutBuffer);

    std::string expectedOutput =
        "Employee ID: 103\n"
        "Name: Diana\n"
        "Age: 35\n"
        "Salary: 55000\n"
        "Department: Support\n";

    EXPECT_EQ(output.str(), expectedOutput);
}