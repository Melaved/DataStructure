#include <iostream>
#include <stdexcept>
using namespace std;


struct DynamicArray
{
	int Size;
	int Capacity;
	int* Array;

	void Resize(int NewCapacity) 
	{

		int* NewArray = new int[NewCapacity];
		for (int i = 0; i < Size; ++i)
		{
			NewArray[i] = Array[i];
		}
		delete[] Array;
		Array = NewArray;
		Capacity = NewCapacity;
	}

};

const int INITIAL_CAPACITY = 8;
const double GROWTH_FACTOR = 2;


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
	if (index < 0 || index > array->Size) {
		throw out_of_range("Index out of range");
	}
}

void AddElement(DynamicArray* array, int index, int value)
{
	CheckRange(array, index);

	if (array->Size >= array->Capacity) 
	{
		array->Resize(array->Capacity * GROWTH_FACTOR);
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
		array->Resize(array->Capacity / GROWTH_FACTOR);
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

int GetElement(DynamicArray* array, int index) {
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

void LinearSearch(DynamicArray* array, int value)
{
	for (int i = 0; i < array->Size; ++i) {
		if (array->Array[i] == value) {
			cout << "Element " << value << "found in index " << i << endl;
			break;
		}
	}
	cout << "Element " << value << " not found." << endl;
}




void BinarySearch(DynamicArray* array, int value) 
{
	SortArray(array);
	int first = 0;
	int last = array->Size - 1;
	while (first <= last) 
	{
		int mid = (first + last) / 2;
		if (array->Array[mid] == value)
		{
			cout << "Element " << value << " found in index " << mid << endl;
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
	cout << "Element " << value << " not found." << endl;
}

void FreeArray(DynamicArray* array) {
	delete[] array->Array;
	delete array;
}


void Print(DynamicArray* array) 
{
	for (int i = 0; i < array->Size; i++) {
		cout << array->Array[i] << ", ";
	}
	cout << endl;
}
