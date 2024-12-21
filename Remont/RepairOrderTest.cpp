#include "pch.h"
#include "../REMONT/RepairOrder.h"
#include "../REMONT/RepairOrder.cpp"
#include "../REMONT/Client.h"
#include "../REMONT/Employee.h"
#include "../REMONT/Department.h"
#include <gtest/gtest.h>
#include <sstream>

TEST(RepairOrderTest, ConstructorTest) {
    Department dept(1, "Mechanics");
    Employee technician(1, "John Mechanic", 35, 40000.0, dept);
    Client client(100, "Alice", "123456789", technician);
    RepairOrder order(200, "Engine repair", 1500.0, client, technician);

    EXPECT_EQ(order.getId(), 200);
    EXPECT_EQ(order.getDescription(), "Engine repair");
    EXPECT_DOUBLE_EQ(order.getCost(), 1500.0);
    EXPECT_EQ(order.getClient().getName(), "Alice");
    EXPECT_EQ(order.getTechnician().getName(), "John Mechanic");
}


TEST(RepairOrderTest, GettersTest) {
    Department dept(2, "Electronics");
    Employee technician(2, "Jane Electrician", 30, 45000.0, dept);
    Client client(101, "Bob", "987654321", technician);
    RepairOrder order(201, "Battery replacement", 500.0, client, technician);

    EXPECT_EQ(order.getId(), 201);
    EXPECT_EQ(order.getDescription(), "Battery replacement");
    EXPECT_DOUBLE_EQ(order.getCost(), 500.0);
    EXPECT_EQ(order.getClient().getName(), "Bob");
    EXPECT_EQ(order.getTechnician().getName(), "Jane Electrician");
}


TEST(RepairOrderTest, SettersTest) {
    Department dept(3, "IT");
    Employee initialTechnician(3, "Initial Tech", 28, 35000.0, dept);
    Client client(102, "Charlie", "555555555", initialTechnician);
    RepairOrder order(202, "Initial repair", 1200.0, client, initialTechnician);

    
    order.setDescription("Updated repair");
    order.setCost(1400.0);

    
    Department newDept(4, "Welding");
    Employee newTechnician(4, "Updated Tech", 40, 50000.0, newDept);
    Client newClient(103, "Updated Charlie", "444444444", newTechnician);
    order.setClient(newClient);
    order.setTechnician(newTechnician);

    EXPECT_EQ(order.getDescription(), "Updated repair");
    EXPECT_DOUBLE_EQ(order.getCost(), 1400.0);
    EXPECT_EQ(order.getClient().getName(), "Updated Charlie");
    EXPECT_EQ(order.getTechnician().getName(), "Updated Tech");
}


TEST(RepairOrderTest, PrintDetailsTest) {
    Department dept(5, "Bodywork");
    Employee technician(5, "Print Technician", 45, 55000.0, dept);
    Client client(103, "Diana", "666666666", technician);
    RepairOrder order(203, "Brake replacement", 800.0, client, technician);

    std::ostringstream output;
    std::streambuf* oldCoutBuffer = std::cout.rdbuf();
    std::cout.rdbuf(output.rdbuf());

    order.printDetails();

    std::cout.rdbuf(oldCoutBuffer);

    std::string expectedOutput =
        "Order ID: 203\n"
        "Description: Brake replacement\n"
        "Cost: 800\n"
        "Client: Diana\n"
        "Technician: Print Technician\n";

    EXPECT_EQ(output.str(), expectedOutput);
}
