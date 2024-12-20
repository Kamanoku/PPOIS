#ifndef MATRIX_H
#define MATRIX_H
#include"Matrix.h"

Matrix::Matrix() : row(0), column(0), value(nullptr) {}
Matrix::Matrix(int rows, int cols) : row(rows), column(cols) {
	value = new double[row * column](); // ������������� ������
}
Matrix::Matrix(const Matrix& other) : row(other.row), column(other.column) {
	value = new double[row * column]; // ��������������, ��� `value` � ��� ��������� �� ������
	for (int i = 0; i < row * column; ++i) {
		value[i] = other.value[i]; // ����������� ��������
	}
}

Matrix::~Matrix()
{
	delete[] value;
}
int Matrix::getRow() const
{
		return row;	
}
int Matrix::getColumn() const {
		return column;
	}
	double* Matrix::getValue() const {
		return value;
	}



void Matrix::file(const std::string& filename) {
		std::ifstream reading(filename);

		if (!reading) {
			std::cout << "�� ������� ������� ���� " << filename << "!" << std::endl;
			return;
		}

		int n, column;
		// ������ �������� �������
		if (!(reading >> n >> column)) {
			std::cout << "������ ������ �������� ������� �� �����." << std::endl;
			return;
		}

		std::cout << "������� ������� �� �����: " << n << " �����, " << column << " ��������." << std::endl;

		// �������� ������������ ��������
		if (n <= 0 || column <= 0) {
			std::cout << "������������ ������� ������� � �����." << std::endl;
			return;
		}

		// ������������ ���������� ������
		delete[] value;
		value = nullptr;

		// ������������� �������
		row = n;
		this->column = column;
		value = new double[row * column];

		// ������ ��������� �������
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < column; j++) {
				if (!(reading >> value[i * column + j])) {
					std::cout << "������ ������ �������� ������� [" << i << "][" << j << "]." << std::endl;
					delete[] value;
					value = nullptr;
					row = 0;
					this->column = 0;
					return;
				}
				std::cout << "�������� ������� [" << i << "][" << j << "]: " << value[i * column + j] << std::endl;
			}
		}

		std::cout << "������� ������� ������� �� ����� " << filename << "." << std::endl;
	}

void Matrix::by_hand(Matrix& Mymatrix, int row, int column)
{
	delete[] value;

	int stroka, stolbec;

	Mymatrix.row = row;
	Mymatrix.column = column;
	Mymatrix.value = new double[row * column];
	cout << "������� �������� ������� (" << row << "x" << column << "):\n";
	for (stroka = 0; stroka < Mymatrix.row; stroka++) {
		for (stolbec = 0; stolbec < Mymatrix.column; stolbec++)
			cin >>Mymatrix.value[stroka * Mymatrix.column + stolbec];
		
	}
}

Matrix Matrix::transposition() const {
	Matrix Helpmatrix;
	Helpmatrix.row = column;
	Helpmatrix.column = row;
	Helpmatrix.value = new double[Helpmatrix.row * Helpmatrix.column];

	for (int i = 0; i < row; ++i)
		for (int j = 0; j < column; ++j)
			Helpmatrix.value[j * row + i] = value[i * column + j];
	
	return Helpmatrix;
}



void Matrix::ChangeStroka(Matrix& Mymatrix)
{	
	int stroka,raznica;

	cout << "������� ����� �� ������ ��������" << endl;
	cin >> stroka;
	raznica = row - stroka;	
	row -= raznica;
}

bool Matrix::ChangeStolbec(int newCols) {
	if (newCols <= 0) {
		std::cout << "������������ ���������� ��������." << std::endl;
		return false;
	}

	double* newValue = new double[row * newCols];

	// ���������� ����������� ���������� �������� ��� �����������
	int minCols = (newCols < column) ? newCols : column;

	// �������� ������ �������� � �����, ���� ��� ����������
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < minCols; ++j) {
			newValue[i * newCols + j] = value[i * column + j];
		}
		// ���������� ���������� �������� ������, ���� �����
		for (int j = minCols; j < newCols; ++j) {
			newValue[i * newCols + j] = 0.0;
		}
	}

	delete[] value;
	value = newValue;
	column = newCols;

	return true;
}






bool Matrix::isSquare() const {
	return row == column;
}




bool Matrix::isDiagonal() const {
	if (!isSquare()) return false;
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < column; ++j) {
			if (i != j && value[i * column + j] != 0.0) {
				return false;
			}
		}
	}
	return true;
}




bool Matrix::isZero() const {
	for (int i = 0; i < row * column; ++i) {
		if (value[i] != 0.0) {
			return false;
		}
	}
	return true;
}




bool Matrix::isIdentity() const {
	if (!isSquare()) return false;
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < column; ++j) {
			if (i == j && value[i * column + j] != 1.0) {
				return false;
			}
			if (i != j && value[i * column + j] != 0.0) {
				return false;
			}
		}
	}
	return true;
}

bool Matrix::isSymmetric() const {
	if (!isSquare()) return false;
	for (int i = 0; i < row; i++) {
		for (int j = i + 1; j < column; j++) {
			if (value[i * column + j] != value[j * row + i]) {
				return false;
			}
		}
	}
	return true;
}

bool Matrix::isUpperTriangular() const {
	if (!isSquare()) return false;
	for (int i = 1; i < row; i++) {
		for (int j = 0; j < i; j++) {
			if (value[i * column + j] != 0.0) {
				return false;
			}
		}
	}
	return true;
}

bool Matrix::isLowerTriangular() const {
	if (!isSquare()) return false;
	for (int i = 0; i < row; i++) {
		for (int j = i + 1; j < column; j++) {
			if (value[i * column + j] != 0.0) {
				return false;
			}
		}
	}
	return true;
}


Matrix Matrix::PodMatrix() const 
{
	Matrix PodMatrix;
	int stroka, stolbec;
	cout << "����� ������ ����������?(X*Y)\n";
	cin >> stroka;
	cin >> stolbec;

	PodMatrix.row = stroka;
	PodMatrix.column = stolbec;
	PodMatrix.value = new double[PodMatrix.row * PodMatrix.column];
	for (int i = 0; i < PodMatrix.row; i++) {
		for (int j = 0; j < PodMatrix.column; j++) {
			PodMatrix.value[i * PodMatrix.column + j] = value[i * column + j];
			
		}
	}
	return PodMatrix;
	
}

void Matrix::initialize(double value) {
	for (int i = 0; i < row * column; ++i) {
		this->value[i] = value; // ������������� ����������
	}
}

void Matrix::Show() const {
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < column; ++j) {
			std::cout << std::fixed << std::setprecision(1) << value[i * column + j];
			if (j < column - 1) {
				std::cout << " "; // ������ ����� ����������
			}
		}
		std::cout << "\n"; // ������� �� ����� ������ ����� ������ ������ �������
	}
}

ostream& operator<<(ostream& os, const Matrix& matrix) {
	for (int i = 0; i < matrix.row; ++i) {
		for (int j = 0; j < matrix.column; ++j) {
			os << fixed << setprecision(1) << matrix.value[i * matrix.column + j];
			if (j < matrix.column - 1) {
				os << " "; // ������ ����� ����������
			}
		}
		os << "\n"; // ������� �� ����� ������ ����� ������ ������ �������
	}
	return os;
}


istream& operator >> (istream& is, Matrix& Mymatrix) {
	for (int i = 0; i < Mymatrix.row; i++) {
		for (int j = 0; j < Mymatrix.column; j++) {
			is >> Mymatrix.value[i * Mymatrix.column + j];
		}
	}
	return is;
}

Matrix& Matrix::operator++() {
	for (int i = 0; i < row * column; ++i) {
		value[i] += 1; // ����������� ������ ������� �� 1
	}
	return *this; // ���������� ������ �� ������� ������
}

Matrix Matrix::operator++(int) {
	Matrix temp = *this; // ��������� ������� ���������
	++(*this); // ����� ����������� ����������
	return temp; // ���������� ������ ���������
}

Matrix& Matrix::operator--() {
	for (int i = 0; i < row * column; ++i) {
		value[i] -= 1; // ��������� ������ ������� �� 1
	}
	return *this; // ���������� ������ �� ������� ������
}

Matrix Matrix::operator--(int) {
	Matrix temp = *this; // ��������� ������� ���������
	--(*this); // ����� ����������� ����������
	return temp; // ���������� ������ ���������
}


Matrix& Matrix::operator=(const Matrix& other)
{
	if (this == &other)
	{
		return *this;
	}

	delete[] value;

	row = other.row;
	column = other.column;

	if (other.value)
	{
		value = new double[row * column];
		for (int i = 0; i < row * column; ++i)
		{
			value[i] = other.value[i];
		}
	}
	else
	{
		value = nullptr;
	}

	return *this;
}
bool Matrix::operator==(const Matrix& other) const {
	if (row != other.row || column != other.column) return false;
	for (int i = 0; i < row * column; ++i) {
		if (value[i] != other.value[i]) {
			return false;
		}
	}
	return true;
}
bool Matrix::operator!=(const Matrix& other) const {
	return !(*this == other); // ���������� ��������� ��������� == ���������������
}
#endif // MATRIX_H