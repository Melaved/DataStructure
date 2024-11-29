#include <iostream>
#include "..\header files\CircularBuffer.h"
#include "../Header Files/SupportMethods.h"

using namespace std;

void ShowCircularBufferMenu()
{
    cout << "Circular Buffer Menu:\n";
    cout << "1. Add to Buffer\n";
    cout << "2. Remove from Buffer\n";
    cout << "0. Back to Main Menu\n";
}

void PrintCircularBuffer(CircularBuffer* buffer)
{
    if (OccupiedSpace(buffer) == 0)
    {
        cout << "Buffer is empty.\n";
        return;
    }

    cout << "List of elements: ";
    int currentIndex = buffer->Head;
    do
    {
        cout << buffer->Buffer[currentIndex] << " ";
        currentIndex = (currentIndex + 1) % buffer->BufferSize;
    } while (currentIndex != buffer->Tail);
    cout << "\n";
}

void CircularBufferShoice(CircularBuffer* buffer) 
{
    bool running = true;
    while (running)
    {
        ClearScreen();
        ShowCircularBufferMenu();
        PrintCircularBuffer(buffer);
        cout << "Free space: " << FreeSpace(buffer) << endl;
        cout << "Used space: " << OccupiedSpace(buffer) << endl;
        int cbChoice = GetInput("Your input: ");

        switch (cbChoice)
        {

            case 1:
            {
                int data = GetInput("Enter value to add: ");
                AddElement(buffer, data);
                break;
            }

            case 2:
            {
                int removedValue = GetElement(buffer);
                if (removedValue != -1)
                {
                    cout << "Removed: " << removedValue << endl;
                }
                break;
            }

            case 0:

                ClearScreen();
                ShowMainMenu();
                running = false;
                return;

        default:
            cout << "Invalid choice! Try again." << endl;
        }
        ContinueCheck();
    }
}