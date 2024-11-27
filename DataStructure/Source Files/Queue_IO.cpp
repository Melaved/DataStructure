#include <iostream>
#include "..\header files\CircularBuffer_IO.h"
#include "..\header files\QueueByBuffer.h"
#include "..\header files\QueueByStacks.h"
#include "../Header Files/SupportMethods.h"
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

void PrintQueueByStacks(QueueByStacks* queue)
{
    Stack* tempStack = CreateStack();
    cout << "Queue elements: ";

    while (!IsEmpty(queue->OutStack))
    {
        int element = Pop(queue->OutStack);
        cout << element << ' ';
        Push(tempStack, element);
    }

    while (!IsEmpty(queue->InStack))
    {
        int element = Pop(queue->InStack);
        cout << element << ' ';
        Push(tempStack, element);
    }

    while (!IsEmpty(tempStack))
    {
        int element = Pop(tempStack);
        Push(queue->OutStack, element);
    }

    Delete(tempStack);

    cout << '\n';
}

void QueueByBufferChoice(QueueByBuffer* queueByBuffer)
{
    bool running = true;
    while (running)
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
                running = false;

        default:
            cout << "Invalid choice! Try again." << endl;
        }
    }
}

void QueueByStacksChoice(QueueByStacks* queueByStacks)
{
    bool running = true;
    while (running)
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
                running = false;
                return;

        default:
            cout << "Invalid choice! Try again." << endl;
        }
    }
}