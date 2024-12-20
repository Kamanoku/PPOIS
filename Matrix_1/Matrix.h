#pragma once

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <windows.h>



using namespace std;

class Matrix {
private:
	int row, column;
	double* value;
public:
	Matrix(); 
	Matrix(int rows, int cols);
	Matrix(const Matrix& other);  
	~Matrix();
	
	
	int getRow() const;
	int getColumn() const;	
	double* getValue() const;

	void Show() const;

	void file(const string& filename);
	void by_hand(Matrix& Mymatrix, int row, int column);
	
	Matrix transposition() const;

	void ChangeStroka(Matrix& Mymatrix);
	bool ChangeStolbec(int newCols);

	void initialize(double value);

	bool isSquare() const;
	bool isDiagonal() const;
	bool isZero() const;
	bool isIdentity() const;
	bool isSymmetric() const;
	bool isUpperTriangular() const;
	bool isLowerTriangular() const;
	Matrix PodMatrix()const;
	
	
	friend ostream& operator<<(ostream& os, const Matrix& Mymatrix);
	friend istream& operator>>(istream& is, Matrix& Mymatrix);
		
	 Matrix& operator++();
	 Matrix operator++(int);

	 Matrix& operator--();
	 Matrix operator--(int);

	 Matrix& operator=(const Matrix& other);
	 bool operator==(const Matrix& other) const;
	 bool operator!=(const Matrix& other) const;

};

