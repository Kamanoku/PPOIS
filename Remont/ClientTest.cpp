#include"pch.h"
#include "../REMONT/Client.h"
#include "../REMONT/Client.cpp"
#include "../REMONT/Employee.h"
#include "../REMONT/Department.h"
#include <gtest/gtest.h>
#include <sstream>

// Тест конструктора
TEST(ClientTest, ConstructorTest) {
    Employee emp(1, "John Doe", 30, 50000.0, Department(1, "HR"));
    Client client(100, "Alice", "123456789", emp);

    EXPECT_EQ(client.getId(), 100);
    EXPECT_EQ(client.getName(), "Alice");
    EXPECT_EQ(client.getPhone(), "123456789");
    EXPECT_EQ(client.getAssignedEmployee().getName(), "John Doe");
}

// Тест геттеров
TEST(ClientTest, GettersTest) {
    Employee emp(2, "Jane Smith", 35, 60000.0, Department(2, "Finance"));
    Client client(101, "Bob", "987654321", emp);

    EXPECT_EQ(client.getId(), 101);
    EXPECT_EQ(client.getName(), "Bob");
    EXPECT_EQ(client.getPhone(), "987654321");
    EXPECT_EQ(client.getAssignedEmployee().getName(), "Jane Smith");
}

// Тест сеттеров
TEST(ClientTest, SettersTest) {
    Employee initialEmp(3, "Initial Employee", 25, 40000.0, Department(3, "IT"));
    Client client(102, "Charlie", "555555555", initialEmp);

    client.setName("Updated Charlie");
    client.setPhone("444444444");

    Employee updatedEmp(4, "Updated Employee", 40, 70000.0, Department(4, "Engineering"));
    client.setAssignedEmployee(updatedEmp);

    EXPECT_EQ(client.getName(), "Updated Charlie");
    EXPECT_EQ(client.getPhone(), "444444444");
    EXPECT_EQ(client.getAssignedEmployee().getName(), "Updated Employee");
}

// Тест метода printDetails
TEST(ClientTest, PrintDetailsTest) {
    Employee emp(5, "Print Employee", 28, 45000.0, Department(5, "Support"));
    Client client(103, "Diana", "666666666", emp);

    std::ostringstream output;
    std::streambuf* oldCoutBuffer = std::cout.rdbuf();
    std::cout.rdbuf(output.rdbuf());

    client.printDetails();

    std::cout.rdbuf(oldCoutBuffer);

    std::string expectedOutput =
        "Client ID: 103\n"
        "Name: Diana\n"
        "Phone: 666666666\n"
        "Assigned Employee: Print Employee\n";

    EXPECT_EQ(output.str(), expectedOutput);
}