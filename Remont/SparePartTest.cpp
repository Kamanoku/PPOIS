#include "pch.h"
#include "../REMONT/SparePart.h"
#include "../REMONT/SparePart.cpp"
#include "../REMONT/RepairOrder.h"
#include "../REMONT/Client.h"
#include "../REMONT/Employee.h"
#include "../REMONT/Department.h"
#include <gtest/gtest.h>
#include <sstream>


TEST(SparePartTest, ConstructorTest) {
    RepairOrder repairOrder(1, "Engine Repair", 300.0, Client(1, "John Doe", "123-456-7890", Employee(1, "Jane Smith", 30, 4000.0, Department(1, "Maintenance"))), Employee(1, "Jane Smith", 30, 4000.0, Department(1, "Maintenance")));

    SparePart sparePart(1, "Brake Pad", 50.0, 100, repairOrder);

    EXPECT_EQ(sparePart.getId(), 1);
    EXPECT_EQ(sparePart.getName(), "Brake Pad");
    EXPECT_EQ(sparePart.getPrice(), 50.0);
    EXPECT_EQ(sparePart.getStock(), 100);
    EXPECT_EQ(sparePart.getRepairOrder().getId(), 1);
}


TEST(SparePartTest, GettersTest) {
    RepairOrder repairOrder(2, "Brake Replacement", 150.0, Client(2, "Jane Smith", "987-654-3210", Employee(2, "Bob White", 35, 5000.0, Department(2, "Service"))), Employee(2, "Bob White", 35, 5000.0, Department(2, "Service")));

    SparePart sparePart(2, "Oil Filter", 25.0, 200, repairOrder);

    EXPECT_EQ(sparePart.getId(), 2);
    EXPECT_EQ(sparePart.getName(), "Oil Filter");
    EXPECT_EQ(sparePart.getPrice(), 25.0);
    EXPECT_EQ(sparePart.getStock(), 200);
    EXPECT_EQ(sparePart.getRepairOrder().getId(), 2);
}


TEST(SparePartTest, SettersTest) {
    RepairOrder repairOrder(3, "Tire Change", 100.0, Client(3, "Sam Green", "555-123-4567", Employee(3, "Charlie Brown", 40, 6000.0, Department(3, "Repair"))), Employee(3, "Charlie Brown", 40, 6000.0, Department(3, "Repair")));

    SparePart sparePart(3, "Windshield Wiper", 15.0, 150, repairOrder);


    sparePart.setName("Tire Valve");
    sparePart.setPrice(30.0);
    sparePart.setStock(120);
    sparePart.setRepairOrder(RepairOrder(4, "Battery Replacement", 80.0, Client(4, "Mike Black", "444-789-1230", Employee(4, "Eva White", 28, 4800.0, Department(4, "Installation"))), Employee(4, "Eva White", 28, 4800.0, Department(4, "Installation"))));

    EXPECT_EQ(sparePart.getName(), "Tire Valve");
    EXPECT_EQ(sparePart.getPrice(), 30.0);
    EXPECT_EQ(sparePart.getStock(), 120);
    EXPECT_EQ(sparePart.getRepairOrder().getId(), 4);
}


TEST(SparePartTest, PrintDetailsTest) {
    RepairOrder repairOrder(5, "Window Tinting", 250.0, Client(5, "Mike Black", "444-789-1230", Employee(5, "Eva White", 28, 4800.0, Department(5, "Installation"))), Employee(5, "Eva White", 28, 4800.0, Department(5, "Installation")));

    SparePart sparePart(5, "Air Filter", 20.0, 80, repairOrder);

    std::ostringstream output;
    std::streambuf* oldCoutBuffer = std::cout.rdbuf();
    std::cout.rdbuf(output.rdbuf());

    sparePart.printDetails(); 

    std::cout.rdbuf(oldCoutBuffer);

    std::string expectedOutput =
        "Spare Part ID: 5\n"
        "Name: Air Filter\n"
        "Price: 20\n"
        "Stock: 80\n"
        "Associated Repair Order ID: 5\n";

    EXPECT_EQ(output.str(), expectedOutput);
}
