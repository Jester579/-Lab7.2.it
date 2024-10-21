#include <iostream>
#include <iomanip>
#include <time.h>
#include <Windows.h>
#define RED "\033[31m"
#define RESET "\033[0m"
using namespace std;

void Create(int** a, const int k, const int n, const int Low, const int High);
void Print(int** a, const int k, const int n, int* minInOddRows);
int Sum(int** a, const int k, const int n, int* minInOddRows);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand((unsigned)time(NULL));

	int Low = 7;
	int High = 65;
	int k, n;

	cout << "k = "; cin >> k;
	cout << "n = "; cin >> n;

	int** a = new int* [k];
	for (int i = 0; i < k; i++)
		a[i] = new int[n];

	int* MIN = new int[k];  

	Create(a, k, n, Low, High);
	int sum = Sum(a, k, n, MIN);  
	Print(a, k, n, MIN);  

	cout << "Сума мінімальних елементів по непарних рядках = " << sum << endl;

	// Очищуємо пам'ять
	for (int i = 0; i < k; i++)
		delete[] a[i];
	delete[] a;
	delete[] MIN;

	return 0;
}

void Create(int** a, const int k, const int n, const int Low, const int High)
{
	for (int i = 0; i < k; i++)
		for (int j = 0; j < n; j++)
			a[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** a, const int k, const int n, int* MIN)
{
	cout << endl;
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i % 2 != 0 && a[i][j] == MIN[i])
				cout << RED << setw(4) << a[i][j] << RESET;
			else
				cout << setw(4) << a[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

int Sum(int** a, const int k, const int n, int* MIN)
{
	int sum = 0;

	for (int i = 1; i < k; i += 2)
	{
		int min = a[i][0];
		for (int j = 1; j < n; j++)
		{
			if (a[i][j] < min)
				min = a[i][j];
		}
		MIN[i] = min;  
		sum += min;
	}

	return sum;
}
