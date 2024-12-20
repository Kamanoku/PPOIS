#include "pch.h"
#include "../REMONT/RepairHistory.h"
#include "../REMONT/RepairHistory.cpp"
#include <gtest/gtest.h>
#include <sstream>

// Тест конструктора
TEST(RepairHistoryTest, ConstructorTest) {
    RepairHistory repairHistory(101, "Engine Repair", "2024-12-10", "John Doe");

    EXPECT_EQ(repairHistory.getOrderId(), 101);
    EXPECT_EQ(repairHistory.getDescription(), "Engine Repair");
    EXPECT_EQ(repairHistory.getDate(), "2024-12-10");
    EXPECT_EQ(repairHistory.getTechnician(), "John Doe");
}

// Тест геттеров
TEST(RepairHistoryTest, GettersTest) {
    RepairHistory repairHistory(102, "Brake Replacement", "2024-11-15", "Jane Smith");

    EXPECT_EQ(repairHistory.getOrderId(), 102);
    EXPECT_EQ(repairHistory.getDescription(), "Brake Replacement");
    EXPECT_EQ(repairHistory.getDate(), "2024-11-15");
    EXPECT_EQ(repairHistory.getTechnician(), "Jane Smith");
}
