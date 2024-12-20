#include "pch.h"
#include "../REMONT/Technician.h"
#include "../REMONT/Technician.cpp"
#include <gtest/gtest.h>
#include <sstream>

// Тест конструктора
TEST(TechnicianTest, ConstructorTest) {
    RepairOrder repairOrder(1, "Engine Repair", 300.0, Client(1, "John Doe", "123-456-7890", Employee(1, "Jane Smith", 30, 4000.0, Department(1, "Maintenance"))), Employee(1, "Jane Smith", 30, 4000.0, Department(1, "Maintenance")));

    Technician technician(1, "Alice Johnson", 5, "Engine Specialist", repairOrder);

    EXPECT_EQ(technician.getId(), 1);
    EXPECT_EQ(technician.getName(), "Alice Johnson");
    EXPECT_EQ(technician.getExperienceYears(), 5);
    EXPECT_EQ(technician.getSpecialization(), "Engine Specialist");
    EXPECT_EQ(technician.getCurrentOrder().getId(), 1);
}

// Тест геттеров
TEST(TechnicianTest, GettersTest) {
    RepairOrder repairOrder(2, "Brake Replacement", 150.0, Client(2, "Jane Smith", "987-654-3210", Employee(2, "Bob White", 35, 5000.0, Department(2, "Service"))), Employee(2, "Bob White", 35, 5000.0, Department(2, "Service")));

    Technician technician(2, "Bob Smith", 10, "Brake Specialist", repairOrder);

    EXPECT_EQ(technician.getId(), 2);
    EXPECT_EQ(technician.getName(), "Bob Smith");
    EXPECT_EQ(technician.getExperienceYears(), 10);
    EXPECT_EQ(technician.getSpecialization(), "Brake Specialist");
    EXPECT_EQ(technician.getCurrentOrder().getId(), 2);
}

// Тест сеттеров
TEST(TechnicianTest, SettersTest) {
    RepairOrder repairOrder(3, "Tire Change", 100.0, Client(3, "Sam Green", "555-123-4567", Employee(3, "Charlie Brown", 40, 6000.0, Department(3, "Repair"))), Employee(3, "Charlie Brown", 40, 6000.0, Department(3, "Repair")));

    Technician technician(3, "Charlie Brown", 7, "Tire Specialist", repairOrder);

    // Обновление данных
    technician.setName("David Lee");
    technician.setExperienceYears(12);
    technician.setSpecialization("Wheel Alignment Specialist");
    technician.setCurrentOrder(RepairOrder(4, "Oil Change", 75.0, Client(4, "Mike Black", "444-789-1230", Employee(4, "Eva White", 28, 4800.0, Department(4, "Installation"))), Employee(4, "Eva White", 28, 4800.0, Department(4, "Installation"))));

    EXPECT_EQ(technician.getName(), "David Lee");
    EXPECT_EQ(technician.getExperienceYears(), 12);
    EXPECT_EQ(technician.getSpecialization(), "Wheel Alignment Specialist");
    EXPECT_EQ(technician.getCurrentOrder().getId(), 4);
}

// Тест метода вывода
TEST(TechnicianTest, PrintDetailsTest) {
    RepairOrder repairOrder(5, "Window Tinting", 250.0, Client(5, "Mike Black", "444-789-1230", Employee(5, "Eva White", 28, 4800.0, Department(5, "Installation"))), Employee(5, "Eva White", 28, 4800.0, Department(5, "Installation")));

    Technician technician(5, "Eva White", 4, "Tinting Specialist", repairOrder);

    std::ostringstream output;
    std::streambuf* oldCoutBuffer = std::cout.rdbuf();
    std::cout.rdbuf(output.rdbuf());

    technician.printDetails(); // Печать информации о технике

    std::cout.rdbuf(oldCoutBuffer);

    std::string expectedOutput =
        "Technician ID: 5\n"
        "Name: Eva White\n"
        "Experience Years: 4\n"
        "Specialization: Tinting Specialist\n"
        "Current Repair Order ID: 5\n";

    EXPECT_EQ(output.str(), expectedOutput);
}