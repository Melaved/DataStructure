#include <iostream>
//TODO: remake
#include "..\Header Files\DynamicArray.h"
using namespace std;

int main()
{

    DynamicArray* myArray = CreateArray();

    //TODO: remove
    int choice;
    do {
        cout << "Current array:\n";
        Print(myArray);
        cout << "\nSelect the action you want to do:\n";
      
        cout << "1. Remove an element by index from an array\n";
        cout << "2. Remove an element by value from an array\n";
        cout << "3. Insert an element at the beginning\n";
        cout << "4. Insert an element at the end\n";
        cout << "5. Insert after a certain element\n";
        cout << "6. Sort array\n";
        cout << "7. Linear search for an element in an array\n";
        cout << "8. Binary search for an element in an array\n";
        cout << "0. Exit\n";
        cout << "Your input: ";
        cin >> choice;

        
        switch (choice) {
            
        case 1:
        {
            //TODO: duplication
            int index;
            cout << "Enter the index to delete: ";
            cin >> index;
            RemoveByIndex(myArray, index);
            break;
        }
        case 2:
        {
            //TODO: duplication
            int value;
            cout << "Enter the value to delete: ";
            cin >> value;
            RemoveByValue(myArray, value);
            break;
        }
        case 3:
        {
            //TODO: duplication
            int value;
            cout << "Enter the element to insert at the beginning: ";
            cin >> value;
            AddElement(myArray, 0, value);
            break;
        }
        case 4: 
        {
            //TODO: duplication
            int  value;
            cout << "Enter the element to insert at the end: " ;
            cin >> value;
            AddElement(myArray, myArray->Size, value);
            break;
        }
        case 5:
        {
            //TODO: rsdn
            int index, value;
            cout << "Enter index to insert: ";
            cin >> index;
            cout << "Enter the element to insert after a certain element: ";
            cin >> value;
            AddElement(myArray, index, value);
            break;
        }
        case 6: 
        {
            SortArray(myArray);
            cout << "The array is sorted. " << endl;
            break;
        }
        case 7: 
        {
            int value;
            cout << "Enter a value for a linear search: ";
            cin >> value;
            LinearSearch(myArray, value);
            break;
        }
        case 8:
        {
            int value;
            cout << "Enter a value for a binary search: ";
            cin >> value;
            BinarySearch(myArray, value);
            break;
        }
            //TODO: return 0
        }
        }
      
     

    
    while (choice != 0);

    FreeArray(myArray);
}
