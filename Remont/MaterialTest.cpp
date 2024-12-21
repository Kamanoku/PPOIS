#include "pch.h"
#include "../REMONT/Material.h"
#include "../REMONT/Material.cpp"
#include "../REMONT/RepairOrder.h"
#include "../REMONT/Client.h"
#include "../REMONT/Employee.h"
#include "../REMONT/Department.h"
#include <gtest/gtest.h>
#include <sstream>


TEST(MaterialTest, ConstructorTest) {
    Department dept(1, "Mechanics");
    Employee employee(1, "John Doe", 35, 50000.0, dept);
    Client client(101, "Alice", "123456789", employee);
    RepairOrder repairOrder(201, "Fix brakes", 200.0, client, employee);
    Material material(301, "Brake pads", 50.0, 4, repairOrder);

    EXPECT_EQ(material.getId(), 301);
    EXPECT_EQ(material.getName(), "Brake pads");
    EXPECT_DOUBLE_EQ(material.getCost(), 50.0);
    EXPECT_EQ(material.getQuantity(), 4);
    EXPECT_EQ(material.getRepairOrder().getId(), 201);
}


TEST(MaterialTest, GettersTest) {
    Department dept(2, "Electronics");
    Employee employee(2, "Jane Smith", 30, 45000.0, dept);
    Client client(102, "Bob", "987654321", employee);
    RepairOrder repairOrder(202, "Battery replacement", 100.0, client, employee);
    Material material(302, "Battery", 120.0, 2, repairOrder);

    EXPECT_EQ(material.getId(), 302);
    EXPECT_EQ(material.getName(), "Battery");
    EXPECT_DOUBLE_EQ(material.getCost(), 120.0);
    EXPECT_EQ(material.getQuantity(), 2);
    EXPECT_EQ(material.getRepairOrder().getId(), 202);
}


TEST(MaterialTest, SettersTest) {
    Department dept(3, "Welding");
    Employee employee(3, "Mark Technician", 40, 55000.0, dept);
    Client client(103, "Charlie", "444444444", employee);
    RepairOrder repairOrder(203, "Engine repair", 300.0, client, employee);
    Material material(303, "Engine oil", 30.0, 5, repairOrder);

 
    material.setName("Premium Engine Oil");
    material.setCost(40.0);
    material.setQuantity(6);

    Department newDept(4, "Painting");
    Employee newEmployee(4, "Sophia Painter", 32, 48000.0, newDept);
    Client newClient(104, "Diana", "555555555", newEmployee);
    RepairOrder newRepairOrder(204, "Paint job", 500.0, newClient, newEmployee);

    material.setRepairOrder(newRepairOrder);

    EXPECT_EQ(material.getName(), "Premium Engine Oil");
    EXPECT_DOUBLE_EQ(material.getCost(), 40.0);
    EXPECT_EQ(material.getQuantity(), 6);
    EXPECT_EQ(material.getRepairOrder().getId(), 204);
}


TEST(MaterialTest, PrintDetailsTest) {
    Department dept(5, "Bodywork");
    Employee employee(5, "Tom Bodyworker", 28, 46000.0, dept);
    Client client(105, "Emma", "666666666", employee);
    RepairOrder repairOrder(205, "Dent repair", 150.0, client, employee);
    Material material(305, "Sheet metal", 20.0, 10, repairOrder);

    std::ostringstream output;
    std::streambuf* oldCoutBuffer = std::cout.rdbuf();
    std::cout.rdbuf(output.rdbuf());

    material.printDetails();

    std::cout.rdbuf(oldCoutBuffer);

    std::string expectedOutput =
        "Material ID: 305\n"
        "Name: Sheet metal\n"
        "Cost: 20\n"
        "Quantity: 10\n"
        "Associated Repair Order ID: 205\n";

    EXPECT_EQ(output.str(), expectedOutput);
}
