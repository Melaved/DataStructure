//#include <iostream>
//#include "..\header files\dynamicarray.h"
//using namespace std;
//
////! \brief задает значение по запросу.
////! \param prompt строка, содержащая текст запроса для ввода.
//int getinput(const string& prompt) 
//{
//    int value;
//    cout << prompt;
//    cin >> value;
//    return value;
//}
//
////! \brief выводит результат поиска индекса.
////! \param index индекс элемента, полученный в результате поиска.
//void printindexresult(int index) 
//{
//    if (index != -1)
//    {
//        cout << "element found at index: " << index << endl;
//    }
//    else
//    {
//        cout << "element not found." << endl;
//    }
//}
//
//int main() 
//{
//    dynamicarray* myarray = createarray();
//    
//
//    while (true)
//    {
//        cout << "current array\n";
//        for (int i = 0; i < myarray->size; i++) 
//        {
//            cout << myarray->array[i] << ", ";
//        }
//        cout << endl;
//       
//        cout << "select the action you want to do\n";
//        cout << "1. remove an element by index from an array\n";
//        cout << "2. remove an element by value from an array\n";
//        cout << "3. insert an element at the beginning\n";
//        cout << "4. insert an element at the end\n";
//        cout << "5. insert after a certain element\n";
//        cout << "6. sort array\n";
//        cout << "7. linear search for an element in an array\n";
//        cout << "8. binary search for an element in an array\n";
//        cout << "0. exit\n";
//        
//        int choice = getinput("your input: ");
//
//        switch (choice) 
//        {
//            case 1: 
//            {
//                int index = getinput("enter the index to delete: ");
//                removebyindex(myarray, index);
//                break;
//            }
//            case 2: 
//            {
//                int value = getinput("enter the value to delete: ");
//                removebyvalue(myarray, value);
//                break;
//            }
//            case 3:
//            {
//                int value = getinput("enter the element to insert at the beginning: ");
//                addelement(myarray, 0, value);
//                break;
//            }
//            case 4: 
//            {
//                int value = getinput("enter the element to insert at the end: ");
//                addelement(myarray, myarray->size, value);
//                break;
//            }
//            case 5:
//            {
//                int index = getinput("enter index to insert: ");
//                int value = getinput("enter the element to insert after a certain element: ");
//                addelement(myarray, index, value);
//                break;
//            }
//            case 6:
//            {
//                sortarray(myarray);
//                cout << "the array is sorted." << endl;
//                break;
//            }
//            case 7: 
//            {
//                int value = getinput("enter a value for a linear search: ");
//                int index = linearsearch(myarray, value);
//
//                printindexresult(index);
//                break;
//            }
//            case 8:
//            {
//                int value = getinput("enter a value for a binary search: ");
//                int index = binarysearch(myarray, value);
//
//                printindexresult(index);
//                break;
//            }
//            case 0:
//            {
//                freearray(myarray);
//                return 0;
//            }
//            default:
//                cout << "invalid choice. please try again." << endl;
//            }
//    }
//}