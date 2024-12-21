#include"pch.h"
#include "../REMONT/Department.h"
#include "../REMONT/Department.cpp"
#include <gtest/gtest.h>


TEST(DepartmentTest, ConstructorTest) {
    Department department(1, "HR");
    EXPECT_EQ(department.getId(), 1);
    EXPECT_EQ(department.getName(), "HR");
}

TEST(DepartmentTest, GettersTest) {
    Department department(2, "Finance");
    EXPECT_EQ(department.getId(), 2);
    EXPECT_EQ(department.getName(), "Finance");
}


TEST(DepartmentTest, SetNameTest) {
    Department department(3, "IT");
    department.setName("Engineering");
    EXPECT_EQ(department.getName(), "Engineering");
}