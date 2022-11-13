#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_06_2_Iter/Lab_06_2_Iter.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

void Test(int* a, const int size)
{
	int max = 0, imax = 0;
	int* c = a;
	for (int i = 0; i < size; i++)
		if (a[i] % 2 != 0)
		{
			max = a[i];
			imax = i;
			break;
		}
	for (int i = 1; i < size; i++)
		if (a[i] % 2 != 0 && a[i] > max)
		{
			max = a[i];
			imax = i;
		}
	Assert::AreEqual(max, Max(a, size));
	Assert::AreEqual(imax, iMax(a, size));
	int temp = a[size - 1];
	a[size - 1] = a[imax];
	a[imax] = temp;
	c = Swap(c, size);
	for (int i = 0; i < size; i++)
		Assert::AreEqual(a[i], c[i]);
}

namespace UnitTestLab062Iter
{
	TEST_CLASS(UnitTestLab062Iter)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			const int n = 10;
			int c[n];
			int Low = -10, High = 10;
			Create(c, n, Low, High);
			Test(c, n);
		}
	};
}