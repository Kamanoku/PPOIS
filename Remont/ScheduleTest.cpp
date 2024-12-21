#include"pch.h"
#include "../REMONT/Schedule.h"
#include "../REMONT/Schedule.cpp"
#include "../REMONT/Client.h"
#include "../REMONT/Department.h"
#include "../REMONT/Employee.h"
#include <gtest/gtest.h>
#include <sstream>


TEST(ScheduleTest, ConstructorTest) {
    RepairOrder repairOrder(1, "Engine Repair", 300.0, Client(1, "John Doe", "123-456-7890", Employee(1, "Jane Smith", 30, 4000.0, Department(1, "Maintenance"))), Employee(1, "Jane Smith", 30, 4000.0, Department(1, "Maintenance")));
    Technician technician(1, "Alice Johnson", 5, "Engine Specialist", repairOrder);

    Schedule schedule(1, "2024-12-25", "10:00 AM - 12:00 PM", technician, repairOrder);

    EXPECT_EQ(schedule.getId(), 1);
    EXPECT_EQ(schedule.getDate(), "2024-12-25");
    EXPECT_EQ(schedule.getTimeSlot(), "10:00 AM - 12:00 PM");
    EXPECT_EQ(schedule.getTechnician().getName(), "Alice Johnson");
    EXPECT_EQ(schedule.getRepairOrder().getId(), 1);
}


TEST(ScheduleTest, GettersTest) {
    RepairOrder repairOrder(2, "Brake Replacement", 150.0, Client(2, "Jane Smith", "987-654-3210", Employee(2, "Bob White", 35, 5000.0, Department(2, "Service"))), Employee(2, "Bob White", 35, 5000.0, Department(2, "Service")));
    Technician technician(2, "Bob Smith", 10, "Brake Specialist", repairOrder);

    Schedule schedule(2, "2024-12-26", "2:00 PM - 4:00 PM", technician, repairOrder);

    EXPECT_EQ(schedule.getId(), 2);
    EXPECT_EQ(schedule.getDate(), "2024-12-26");
    EXPECT_EQ(schedule.getTimeSlot(), "2:00 PM - 4:00 PM");
    EXPECT_EQ(schedule.getTechnician().getName(), "Bob Smith");
    EXPECT_EQ(schedule.getRepairOrder().getId(), 2);
}


TEST(ScheduleTest, SettersTest) {
    RepairOrder repairOrder(3, "Tire Change", 100.0, Client(3, "Sam Green", "555-123-4567", Employee(3, "Charlie Brown", 40, 6000.0, Department(3, "Repair"))), Employee(3, "Charlie Brown", 40, 6000.0, Department(3, "Repair")));
    Technician technician(3, "Charlie Brown", 7, "Tire Specialist", repairOrder);

    Schedule schedule(3, "2024-12-27", "9:00 AM - 11:00 AM", technician, repairOrder);


    schedule.setDate("2024-12-28");
    schedule.setTimeSlot("11:00 AM - 1:00 PM");
    schedule.setTechnician(Technician(4, "David Lee", 5, "Wheel Alignment Specialist", repairOrder));
    schedule.setRepairOrder(RepairOrder(4, "Oil Change", 75.0, Client(4, "Mike Black", "444-789-1230", Employee(4, "Eva White", 28, 4800.0, Department(4, "Installation"))), Employee(4, "Eva White", 28, 4800.0, Department(4, "Installation"))));

    EXPECT_EQ(schedule.getDate(), "2024-12-28");
    EXPECT_EQ(schedule.getTimeSlot(), "11:00 AM - 1:00 PM");
    EXPECT_EQ(schedule.getTechnician().getName(), "David Lee");
    EXPECT_EQ(schedule.getRepairOrder().getId(), 4);
}


TEST(ScheduleTest, PrintDetailsTest) {
    RepairOrder repairOrder(5, "Window Tinting", 250.0, Client(5, "Mike Black", "444-789-1230", Employee(5, "Eva White", 28, 4800.0, Department(5, "Installation"))), Employee(5, "Eva White", 28, 4800.0, Department(5, "Installation")));
    Technician technician(5, "Eva White", 4, "Tinting Specialist", repairOrder);

    Schedule schedule(5, "2024-12-29", "1:00 PM - 3:00 PM", technician, repairOrder);

    std::ostringstream output;
    std::streambuf* oldCoutBuffer = std::cout.rdbuf();
    std::cout.rdbuf(output.rdbuf());

    schedule.printDetails(); 

    std::cout.rdbuf(oldCoutBuffer);

    std::string expectedOutput =
        "Schedule ID: 5\n"
        "Date: 2024-12-29\n"
        "Time Slot: 1:00 PM - 3:00 PM\n"
        "Technician: Eva White\n"
        "Repair Order ID: 5\n";

    EXPECT_EQ(output.str(), expectedOutput);
}
