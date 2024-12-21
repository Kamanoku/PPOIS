#include "pch.h"
#include "../REMONT/Invoice.h"
#include "../REMONT/Invoice.cpp"
#include "../REMONT/Client.h"
#include "../REMONT/Employee.h"
#include "../REMONT/Department.h"
#include "../REMONT/RepairOrder.h"
#include <gtest/gtest.h>
#include <sstream>


TEST(InvoiceTest, ConstructorTest) {
    Department dept(1, "Mechanics");
    Employee employee(1, "John Doe", 35, 50000.0, dept);
    Client client(101, "Alice", "123456789", employee);
    RepairOrder repairOrder(201, "Fix brakes", 200.0, client, employee);
    Invoice invoice(301, 250.0, "2024-12-20", client, repairOrder);

    EXPECT_EQ(invoice.getId(), 301);
    EXPECT_DOUBLE_EQ(invoice.getTotalAmount(), 250.0);
    EXPECT_EQ(invoice.getIssueDate(), "2024-12-20");
    EXPECT_EQ(invoice.getClient().getName(), "Alice");
    EXPECT_EQ(invoice.getRepairOrder().getId(), 201);
}

TEST(InvoiceTest, GettersTest) {
    Department dept(2, "Electronics");
    Employee employee(2, "Jane Smith", 30, 45000.0, dept);
    Client client(102, "Bob", "987654321", employee);
    RepairOrder repairOrder(202, "Battery replacement", 100.0, client, employee);
    Invoice invoice(302, 120.0, "2024-12-21", client, repairOrder);

    EXPECT_EQ(invoice.getId(), 302);
    EXPECT_DOUBLE_EQ(invoice.getTotalAmount(), 120.0);
    EXPECT_EQ(invoice.getIssueDate(), "2024-12-21");
    EXPECT_EQ(invoice.getClient().getName(), "Bob");
    EXPECT_EQ(invoice.getRepairOrder().getId(), 202);
}


TEST(InvoiceTest, SettersTest) {
    Department dept(3, "Welding");
    Employee employee(3, "Mark Technician", 40, 55000.0, dept);
    Client client(103, "Charlie", "444444444", employee);
    RepairOrder repairOrder(203, "Engine repair", 300.0, client, employee);
    Invoice invoice(303, 350.0, "2024-12-22", client, repairOrder);

   
    invoice.setTotalAmount(400.0);
    invoice.setIssueDate("2024-12-25");

    Department newDept(4, "Painting");
    Employee newEmployee(4, "Sophia Painter", 32, 48000.0, newDept);
    Client newClient(104, "Diana", "555555555", newEmployee);
    RepairOrder newRepairOrder(204, "Paint job", 500.0, newClient, newEmployee);

    invoice.setClient(newClient);
    invoice.setRepairOrder(newRepairOrder);

    EXPECT_DOUBLE_EQ(invoice.getTotalAmount(), 400.0);
    EXPECT_EQ(invoice.getIssueDate(), "2024-12-25");
    EXPECT_EQ(invoice.getClient().getName(), "Diana");
    EXPECT_EQ(invoice.getRepairOrder().getId(), 204);
}


TEST(InvoiceTest, PrintDetailsTest) {
    Department dept(5, "Bodywork");
    Employee employee(5, "Tom Bodyworker", 28, 46000.0, dept);
    Client client(105, "Emma", "666666666", employee);
    RepairOrder repairOrder(205, "Dent repair", 150.0, client, employee);
    Invoice invoice(305, 180.0, "2024-12-26", client, repairOrder);

    std::ostringstream output;
    std::streambuf* oldCoutBuffer = std::cout.rdbuf();
    std::cout.rdbuf(output.rdbuf());

    invoice.printDetails();

    std::cout.rdbuf(oldCoutBuffer);

    std::string expectedOutput =
        "Invoice ID: 305\n"
        "Total Amount: 180\n"
        "Issue Date: 2024-12-26\n"
        "Client: Emma\n"
        "Associated Repair Order ID: 205\n";

    EXPECT_EQ(output.str(), expectedOutput);
}
