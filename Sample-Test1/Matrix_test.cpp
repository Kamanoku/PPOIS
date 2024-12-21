#include "pch.h"
#include "../Matrix_1/Matrix.h"
#include "../Matrix_1/Matrix.cpp"
#include <gtest/gtest.h>
#include <sstream> 
#include <ostream> 

TEST(MatrixTest, GetRow) {
    Matrix matrix(3, 4);
    EXPECT_EQ(matrix.getRow(), 3);
}

TEST(MatrixTest, GetColumn) {
    Matrix matrix(3, 4);
    EXPECT_EQ(matrix.getColumn(), 4);
}

TEST(MatrixTest, ByHand) {
    Matrix matrix;
    matrix.by_hand(matrix, 2, 2);
    EXPECT_EQ(matrix.getRow(), 2);
    EXPECT_EQ(matrix.getColumn(), 2);
}

TEST(MatrixTest, OperatorAssignment) {
    Matrix matrix1(2, 2);
    matrix1.initialize(1.0);

    Matrix matrix2 = matrix1;
    EXPECT_EQ(matrix2.getValue()[0], 1.0);
    EXPECT_EQ(matrix2.getValue()[1], 1.0);
    EXPECT_EQ(matrix2.getValue()[2], 1.0);
    EXPECT_EQ(matrix2.getValue()[3], 1.0);
}

TEST(MatrixTest, OperatorInput) {
    Matrix matrix(2, 2);
    std::istringstream input("1.0 2.0 3.0 4.0");
    input >> matrix;
    EXPECT_EQ(matrix.getValue()[0], 1.0);
    EXPECT_EQ(matrix.getValue()[1], 2.0);
    EXPECT_EQ(matrix.getValue()[2], 3.0);
    EXPECT_EQ(matrix.getValue()[3], 4.0);
}

TEST(MatrixTest, OperatorOutput) {
    Matrix matrix(2, 2);
    matrix.initialize(1.0);
    std::ostringstream output;
    output << matrix;
    EXPECT_EQ(output.str(), "1.0 1.0\n1.0 1.0\n");
}

TEST(MatrixTest, Show) {
    Matrix matrix(2, 2);
    matrix.initialize(5.0);
    testing::internal::CaptureStdout();
    matrix.Show();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "5.0 5.0\n5.0 5.0\n");
}

TEST(MatrixTest, ChangeStolbec) {
    Matrix matrix(2, 3);
    matrix.initialize(1.0);
    matrix.ChangeStolbec(2);
    EXPECT_EQ(matrix.getColumn(), 2);
    EXPECT_EQ(matrix.getValue()[0], 1.0);
    EXPECT_EQ(matrix.getValue()[1], 1.0);
    EXPECT_EQ(matrix.getValue()[2], 1.0);
    EXPECT_EQ(matrix.getValue()[3], 1.0);
}

TEST(MatrixTest, Transposition) {
    Matrix matrix(2, 3);
    matrix.initialize(1.0);
    Matrix transposed = matrix.transposition();
    EXPECT_EQ(transposed.getRow(), 3);
    EXPECT_EQ(transposed.getColumn(), 2);
}

TEST(MatrixTest, IsSquare) {
    Matrix squareMatrix(2, 2);
    Matrix nonSquareMatrix(2, 3);
    EXPECT_TRUE(squareMatrix.isSquare());
    EXPECT_FALSE(nonSquareMatrix.isSquare());
}

TEST(MatrixTest, IsDiagonal) {
    Matrix diagonalMatrix(3, 3);
    diagonalMatrix.initialize(0.0);
    diagonalMatrix.getValue()[0] = 1.0;
    diagonalMatrix.getValue()[4] = 1.0;
    diagonalMatrix.getValue()[8] = 1.0;
    EXPECT_TRUE(diagonalMatrix.isDiagonal());

    Matrix nonDiagonalMatrix(3, 3);
    nonDiagonalMatrix.initialize(1.0);
    EXPECT_FALSE(nonDiagonalMatrix.isDiagonal());
}

TEST(MatrixTest, IsZero) {
    Matrix zeroMatrix(3, 3);
    zeroMatrix.initialize(0.0);
    EXPECT_TRUE(zeroMatrix.isZero());

    Matrix nonZeroMatrix(3, 3);
    nonZeroMatrix.initialize(1.0);
    EXPECT_FALSE(nonZeroMatrix.isZero());
}

TEST(MatrixTest, IsIdentity) {
    Matrix identityMatrix(3, 3);
    identityMatrix.initialize(0.0);
    identityMatrix.getValue()[0] = 1.0;
    identityMatrix.getValue()[4] = 1.0;
    identityMatrix.getValue()[8] = 1.0;
    EXPECT_TRUE(identityMatrix.isIdentity());

    Matrix nonIdentityMatrix(3, 3);
    nonIdentityMatrix.initialize(1.0);
    EXPECT_FALSE(nonIdentityMatrix.isIdentity());
}

TEST(MatrixTest, IsSymmetric) {
    Matrix symmetricMatrix(2, 2);
    symmetricMatrix.getValue()[0] = 1.0;
    symmetricMatrix.getValue()[1] = 2.0;
    symmetricMatrix.getValue()[2] = 2.0;
    symmetricMatrix.getValue()[3] = 1.0;
    EXPECT_TRUE(symmetricMatrix.isSymmetric());

    Matrix nonSymmetricMatrix(2, 2);
    nonSymmetricMatrix.getValue()[0] = 1.0;
    nonSymmetricMatrix.getValue()[1] = 2.0;
    nonSymmetricMatrix.getValue()[2] = 3.0;
    nonSymmetricMatrix.getValue()[3] = 4.0;
    EXPECT_FALSE(nonSymmetricMatrix.isSymmetric());
}

TEST(MatrixTest, IsUpperTriangular) {
    Matrix upperTriangularMatrix(3, 3);
    upperTriangularMatrix.getValue()[0] = 1.0;
    upperTriangularMatrix.getValue()[1] = 2.0;
    upperTriangularMatrix.getValue()[2] = 3.0;
    upperTriangularMatrix.getValue()[3] = 0.0;
    upperTriangularMatrix.getValue()[4] = 4.0;
    upperTriangularMatrix.getValue()[5] = 5.0;
    upperTriangularMatrix.getValue()[6] = 0.0;
    upperTriangularMatrix.getValue()[7] = 0.0;
    upperTriangularMatrix.getValue()[8] = 6.0;
    EXPECT_TRUE(upperTriangularMatrix.isUpperTriangular());

    Matrix nonUpperTriangularMatrix(3, 3);
    nonUpperTriangularMatrix.getValue()[0] = 1.0;
    nonUpperTriangularMatrix.getValue()[1] = 2.0;
    nonUpperTriangularMatrix.getValue()[2] = 3.0;
    nonUpperTriangularMatrix.getValue()[3] = 4.0;
    nonUpperTriangularMatrix.getValue()[4] = 5.0;
    nonUpperTriangularMatrix.getValue()[5] = 6.0;
    nonUpperTriangularMatrix.getValue()[6] = 0.0;
    nonUpperTriangularMatrix.getValue()[7] = 0.0;
    nonUpperTriangularMatrix.getValue()[8] = 0.0;
    EXPECT_FALSE(nonUpperTriangularMatrix.isUpperTriangular());
}

TEST(MatrixTest, IsLowerTriangular) {
    Matrix lowerTriangularMatrix(3, 3);
    lowerTriangularMatrix.getValue()[0] = 1.0;
    lowerTriangularMatrix.getValue()[1] = 0.0;
    lowerTriangularMatrix.getValue()[3] = 3.0;
    lowerTriangularMatrix.getValue()[4] = 4.0;
    EXPECT_TRUE(lowerTriangularMatrix.isLowerTriangular());

    Matrix nonLowerTriangularMatrix(3, 3);
    nonLowerTriangularMatrix.getValue()[1] = 2.0;
    EXPECT_FALSE(nonLowerTriangularMatrix.isLowerTriangular());
}

TEST(MatrixTest, PodMatrix) {
    Matrix matrix(3, 3);
    matrix.initialize(1.0);

    matrix.getValue()[0] = 1.1;
    matrix.getValue()[1] = 1.2;
    matrix.getValue()[2] = 1.3;
    matrix.getValue()[3] = 2.1;
    matrix.getValue()[4] = 2.2;
    matrix.getValue()[5] = 2.3;
    matrix.getValue()[6] = 3.1;
    matrix.getValue()[7] = 3.2;
    matrix.getValue()[8] = 3.3;

    Matrix podMatrix = matrix.PodMatrix(); 

    EXPECT_EQ(podMatrix.getRow(), 2);
    EXPECT_EQ(podMatrix.getColumn(), 2);
    EXPECT_DOUBLE_EQ(podMatrix.getValue()[0], 1.1);
    EXPECT_DOUBLE_EQ(podMatrix.getValue()[1], 1.2);
    EXPECT_DOUBLE_EQ(podMatrix.getValue()[2], 2.1);
    EXPECT_DOUBLE_EQ(podMatrix.getValue()[3], 2.2);
}

TEST(MatrixTest, IncrementOperators) {
    Matrix matrix(2, 2);
    matrix.initialize(1.0);

    Matrix incrementedMatrix = ++matrix;

    EXPECT_EQ(incrementedMatrix.getValue()[0], 2.0);
    EXPECT_EQ(incrementedMatrix.getValue()[1], 2.0);
    EXPECT_EQ(incrementedMatrix.getValue()[2], 2.0);
    EXPECT_EQ(incrementedMatrix.getValue()[3], 2.0);

    EXPECT_EQ(matrix.getValue()[0], 2.0);
    EXPECT_EQ(matrix.getValue()[1], 2.0);
    EXPECT_EQ(matrix.getValue()[2], 2.0);
    EXPECT_EQ(matrix.getValue()[3], 2.0);

    Matrix oldMatrix = matrix++;

    EXPECT_EQ(oldMatrix.getValue()[0], 2.0);
    EXPECT_EQ(oldMatrix.getValue()[1], 2.0);
    EXPECT_EQ(oldMatrix.getValue()[2], 2.0);
    EXPECT_EQ(oldMatrix.getValue()[3], 2.0);

    EXPECT_EQ(matrix.getValue()[0], 3.0);
    EXPECT_EQ(matrix.getValue()[1], 3.0);
    EXPECT_EQ(matrix.getValue()[2], 3.0);
    EXPECT_EQ(matrix.getValue()[3], 3.0);
}

TEST(MatrixTest, DecrementOperators) {
    Matrix matrix(2, 2);
    matrix.initialize(2.0);

    Matrix decrementedMatrix = --matrix;

    EXPECT_EQ(decrementedMatrix.getValue()[0], 1.0);
    EXPECT_EQ(decrementedMatrix.getValue()[1], 1.0);
    EXPECT_EQ(decrementedMatrix.getValue()[2], 1.0);
    EXPECT_EQ(decrementedMatrix.getValue()[3], 1.0);

    EXPECT_EQ(matrix.getValue()[0], 1.0);
    EXPECT_EQ(matrix.getValue()[1], 1.0);
    EXPECT_EQ(matrix.getValue()[2], 1.0);
    EXPECT_EQ(matrix.getValue()[3], 1.0);

    Matrix oldMatrix = matrix--;

    EXPECT_EQ(oldMatrix.getValue()[0], 1.0);
    EXPECT_EQ(oldMatrix.getValue()[1], 1.0);
    EXPECT_EQ(oldMatrix.getValue()[2], 1.0);
    EXPECT_EQ(oldMatrix.getValue()[3], 1.0);

    EXPECT_EQ(matrix.getValue()[0], 0.0);
    EXPECT_EQ(matrix.getValue()[1], 0.0);
    EXPECT_EQ(matrix.getValue()[2], 0.0);
    EXPECT_EQ(matrix.getValue()[3], 0.0);
}

TEST(MatrixTest, InitializeMethod) {
    Matrix matrix(2, 2);
    matrix.initialize(5.0);

    EXPECT_EQ(matrix.getValue()[0], 5.0);
    EXPECT_EQ(matrix.getValue()[1], 5.0);
    EXPECT_EQ(matrix.getValue()[2], 5.0);
    EXPECT_EQ(matrix.getValue()[3], 5.0);
}

TEST(MatrixTest, EqualityOperator) {
    Matrix matrix1(2, 2);
    matrix1.initialize(1.0);

    Matrix matrix2(2, 2);
    matrix2.initialize(1.0);

    EXPECT_EQ(matrix1, matrix2);

    matrix2.initialize(2.0);
    EXPECT_NE(matrix1, matrix2);
}

TEST(MatrixTest, InequalityOperator) {
    Matrix matrix1(2, 2);
    matrix1.initialize(1.0);

    Matrix matrix2(2, 2);
    matrix2.initialize(2.0);

    EXPECT_NE(matrix1, matrix2);
}

TEST(MatrixTest, AssignmentOperator) {
    Matrix matrix1(2, 2);
    matrix1.initialize(5.0);

    Matrix matrix2;
    matrix2 = matrix1;

    EXPECT_EQ(matrix2.getRow(), 2);
    EXPECT_EQ(matrix2.getColumn(), 2);
    EXPECT_DOUBLE_EQ(matrix2.getValue()[0], 5.0);
    EXPECT_DOUBLE_EQ(matrix2.getValue()[1], 5.0);
    EXPECT_DOUBLE_EQ(matrix2.getValue()[2], 5.0);
    EXPECT_DOUBLE_EQ(matrix2.getValue()[3], 5.0);

    matrix2 = matrix2;
    EXPECT_EQ(matrix2.getRow(), 2);
    EXPECT_EQ(matrix2.getColumn(), 2);
    EXPECT_DOUBLE_EQ(matrix2.getValue()[0], 5.0);
    EXPECT_DOUBLE_EQ(matrix2.getValue()[1], 5.0);
    EXPECT_DOUBLE_EQ(matrix2.getValue()[2], 5.0);
    EXPECT_DOUBLE_EQ(matrix2.getValue()[3], 5.0);

    Matrix matrix3;
    matrix3 = matrix2;
    EXPECT_EQ(matrix3.getRow(), 2);
    EXPECT_EQ(matrix3.getColumn(), 2);
    EXPECT_DOUBLE_EQ(matrix3.getValue()[0], 5.0);
    EXPECT_DOUBLE_EQ(matrix3.getValue()[1], 5.0);
    EXPECT_DOUBLE_EQ(matrix3.getValue()[2], 5.0);
    EXPECT_DOUBLE_EQ(matrix3.getValue()[3], 5.0);
}
