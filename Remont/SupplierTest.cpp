#include "pch.h"
#include "../REMONT/Supplier.h"
#include "../REMONT/Supplier.cpp"
#include <gtest/gtest.h>

// Тест конструктора
TEST(SupplierTest, ConstructorTest) {
    Supplier supplier(1, "ACME Corp.", "contact@acme.com");

    EXPECT_EQ(supplier.getSupplierId(), 1);
    EXPECT_EQ(supplier.getName(), "ACME Corp.");
    EXPECT_EQ(supplier.getContactInfo(), "contact@acme.com");
}

// Тест геттеров
TEST(SupplierTest, GettersTest) {
    Supplier supplier(2, "Best Suppliers Inc.", "contact@bestsuppliers.com");

    EXPECT_EQ(supplier.getSupplierId(), 2);
    EXPECT_EQ(supplier.getName(), "Best Suppliers Inc.");
    EXPECT_EQ(supplier.getContactInfo(), "contact@bestsuppliers.com");
}

