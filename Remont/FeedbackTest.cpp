#include"pch.h"
#include "../REMONT/Feedback.h"
#include "../REMONT/Feedback.cpp"
#include "../REMONT/Client.h"
#include "../REMONT/Employee.h"
#include "../REMONT/Department.h"
#include <gtest/gtest.h>
#include <sstream>

// Тест конструктора
TEST(FeedbackTest, ConstructorTest) {
    Department dept(1, "HR");
    Employee emp(1, "John Doe", 30, 50000.0, dept);
    Client client(100, "Alice", "123456789", emp);
    Feedback feedback(200, "Great service!", 5, client);

    EXPECT_EQ(feedback.getId(), 200);
    EXPECT_EQ(feedback.getContent(), "Great service!");
    EXPECT_EQ(feedback.getRating(), 5);
    EXPECT_EQ(feedback.getClient().getName(), "Alice");
}

// Тест геттеров
TEST(FeedbackTest, GettersTest) {
    Department dept(2, "Finance");
    Employee emp(2, "Jane Smith", 35, 60000.0, dept);
    Client client(101, "Bob", "987654321", emp);
    Feedback feedback(201, "Satisfactory experience.", 4, client);

    EXPECT_EQ(feedback.getId(), 201);
    EXPECT_EQ(feedback.getContent(), "Satisfactory experience.");
    EXPECT_EQ(feedback.getRating(), 4);
    EXPECT_EQ(feedback.getClient().getName(), "Bob");
}

// Тест сеттеров
TEST(FeedbackTest, SettersTest) {
    Department dept(3, "IT");
    Employee emp(3, "Initial Employee", 25, 40000.0, dept);
    Client client(102, "Charlie", "555555555", emp);
    Feedback feedback(202, "Initial feedback.", 3, client);

    feedback.setContent("Updated feedback.");
    feedback.setRating(5);

    Department newDept(4, "Engineering");
    Employee newEmp(4, "Updated Employee", 40, 70000.0, newDept);
    Client newClient(103, "Updated Charlie", "444444444", newEmp);
    feedback.setClient(newClient);

    EXPECT_EQ(feedback.getContent(), "Updated feedback.");
    EXPECT_EQ(feedback.getRating(), 5);
    EXPECT_EQ(feedback.getClient().getName(), "Updated Charlie");
}

// Тест метода printDetails
TEST(FeedbackTest, PrintDetailsTest) {
    Department dept(5, "Support");
    Employee emp(5, "Print Employee", 28, 45000.0, dept);
    Client client(103, "Diana", "666666666", emp);
    Feedback feedback(203, "Excellent support!", 5, client);

    std::ostringstream output;
    std::streambuf* oldCoutBuffer = std::cout.rdbuf();
    std::cout.rdbuf(output.rdbuf());

    feedback.printDetails();

    std::cout.rdbuf(oldCoutBuffer);

    std::string expectedOutput =
        "Feedback ID: 203\n"
        "Content: Excellent support!\n"
        "Rating: 5\n"
        "Client: Diana\n";

    EXPECT_EQ(output.str(), expectedOutput);
}