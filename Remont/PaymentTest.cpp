#include "pch.h"
#include "../REMONT/Payment.h"
#include "../REMONT/Payment.cpp"
#include "../REMONT/Client.h"
#include "../REMONT/Employee.h"
#include "../REMONT/Department.h"
#include "../REMONT/Invoice.h"
#include "../REMONT/RepairOrder.h"
#include <gtest/gtest.h>
#include <sstream>


TEST(PaymentTest, ConstructorTest) {
    Department dept(1, "Sales");
    Employee employee(1, "John Smith", 40, 60000.0, dept);
    Client client(101, "Alice Johnson", "123456789", employee);
    RepairOrder repairOrder(201, "Fix engine", 500.0, client, employee);
    Invoice invoice(301, 1000.0, "2024-12-01", client, repairOrder);
    Payment payment(401, 1000.0, "2024-12-15", client, invoice);

    EXPECT_EQ(payment.getId(), 401);
    EXPECT_DOUBLE_EQ(payment.getAmount(), 1000.0);
    EXPECT_EQ(payment.getDate(), "2024-12-15");
    EXPECT_EQ(payment.getClient().getId(), 101);
    EXPECT_EQ(payment.getInvoice().getId(), 301);
}


TEST(PaymentTest, GettersTest) {
    Department dept(2, "Maintenance");
    Employee employee(2, "Jane Doe", 35, 50000.0, dept);
    Client client(102, "Bob Williams", "987654321", employee);
    RepairOrder repairOrder(202, "Brake replacement", 300.0, client, employee);
    Invoice invoice(302, 600.0, "2024-11-20", client, repairOrder);
    Payment payment(402, 600.0, "2024-12-05", client, invoice);

    EXPECT_EQ(payment.getId(), 402);
    EXPECT_DOUBLE_EQ(payment.getAmount(), 600.0);
    EXPECT_EQ(payment.getDate(), "2024-12-05");
    EXPECT_EQ(payment.getClient().getName(), "Bob Williams");
    EXPECT_EQ(payment.getInvoice().getTotalAmount(), 600.0);
}

TEST(PaymentTest, SettersTest) {
    Department dept(3, "IT Support");
    Employee employee(3, "Mark Technician", 38, 55000.0, dept);
    Client client(103, "Charlie Brown", "555555555", employee);
    RepairOrder repairOrder(203, "Software installation", 150.0, client, employee);
    Invoice invoice(303, 200.0, "2024-10-15", client, repairOrder);
    Payment payment(403, 200.0, "2024-11-01", client, invoice);


    payment.setAmount(250.0);
    payment.setDate("2024-11-10");

    Department newDept(4, "HR");
    Employee newEmployee(4, "Sophia HR", 30, 48000.0, newDept);
    Client newClient(104, "Diana Prince", "444444444", newEmployee);
    RepairOrder newRepairOrder(204, "HR system upgrade", 400.0, newClient, newEmployee);
    Invoice newInvoice(304, 400.0, "2024-09-01", newClient, newRepairOrder);

    payment.setClient(newClient);
    payment.setInvoice(newInvoice);

    EXPECT_DOUBLE_EQ(payment.getAmount(), 250.0);
    EXPECT_EQ(payment.getDate(), "2024-11-10");
    EXPECT_EQ(payment.getClient().getName(), "Diana Prince");
    EXPECT_EQ(payment.getInvoice().getId(), 304);
}


TEST(PaymentTest, PrintDetailsTest) {
    Department dept(5, "Logistics");
    Employee employee(5, "Tom Logistics", 45, 65000.0, dept);
    Client client(105, "Emma Watson", "666666666", employee);
    RepairOrder repairOrder(205, "Shipping arrangement", 300.0, client, employee);
    Invoice invoice(305, 500.0, "2024-08-20", client, repairOrder);
    Payment payment(405, 500.0, "2024-09-01", client, invoice);

    std::ostringstream output;
    std::streambuf* oldCoutBuffer = std::cout.rdbuf();
    std::cout.rdbuf(output.rdbuf());

    payment.printDetails();

    std::cout.rdbuf(oldCoutBuffer);

    std::string expectedOutput =
        "Payment ID: 405\n"
        "Amount: 500\n"
        "Date: 2024-09-01\n"
        "Client: Emma Watson\n"
        "Invoice ID: 305\n";

    EXPECT_EQ(output.str(), expectedOutput);
}
