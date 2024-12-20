#include "pch.h"
#include "../REMONT/Warranty.h"
#include "../REMONT/Warranty.cpp"
#include <gtest/gtest.h>

// Тест конструктора
TEST(WarrantyTest, ConstructorTest) {
    Warranty warranty(101, "Standard Repair", 12, "Free repairs for 1 year");

    EXPECT_EQ(warranty.getWarrantyId(), 101);
    EXPECT_EQ(warranty.getService(), "Standard Repair");
    EXPECT_EQ(warranty.getDurationMonths(), 12);
    EXPECT_EQ(warranty.getTerms(), "Free repairs for 1 year");
}

// Тест геттеров
TEST(WarrantyTest, GettersTest) {
    Warranty warranty(102, "Extended Warranty", 24, "Free repairs for 2 years");

    EXPECT_EQ(warranty.getWarrantyId(), 102);
    EXPECT_EQ(warranty.getService(), "Extended Warranty");
    EXPECT_EQ(warranty.getDurationMonths(), 24);
    EXPECT_EQ(warranty.getTerms(), "Free repairs for 2 years");
}