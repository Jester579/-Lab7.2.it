#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab7.2.it/Source.cpp" // замініть шлях на правильний, якщо необхідно

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:

		TEST_METHOD(Test)
		{
			int k = 3, n = 3;
			int** a = new int* [k];
			for (int i = 0; i < k; i++)
				a[i] = new int[n];

			a[0][0] = 8; a[0][1] = 28; a[0][2] = 3;
			a[1][0] = 1; a[1][1] = 5; a[1][2] = 88;
			a[2][0] = 7; a[2][1] = 32; a[2][2] = 52;

			int min = a[1][0];
			Assert::AreEqual(min,1);

			for (int i = 0; i < k; i++)
				delete[] a[i];
			delete[] a;
		}
	};
}
