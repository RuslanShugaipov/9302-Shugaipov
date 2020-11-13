#include <iostream>
#include "Sort_Search_Algorithms.h"
#include <ctime>
#include <fstream>

using namespace std;

void Show_Array_Char(char* array, const int array_size);
void Show_Array_Int(int* array, const int array_size);

void main()
{
	int required_el=16;
	const int array1_size = 9, array2_size = 7, array3_size = 5, array4_size = 10, array5_size=10;
	int array1[array1_size] = { 1,4,9,16,25,36,49,64,81 }, array2[array2_size] = { 8,7,6,1,0,9,2 }, array3[array3_size] = { -2,45,0,11,-9 }, array4[array4_size] = {-153,56,84,9251,-84,2,7,5,3718,78};
	char array5[array5_size] = { 'a','c','u','q','t','e','b','a','u','z' };
	//Different algorithms

	//BinarySearch
	cout << "Algorithms:\n\n";
	cout << "BinarySearch:\n\t";
	cout<<BinarySearch(array1, array1_size,required_el)<<endl;

	//QuickSort
	cout << "QuickSort:\n\tBefore: ";
	Show_Array_Int(array2, array2_size);
	cout << "\n\tAfter: ";
	QuickSort(array2, array2_size);
	Show_Array_Int(array2, array2_size);

	//BubbleSort
	cout << "\nBubbleSort:\n\tBefore: ";
	Show_Array_Int(array3, array3_size);
	cout << "\n\tAfter: ";
	BubbleSort(array3, array3_size);
	Show_Array_Int(array3, array3_size);

	//BogoSort
	cout << "\nBogoSort:\n\tBefore: ";
	Show_Array_Int(array4, array4_size);
	cout << "\n\tAfter: ";
	BogoSort(array4, array4_size);
	Show_Array_Int(array4, array4_size);

	//CountingSort
	cout << "\nCountingSort:\n\tBefore: ";
	Show_Array_Char(array5, array5_size);
	cout << "\n\tAfter: ";
	CountingSort(array5, array5_size);
	Show_Array_Char(array5, array5_size);

	//Comparison of algorithms
	ofstream out("Test_QuickSort 10.txt");
	int array[10];
	clock_t start, stop;
	for (int i = 0; i < 10; i++)
	{
		start = clock();
		for (int i = 0; i < 10; i++)
			array[i] = rand();
		QuickSort(array, 10);
		stop = clock();
		out << "\nRuntime: " << (stop-start) / 1000.0 << "\n\n\n";
	}
	out.close();
}

void Show_Array_Int(int* array, const int array_size)
{
	for (int i = 0; i < array_size; i++)
		cout << array[i] << ' ';
}

void Show_Array_Char(char* array, const int array_size)
{
	for (int i = 0; i < array_size; i++)
		cout << array[i] << ' ';
}