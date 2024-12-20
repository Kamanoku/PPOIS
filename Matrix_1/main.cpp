#include "Matrix.h"
#include <iostream>
int		stateMenu, other_stateMenu, row, column;

void Menu() {
	cout << "�������� ��������: " << endl
		<< "(0) ����� �� ��������� " << endl
		<< "(1) ������� ������� �������" << endl
		<< "(2) �������� �������" << endl
		<< "(3) �������� ������� �� ����� " << endl
		<< "(4) ���������������� ������� " << endl
		<< "(5) �������� ���� �������" << endl
		<< "(6) ��������� " << endl
		<< "(7) ��������� " << endl
		<< "(8) ���������� ���������� " << endl
		<< "(9) ��������� ���������� ����� " << endl
		<< "(10) ��������� ���������� ��������" << endl
		<< "��� �����: ";
	cin >> stateMenu;
}


void Type(const Matrix& Type) {
	cout << "\n�������� ����� �������:\n";
	cout << "����������: " << (Type.isSquare() ? "��" : "���") << endl;
	cout << "������������: " << (Type.isDiagonal() ? "��" : "���") << endl;
	cout << "�������: " << (Type.isZero() ? "��" : "���") << endl;
	cout << "���������: " << (Type.isIdentity() ? "��" : "���") << endl;
	cout << "������������: " << (Type.isSymmetric() ? "��" : "���") << endl;
	cout << "������� �����������: " << (Type.isUpperTriangular() ? "��" : "���") << endl;
	cout << "������ �����������: " << (Type.isLowerTriangular() ? "��" : "���") << endl;
}


int main() {
	Matrix Mymatrix;
	Matrix Helpmatrix;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	

string filename;

Menu();
	while (stateMenu != 0)
	{
		switch (stateMenu)
		{
		case 1: {
			cout << "������� ���������� ����� �������" << endl;
			cin >> row; '\n';
cout << "������� ���������� ������ �������" << endl;
cin >> column; '\n';
			Mymatrix.by_hand( Mymatrix,  row, column);
			system("pause");
			system("cls");
			Menu();
			break;
		};
		case 2: {

			Mymatrix.Show();
			system("pause");
			system("cls");
			Menu();
			break;
		};
		case 3: {
			cin >> filename;
			Mymatrix.file(filename);

			system("pause");
			system("cls");
			Menu();
			break;
		};
		case 4: {
			Helpmatrix = Mymatrix.transposition();
			cout << "����������������� �������:\n" << Helpmatrix;
			system("pause");
			system("cls");
			Menu();
			break;
			
		};
		case 5: {
			Type(Mymatrix);
			system("pause");
			system("cls");
			Menu();
			break;
		};
		case 6: {
			other_stateMenu = 1;
			while (other_stateMenu != 0)
			{
				cout << "���- ��� �������������? " << endl
					<< "(0) ����� �� ��������� " << endl
					<< "(1) ������������ " << endl
					<< "(2) ������������� " << endl
					<< "��� �����: ";
				cin >> other_stateMenu;
				switch (other_stateMenu)
				{
				case 1: {
					++Mymatrix;
					break;
				}
				case 2: {
					Mymatrix++;
					break;
				}
				}
				break;
			}

			system("pause");
			system("cls");
			Menu();
			break;
		};
		case 7: {
			other_stateMenu = 1;
			while (other_stateMenu != 0)
			{
				cout << "���- ��� �������������? " << endl
					<< "(0) ����� �� ��������� " << endl
					<< "(1) ������������ " << endl
					<< "(2) ������������� " << endl
					<< "��� �����: ";
				cin >> other_stateMenu;
				switch (other_stateMenu)
				{
				case 1: {
					--Mymatrix;
					break;
				}
				case 2: {
					Mymatrix--;
					break;
				}
				}
				break;
			}

			system("pause");
			system("cls");
			Menu();
			break;
		};
		case 8: {
			
			Helpmatrix=Mymatrix.PodMatrix();
			cout <<"\n" << Helpmatrix;
			system("pause");
			system("cls");
			Menu();
			break;
		};
		case 9: {

			Mymatrix.ChangeStroka(Mymatrix);
			system("pause");
			system("cls");
			Menu();
			break;
		};
		case 10: {
			int newCols;
			cout << "������� �������� �� ������ ��������" << endl;
			cin >> newCols;
			Mymatrix.ChangeStolbec(newCols);
			system("pause");
			system("cls");
			Menu();
			break;
		};	
		}
	}
	return 0;
};