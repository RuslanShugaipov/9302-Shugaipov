#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\Руслан\source\repos\АлгиСтр(Лр 2)\АлгиСтр(Лр 2)\Sort_Search_Algorithms.cpp"
#include "C:\Users\Руслан\source\repos\АлгиСтр(Лр 2)\АлгиСтр(Лр 2)\Sort_Search_Algorithms.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(Sort_Search_Algorithms)
	{
	public:
		int array1[9] = { 1,4,9,16,25,36,49,64,81 };
		TEST_METHOD(binarysearch)
		{
			Assert::AreEqual(BinarySearch(array1, 9, 16), 3);
			Assert::AreEqual(BinarySearch(array1, 9, 81), 8);
			Assert::AreEqual(BinarySearch(array1, 9, -54), -1);
		}
		int array21[5] = { 21,12,654,743,43 };
		int array22[5] = { 2345,-54,23,2765,754 };
		TEST_METHOD(quicksort)
		{
			QuickSort(array21, 5);
			QuickSort(array22, 5);
			Assert::AreEqual(array21[1], 21);
			Assert::AreEqual(array22[4], 2765);
		}
		int array31[5] = { 5,4,3,2,1 };
		int array32[5] = { 124,54,765,34,8 };
		TEST_METHOD(bubblesort)
		{
			BubbleSort(array31, 5);
			BubbleSort(array32, 5);
			Assert::AreEqual(array31[1], 2);
			Assert::AreEqual(array32[4], 765);
		}
		int array41[5] = { 43,8,5,8,4 };
		int array42[5] = { 12,97,6,4,7 };
		TEST_METHOD(bogosort)
		{
			BogoSort(array41, 5);
			BogoSort(array42, 5);
			Assert::AreEqual(array41[1], 5);
			Assert::AreEqual(array42[4], 97);
		}
		char array6[6] = { 'f','e','d','c','b','a' };
		TEST_METHOD(countingsort)
		{
			CountingSort(array6, 6);
			Assert::AreEqual(array6[0], 'a');
			Assert::AreEqual(array6[1], 'b');
			Assert::AreEqual(array6[2], 'c');
			Assert::AreEqual(array6[3], 'd');
			Assert::AreEqual(array6[4], 'e');
			Assert::AreEqual(array6[5], 'f');
		}
	};
}
