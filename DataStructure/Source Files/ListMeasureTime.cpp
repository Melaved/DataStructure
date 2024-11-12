#include <iostream>
#include <chrono>
#include "..\header files\DoubleLinkedList.h"
using namespace std;

void measureInsertion(List* myList, int size)
{
    auto start = chrono::high_resolution_clock::now();

    for (int i = 0; i < size; ++i)
    {
        InsertAtEnd(myList, i); 
    }

    auto end = chrono::high_resolution_clock::now();

    chrono::duration<double> duration = end - start;

    cout << "Insertion time for size " << size << ": " << duration.count() << " seconds";

    for (int i = 0; i < size; ++i) 
    {
        RemoveAtIndex(myList, 0); 
    }
}


void measureDeletion(List* myList, int size)
{
    
    for (int i = 0; i < size; ++i)
    {
        InsertAtEnd(myList, i); 
    }

    auto start = chrono::high_resolution_clock::now();

    for (int i = 0; i < size; ++i)
    {
        RemoveAtIndex(myList, 0);
    }

    auto end = chrono::high_resolution_clock::now();

    chrono::duration<double> duration = end - start;

    cout << "Deletion time for size " << size << ": " << duration.count() << " seconds";
}