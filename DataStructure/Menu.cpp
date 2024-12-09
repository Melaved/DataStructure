#include "Header Files/Stack.h"
#include "Header Files/CircularBuffer.h"
#include "Header Files/QueueByStacks.h"
#include "Header Files/QueueByBuffer.h"
#include "Header Files/SupportMethods.h"
#include "Header Files/Stack_IO.h"
#include "Header Files/CircularBuffer_IO.h"
#include "Header Files/Queue_IO.h"


void ShowMainMenu()
{
    cout << "Main Menu:\n";
    cout << "1. Stack\n";
    cout << "2. Circular Buffer\n";
    cout << "3. Queue from Circular Buffer\n";
    cout << "4. Queue from Stacks\n";
    cout << "0. Exit\n";
}

void Menu() 
{
    Stack* stack = CreateStack();
    CircularBuffer* circularBuffer = CreateCircularBuffer();
    QueueByBuffer* queueByBuffer = CreateQueueByBuffer();
    QueueByStacks* queueByStacks = CreateQueueByStacks();

    while (true)
    {
        ClearScreen();
        ShowMainMenu();

        int choice = GetInput("Your input: ");

        switch (choice)
        {
            case 1:
            {

                StackChoice(stack);
                break;
            }

            case 2:
            {

                CircularBufferShoice(circularBuffer);
                break;
            }

            case 3:
            {

                QueueByBufferChoice(queueByBuffer);
                break;

            }

            case 4:
            {

                QueueByStacksChoice(queueByStacks);
                break;

            }

            case 0:
                Delete(stack);
                Delete(circularBuffer);
                DeleteQueue(queueByBuffer);
                ClearQueue(queueByStacks);
                return;
                break;
        default:
            cout << "Invalid choice! Try again." << endl;
        }
    }
}