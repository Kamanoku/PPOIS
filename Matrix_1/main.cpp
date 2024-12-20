#include "Matrix.h"
#include <iostream>
int		stateMenu, other_stateMenu, row, column;

void Menu() {
	cout << "Выберите действие: " << endl
		<< "(0) Выход из программы " << endl
		<< "(1) Задание матрицы вручную" << endl
		<< "(2) Просмотр матрицы" << endl
		<< "(3) Загрузка матрицы из файла " << endl
		<< "(4) Транспонирование матрицы " << endl
		<< "(5) Проверка типа матрицы" << endl
		<< "(6) Инкремент " << endl
		<< "(7) Декремент " << endl
		<< "(8) Извлечение подматрицы " << endl
		<< "(9) Изменение количества строк " << endl
		<< "(10) Изменение количества столбцов" << endl
		<< "Ваш выбор: ";
	cin >> stateMenu;
}


void Type(const Matrix& Type) {
	cout << "\nПроверка типов матрицы:\n";
	cout << "Квадратная: " << (Type.isSquare() ? "Да" : "Нет") << endl;
	cout << "Диагональная: " << (Type.isDiagonal() ? "Да" : "Нет") << endl;
	cout << "Нулевая: " << (Type.isZero() ? "Да" : "Нет") << endl;
	cout << "Единичная: " << (Type.isIdentity() ? "Да" : "Нет") << endl;
	cout << "Симметричная: " << (Type.isSymmetric() ? "Да" : "Нет") << endl;
	cout << "Верхняя треугольная: " << (Type.isUpperTriangular() ? "Да" : "Нет") << endl;
	cout << "Нижняя треугольная: " << (Type.isLowerTriangular() ? "Да" : "Нет") << endl;
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
			cout << "Введите количество строк матрицы" << endl;
			cin >> row; '\n';
cout << "Введите количество колонн матрицы" << endl;
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
			cout << "Транспонированная матрица:\n" << Helpmatrix;
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
				cout << "Пре- или постинкремент? " << endl
					<< "(0) Выход из программы " << endl
					<< "(1) Преинкремент " << endl
					<< "(2) Постинкремент " << endl
					<< "Ваш выбор: ";
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
				cout << "Пре- или постинкремент? " << endl
					<< "(0) Выход из программы " << endl
					<< "(1) Предекремент " << endl
					<< "(2) Постдекремент " << endl
					<< "Ваш выбор: ";
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
			cout << "сколько столбцов вы хотите оставить" << endl;
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