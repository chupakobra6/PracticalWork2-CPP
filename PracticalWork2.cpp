#include <iostream>
#include <Windows.h>
#include <stdio.h>

using namespace std;

void Function7(int** matrix, int n, int m)
{
	int summ = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			summ += matrix[i][j];
		}
	}

	cout << "\nСумма: " << summ << "\n\n";
}

void Function4(int* array, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << array[i] << "\n";
	}
}

void Function2(int* first, int* second)
{
	int buffer = *first;
	*first = *second;
	*second = buffer;
}

int RecursiveFactorial(int i, int factorial)
{
	factorial *= i;

	if (i != 1)
	{
		RecursiveFactorial(i - 1, factorial);
	}
	else {
		return factorial;
	}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int choice;

	do
	{
		cout << "Выберите задачу:\n 1 - факториал\n 2 - изменение значения\n 3 - сумма элементов массива\n 4 - вывод элементов массива\n 5 - среднее арифметическое массива\n 6 - вывод чисел на экран\n 7 - двумерный массива\n 8 - наименьший элемент массива\n 9 - выход\n";
		cin >> choice;

		if (choice == 1)
		{
			int i;
			cout << "Введите число:";
			cin >> i;

			cout << RecursiveFactorial(i, 1) << "\n";
		}

		else if (choice == 2)
		{
			int a = 11;
			int b = 22;

			Function2(&a, &b);

			cout << a << "\n" << b << "\n";
		}

		else if (choice == 3)
		{
			int n;
			int summ = 0;

			cout << "Введите кол-во чисел: ";
			cin >> n;

			int* arraysize = new int[n];

			for (int i = 0; i < n; i++)
			{
				int buffer;
				cin >> buffer;
				arraysize[i] = buffer;
				summ += buffer;
			}

			cout << "Сумма: " << summ << "\n";
		}

		else if (choice == 4)
		{
			int numbers[] = { 1, 2, 3, 4, 5 };
			int* array{ numbers };

			Function4(array, 5);
		}

		else if (choice == 5)
		{
			double n;
			double summ = 0;

			cout << "Введите кол-во чисел: ";
			cin >> n;

			int* arraysize = new int[n];

			for (int i = 0; i < n; i++)
			{
				int buffer;
				cin >> buffer;
				arraysize[i] = buffer;
				summ += buffer;
			}

			double divorse = summ / n;

			cout << "Среднее арифметическое: " << divorse << "\n";
		}

		else if (choice == 6)
		{
			int n;
			int summ = 0;

			cout << "Введите кол-во чисел: ";
			cin >> n;

			int* arraysize = new int[n];

			for (int i = 0; i < n; i++)
			{
				int buffer;
				cin >> buffer;
				arraysize[i] = buffer;
			}

			Function4(arraysize, n);
		}

		else if (choice == 7)
		{
			cout << "Введите размерность двумерного массива[N][M]: ";
			int n, m;
			cin >> n >> m;

			cout << "\n";

			int** matrix;
			matrix = new int* [n];
			for (int i = 0; i < n; i++)
			{
				matrix[i] = new int[m];
			}

			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{
					matrix[i][j] = rand() % 100 + 1;
					cout << matrix[i][j] << "\t";
				}
				cout << "\n";
			}

			Function7(matrix, n, m);

			/*for (int i = 0; i < n; i++)
			{
				delete matrix[i];
				delete []matrix;
			}*/ // удаление

		}

		else if (choice == 8)
		{
			int n;
			cout << "Размер n массива: ";
			cin >> n;

			int* array = new int[n];
			for (int i = 0; i < n; i++)
			{
				array[i] = rand() % 100 + 1;
			}

			int min = 100;
			for (int i = 0; i < n; i++)
			{
				if (array[i] < min)
				{
					min = array[i];
				}

				cout << array[i] << "\t";
			}


			cout << "\nМинимальное значение: " << min << "\n";
		}

	} while (true);
}