#include "..\Header Files\DynamicArray.h"
#include <stdexcept>
using namespace std;

void Resize(DynamicArray* array, int capacity)
{
	int* newArray = new int[capacity];
	for (int i = 0; i < array->Size; ++i)
	{
		newArray[i] = array->Array[i];
	}
	delete[] array->Array;
	array->Array = newArray;
	array->Capacity = capacity;
}

DynamicArray* CreateArray()
{
	DynamicArray* array = new DynamicArray;
	array->Size = 0;
	array->Capacity = INITIAL_CAPACITY;
	array->Array = new int[array->Capacity];
	return array;
};

void CheckRange(DynamicArray* array, int index) 
{
	if (index < 0 || index > array->Size) 
	{
		throw out_of_range("Index out of range");
	}
}

void AddElement(DynamicArray* array, int index, int value)
{
	CheckRange(array, index);

	if (array->Size >= array->Capacity) 
	{
		Resize(array,array->Capacity * GROWTH_FACTOR);
	}
	for (int i = array->Size; i > index; --i)
	{
		array->Array[i] = array->Array[i - 1];
	}
	array->Array[index] = value;
	++array->Size;
};

void RemoveByIndex(DynamicArray* array, int index) 
{
	CheckRange(array, index);

	for (int i = index; i < array->Size - 1; ++i)
	{
		array->Array[i] = array->Array[i + 1];
	}

	--array->Size;

	if (array->Size < array->Capacity / GROWTH_FACTOR && array->Capacity > INITIAL_CAPACITY)
	{
		Resize(array, array->Capacity / GROWTH_FACTOR);
	}
}

void RemoveByValue(DynamicArray* array, int value) 
{
	for (int i = 0; i < array->Size; ++i) 
	{
		if (array->Array[i] == value) 
		{
			RemoveByIndex(array, i);
			--i;
		}
	}
}

int GetElement(DynamicArray* array, int index) 
{
	CheckRange(array, index);
	return array->Array[index];
}


void SortArray(DynamicArray* array)
{
	for (int i = 1; i < array->Size; ++i)
	{
		int key = array->Array[i];
		int j = i - 1;
		while (j >= 0 && array->Array[j] > key) 
		{
			array->Array[j + 1] = array->Array[j];
			--j;
		}
		array->Array[j + 1] = key;
	}
}

int LinearSearch(DynamicArray* array, int value)
{
	for (int i = 0; i < array->Size; ++i) 
	{
		if (array->Array[i] == value) 
		{
			return i; 
		}
	}
	return -1; 
}

int BinarySearch(DynamicArray* array, int value) 
{
	SortArray(array); 
	int first = 0;
	int last = array->Size - 1;

	while (first <= last) 
	{
		int mid = (first + last) / 2;
		if (array->Array[mid] == value)
		{
			return mid;
		}
		if (value < array->Array[mid])
		{
			last = mid - 1;
		}
		else
		{
			first = mid + 1;
		}
	}
	return -1; 
}

void FreeArray(DynamicArray* array) 
{
	delete[] array->Array;
	delete array;
}



