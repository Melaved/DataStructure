#include <iostream>
#include "..\header files\DoubleLinkedList.h";
#include "..\header files\ListMeasureTime.h";
#include <string>
#include <limits>

using namespace std;

//! brief Prompts the user for input and retrieves an integer value.
//! param prompt A string containing the text of the prompt to display to 
//! the user.
//! return The integer value entered by the user.
int GetInput(const string& prompt)
{
    int value;
    string input;

    while (true)
    {
        cout << prompt;
        getline(cin, input);

        try
        {
            value = stoi(input);
            return value;
        }
        catch (const invalid_argument& e)
        {
            cout << "Invalid input. Please enter an integer value.\n";
        }
        catch (const out_of_range& e)
        {
            cout << "Input is out of range. Please enter a valid integer value.\n";
        }
    }
}

//! brief Prints the elements of the double linked list to the console.
//! param list Pointer to the list to be printed.
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
        cout << "Current List:\n ";
        PrintList(myList);


        cout << "Select the action you want to do\n";
        cout << "1. remove an element by index from an list\n";
        cout << "2. remove an element by value from an list\n";
        cout << "3. insert an element at the beginning\n";
        cout << "4. insert an element at the end\n";
        cout << "5. insert after a certain element\n";
        cout << "6. insert before a certain element\n";
        cout << "7. sort list\n";
        cout << "8. linear search for an element in an array\n";
        cout << "9. measure insertion time\n";
        cout << "10. measure deletion time\n";
        cout << "0. exit\n";

        int choice = GetInput("your input: ");

        switch (choice)
        {
        case 1:
        {
            int index = GetInput("Enter the index to delete: ");

            RemoveAtIndex(myList, index);

            break;
        }
        case 2:
        {
            int value = GetInput("Enter the value to delete: ");

            RemoveAtValue(myList, value);

            break;
        }
        case 3:
        {
            int value = GetInput("Enter the element to insert at the beginning: ");

            InsertAtBeginning(myList, value);

            break;
        }
        case 4:
        {
            int value = GetInput("Enter the element to insert at the end: ");

            InsertAtEnd(myList, value);

            break;
        }
        case 5:
        {
            int index = GetInput("Enter index to insert: ");

            int value = GetInput("Enter the element to insert after a certain element: ");

            InsertAfter(myList, index, value);

            break;
        }
        case 6:
        {
            int index = GetInput("Enter index to insert: ");

            int value = GetInput("Enter the element to insert after a certain element: ");

            InsertBefore(myList, index, value);

            break;
        }
        case 7:
        {
            SortList(myList);

            cout << "The list is sorted." << endl;

            break;
        }
        case 8:
        {
            int value = GetInput("Enter a value for a binary search: ");


            if (LinearSearch(myList, value))
            {
                cout << "Element found\n";
            }
            else
            {
                cout << "Element not found\n";
            }

            break;
        }
        case 9:
        {
            int size = GetInput("Enter the size for insertion measurement: ");

            measureInsertion(myList, size);

            cout << endl;

            break;
        }
        case 10:
        {
            int size = GetInput("Enter the size for deletion measurement: ");

            measureDeletion(myList, size);

            cout << endl;

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