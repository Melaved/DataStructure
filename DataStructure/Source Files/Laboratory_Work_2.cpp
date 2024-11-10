#include <iostream>
#include "DoublyLinkedList.cpp"
#include "..\header files\doublelinkedlist.h"
using namespace std;

//! \brief задает значение по запросу.
//! \param prompt строка, содержащая текст запроса для ввода.
int getinput(const string& prompt)
{
    int value;
    cout << prompt;
    cin >> value;
    return value;
}

//! \brief выводит результат поиска индекса.
//! \param index индекс элемента, полученный в результате поиска.
void printindexresult(int index) 
{
    if (index != -1)
    {
        cout << "element found at index: " << index << endl;
    }
    else
    {
        cout << "element not found." << endl;
    }
}

void PrintList(List* list)
{
    if (list == nullptr || list->Head == nullptr) 
    {
        cout << "The list is empty." << endl;
        return;
    }

    Node* current = list->Head;

    while (current != nullptr)
    {
        cout << current->Data << " ";
        current = current->Next;
    }

    cout << endl;
}

int main()
{
    List* myList = new List();

    while (true)
    {
        cout << "Current NodeList:\n ";
        PrintList(myList);


        cout << "Select the action you want to do\n";
        cout << "1. remove an element by index from an list\n";
        cout << "2. remove an element by value from an list\n";
        cout << "3. insert an element at the beginning\n";
        cout << "4. insert an element at the end\n";
        cout << "5. insert after a certain element\n";
        cout << "6. sort list\n";
        cout << "7. linear search for an element in an list\n";
        cout << "8. binary search for an element in an array\n";
        cout << "0. exit\n";

        int choice = getinput("your input: ");

        switch (choice)
        {
        case 1:
        {
            int index = getinput("Enter the index to delete: ");
            RemoveAtIndex(myList, index);
            break;
        }
        case 2:
        {
            int value = getinput("Enter the value to delete: ");
            RemoveAtValue(myList, value);
            break;
        }
        case 3:
        {
            int value = getinput("Enter the element to insert at the beginning: ");
            InsertAtBeginning(myList, value);
            break;
        }
        case 4:
        {
            int value = getinput("Enter the element to insert at the end: ");
            InsertAtEnd(myList, value);
            break;
        }
        case 5:
        {
            int index = getinput("Enter index to insert: ");
            int value = getinput("Enter the element to insert after a certain element: ");
            InsertAfter(myList, index, value);
            break;
        }
        case 6:
        {
            SortList(myList);
            cout << "The list is sorted." << endl;
            break;
        }
        case 7:
        {
            int value = getinput("enter a value for a linear search: ");
            int index = LinearSearch(myList, value);

            break;
        }
        case 8:
        {
            int value = getinput("Enter a value for a binary search: ");
            
            
            if (LinearSearch(myList, value)) {
                cout << "Element found\n";
            }
            else {
                cout << "Element not found\n";
            }
            break;
        }
        case 0:
        {
            ClearList(myList);
            return 0;
        }
        default:
            cout << "invalid choice. please try again." << endl;
        }
    }
}