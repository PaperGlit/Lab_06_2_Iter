#include <iostream>
#include <time.h>
#include <windows.h>

using namespace std;

void Create(int* a, const int size, const int Low, const int High)
{
	for (int i = 0; i < size; i++)
		a[i] = Low + rand() % (High - Low + 1);
}

void Print(int* a, const int size)
{
	cout << "Значення масиву : ";
	for (int i = 0; i < size; i++)
		cout << a[i] << " ";
	cout << endl;
}

int Max(int* a, const int size)
{
	int max = 0;
	for (int i = 0; i < size; i++)
		if (a[i] % 2 != 0)
		{
			max = a[i];
			break;
		}
	for (int i = 0; i < size; i++)
		if (a[i] % 2 != 0 && a[i] > max)
			max = a[i];
	return max;
}

int iMax(int* a, const int size)
{
	int max = 0, imax = 0;
	for (int i = 0; i < size; i++)
		if (a[i] % 2 != 0)
		{
			max = a[i];
			imax = i;
			break;
		}
	for (int i = 0; i < size; i++)
		if (a[i] % 2 != 0 && a[i] > max)
		{
			max = a[i];
			imax = i;
		}
	return imax;
}

int* Swap(int* a, const int size)
{
	int* c = a;
	int imax = iMax(a, size), temp = c[size - 1];
	c[size - 1] = c[imax];
	c[imax] = temp;
	return c;
}

int main()
{
	SetConsoleOutputCP(1251);
	srand((unsigned)time(NULL));

	int n, Low, High;

	cout << "n = "; cin >> n;
	cout << "min = "; cin >> Low;
	cout << "max = "; cin >> High;

	int* c = new int[n];

	Create(c, n, Low, High);
	Print(c, n);
	cout << "Значення, яке підходить вимогам : " << Max(c, n) << endl;
	Print(Swap(c, n), n);

	return 0;
}