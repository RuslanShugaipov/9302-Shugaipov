#include <stdio.h>
#include <iostream>
#include "Sort_Search_Algorithms.h"

int BinarySearch(int* array, const int array_size, int required_el)
{
	int left = 0, right = array_size - 1, middle = ((left + right) / 2);
	if(array[middle]==required_el)
		printf("\t%s%d", "Index is: ", middle);
	else
	{
		while (array[middle] != required_el)
		{
			if (required_el < array[middle])
			{
				right = middle - 1;
				middle = ((left + right) / 2);
			}
			else if (required_el > array[middle])
			{
				left = middle + 1;
				middle = ((left + right) / 2);
			}
			if (required_el == array[middle])
			{
				printf("\t%s", "Index is: ");
				return middle;
			}
			if ((right == left && right == middle) && required_el != array[middle])
				break;
		}
    }
	if (required_el != array[middle])
	{
		printf("\t%s", "-1 - there is no such number: ");
		return -1;
	}
}

void QuickSort(int* array, int array_size)
{
	int i = 0, j = array_size - 1;
	int mid = array[array_size / 2];
	do
	{
		while (array[i] < mid)
			i++;
		while (array[j] > mid)
			j--;
		if (i <= j)
		{
			int temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			i++;
			j--;
		}
	} while (i <= j);
	if (j > 0)
		QuickSort(array, j + 1);
	if (i < array_size)
		QuickSort(&array[i], array_size - i);
}

void BubbleSort(int* array, int array_size)
{
	int j = array_size,temp;
	while (j > 0)
	{
		for (int i = 0; i < j-1; i++)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
			}
		}
		j--;
	}
}

int correct(int* array, int array_size)
{
	while (--array_size > 0)
		if (array[array_size - 1] > array[array_size])
			return 0;
	return 1;
}

void mix(int* array, int array_size)
{
	int temp,r;
	for (int i = 0; i < array_size; i++)
	{
		temp = array[i];
		r = rand() % array_size;
		array[i] = array[r];
		array[r] = temp;
	}
}

void BogoSort(int* array, int array_size)
{
	while (!correct(array, array_size))
		mix(array, array_size);
}

void CountingSort(char* array, int array_size)
{
	char max='a';
	for (int i = 0; i < array_size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	int *count=new int[int(max+1)];
	for (int i = 0; i <int(max + 1); i++)
	{
		count[i]=0;
	}
	for (int i = 0; i<array_size; i++)
	{
		count[int(array[i])]++;
	}
	int j = 0,q=0;

	for (int i = 0; i < int(max+1); i++)
	{
		if (count[i] == 0)
			continue;
		else
		{
			while (q < count[i])
			{
				array[j] = static_cast<char>(i);
				j++;
				q++;
			}
			q = 0;
		}
	}
	delete[] count;
}