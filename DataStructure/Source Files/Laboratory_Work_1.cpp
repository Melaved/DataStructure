//#include <iostream>
//#include "..\Header Files\DynamicArray.h"
//using namespace std;
//
////! \brief Задает значение по запросу.
////! \param prompt Строка, содержащая текст запроса для ввода.
//int GetInput(const string& prompt) 
//{
//    int value;
//    cout << prompt;
//    cin >> value;
//    return value;
//}
//
////! \brief Выводит результат поиска индекса.
////! \param index Индекс элемента, полученный в результате поиска.
//void PrintIndexResult(int index) 
//{
//    if (index != -1)
//    {
//        cout << "Element found at index: " << index << endl;
//    }
//    else
//    {
//        cout << "Element not found." << endl;
//    }
//}
//
//int main() 
//{
//    DynamicArray* myArray = CreateArray();
//    
//
//    while (true)
//    {
//        cout << "Current array\n";
//        for (int i = 0; i < myArray->Size; i++) 
//        {
//            cout << myArray->Array[i] << ", ";
//        }
//        cout << endl;
//       
//        cout << "Select the action you want to do\n";
//        cout << "1. Remove an element by index from an array\n";
//        cout << "2. Remove an element by value from an array\n";
//        cout << "3. Insert an element at the beginning\n";
//        cout << "4. Insert an element at the end\n";
//        cout << "5. Insert after a certain element\n";
//        cout << "6. Sort array\n";
//        cout << "7. Linear search for an element in an array\n";
//        cout << "8. Binary search for an element in an array\n";
//        cout << "0. Exit\n";
//        
//        int choice = GetInput("Your input: ");
//
//        switch (choice) 
//        {
//            case 1: 
//            {
//                int index = GetInput("Enter the index to delete: ");
//                RemoveByIndex(myArray, index);
//                break;
//            }
//            case 2: 
//            {
//                int value = GetInput("Enter the value to delete: ");
//                RemoveByValue(myArray, value);
//                break;
//            }
//            case 3:
//            {
//                int value = GetInput("Enter the element to insert at the beginning: ");
//                AddElement(myArray, 0, value);
//                break;
//            }
//            case 4: 
//            {
//                int value = GetInput("Enter the element to insert at the end: ");
//                AddElement(myArray, myArray->Size, value);
//                break;
//            }
//            case 5:
//            {
//                int index = GetInput("Enter index to insert: ");
//                int value = GetInput("Enter the element to insert after a certain element: ");
//                AddElement(myArray, index, value);
//                break;
//            }
//            case 6:
//            {
//                SortArray(myArray);
//                cout << "The array is sorted." << endl;
//                break;
//            }
//            case 7: 
//            {
//                int value = GetInput("Enter a value for a linear search: ");
//                int index = LinearSearch(myArray, value);
//
//                PrintIndexResult(index);
//                break;
//            }
//            case 8:
//            {
//                int value = GetInput("Enter a value for a binary search: ");
//                int index = BinarySearch(myArray, value);
//
//                PrintIndexResult(index);
//                break;
//            }
//            case 0:
//            {
//                FreeArray(myArray);
//                return 0;
//            }
//            default:
//                cout << "Invalid choice. Please try again." << endl;
//            }
//    }
//}