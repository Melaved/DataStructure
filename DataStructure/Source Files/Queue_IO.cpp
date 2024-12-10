#include <iostream>
#include "..\header files\CircularBuffer_IO.h"
#include "..\header files\QueueByBuffer.h"
#include "..\header files\QueueByStacks.h"
#include "../Header Files/SupportMethods.h"
#include "../Menu.h"
using namespace std;

void ShowQueueMenu()
{
    cout << "Queue Menu:\n";
    cout << "1. Enqueue\n";
    cout << "2. Dequeue\n";
    cout << "0. Back to Main Menu\n";
}

void PrintQueueByBuffer(QueueByBuffer* queue)
{
    if (!queue->Buffer)
    {
        cout << "Queue is empty.\n";
        return;
    }

    PrintCircularBuffer(queue->Buffer);
}

#include <iostream>

void PrintStackForQueue(Stack* stack) 
{
    if (stack == nullptr) 
    {
        cout << "Stack is null." << endl;
        return;
    }

    if (IsEmpty(stack)) 
    {
        cout << "Stack is empty." << endl;
        return;
    }

    Stack* temp = CreateStack();
    cout << "Stack contents: ";
    while (!IsEmpty(stack)) 
    {
        int value = Pop(stack);
        cout << value << " ";
        Push(temp, value); 
    }
    cout << endl;

    while (!IsEmpty(temp)) 
    {
        Push(stack, Pop(temp));
    }

    Delete(temp); 
}

void PrintQueueByStacks(QueueByStacks* queue)
{
    if (queue == nullptr) 
    {
        cout << "Queue is null." << endl;
        return;
    }

    cout << "InStack: ";
    PrintStackForQueue(queue->InStack);

    cout << "OutStack: ";
    PrintStackForQueue(queue->OutStack);
}


void QueueByBufferChoice(QueueByBuffer* queueByBuffer)
{
    while (true)
    {
        ClearScreen();
        ShowQueueMenu();
        PrintQueueByBuffer(queueByBuffer);
        int queueByBufferChoice = GetInput("Your input: ");
        switch (queueByBufferChoice)
        {

            case 1:
            {
                int data = GetInput("Enter value to enqueue: ");
                if (FreeSpace(queueByBuffer->Buffer) == 0)
                {
                    cout << "Queue is full, please dequeue element: " << endl;
                }
                Enqueue(queueByBuffer, data);
                break;
            }

            case 2:
            {
                int dequeuedValue = Dequeue(queueByBuffer);
                if (dequeuedValue != -1)
                {
                    cout << "Dequeued: " << dequeuedValue << endl;
                }
                break;
            }

            case 0:

                ClearScreen();
                ShowMainMenu();
                return;
                break;

        default:
            cout << "Invalid choice! Try again." << endl;
        }
        ContinueCheck();
    }
}

void QueueByStacksChoice(QueueByStacks* queueByStacks)
{
    while (true)
    {
        ClearScreen();
        ShowQueueMenu();
        PrintQueueByStacks(queueByStacks);
        int queueByStacksChoice = GetInput("Your input: ");


        switch (queueByStacksChoice)
        {

            case 1:
            {
                int data = GetInput("Enter value to enqueue: ");
                Enqueue(queueByStacks, data);
                break;
            }

            case 2:
            {
                int dequeuedValue = Dequeue(queueByStacks);
                cout << "Dequeued: " << dequeuedValue << endl;
                break;
            }

            case 0:

                ClearScreen();
                ShowMainMenu();
                return;
                break;

        default:
            cout << "Invalid choice! Try again." << endl;
        }
        ContinueCheck();
    }
}