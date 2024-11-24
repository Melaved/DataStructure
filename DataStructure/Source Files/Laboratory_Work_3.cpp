#include <iostream>
#include "..\header files\Stack.h"
#include "..\header files\CircularBuffer.h"
#include "..\header files\QueueByBuffer.h"
#include "..\header files\QueueByStacks.h"
#include <string>
using namespace std;

//! \brief Display main menu
void ShowMainMenu() 
{
    cout << "Main Menu:\n";
    cout << "1. Stack\n";
    cout << "2. Circular Buffer\n";
    cout << "3. Queue from Circular Buffer\n";
    cout << "4. Queue from Stacks\n";
    cout << "0. Exit\n";
}

//! \brief Display stack menu
void ShowStackMenu() 
{
    cout << "Stack Menu:\n";
    cout << "1. Push\n";
    cout << "2. Pop\n";
    cout << "3. Resize Stack\n";
    cout << "0. Back to Main Menu\n";
}

//! \brief Display circular buffer menu
void ShowCircularBufferMenu() 
{
    cout << "Circular Buffer Menu:\n";
    cout << "1. Add to Buffer\n";
    cout << "2. Remove from Buffer\n";
    cout << "0. Back to Main Menu\n";
}

//! \brief Display queue menu
void ShowQueueMenu() 
{
    cout << "Queue Menu:\n";
    cout << "1. Enqueue\n";
    cout << "2. Dequeue\n";
    cout << "0. Back to Main Menu\n";
}

//! \brief Prints the elements of the stack list to the console.
//! \param stack Pointer to the stack to be printed.
void PrintStack(Stack* stack) 
{
    if (IsEmpty(stack)) 
    {
        cout << "Stack is empty.\n";
        return;
    }

    cout << "Stack elements: ";
    for (int i = stack->Top; i >= 0; i--) 
    {
        cout << stack->Buffer[i] << " ";
    }
    cout << "\n";
}

//! \brief Prints the elements of the circular buffer to the console.
//! \param buffer Pointer to the buffer to be printed.
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
    } 
    while (currentIndex != buffer->Tail);
    cout << "\n";
}

//! \brief Prints the elements of the queue by circular buffer list to the console.
//! \param queue Pointer to the queue to be printed.
void PrintQueueByBuffer(QueueByBuffer* queue) 
{
    if (!queue->Buffer)
    {
        cout << "Queue is empty.\n";
        return;
    }

    PrintCircularBuffer(queue->Buffer);
}
//! \brief Prints the elements of queue by two stacks to the console.
//! \param queue Pointer to the queue to be printed.
void PrintQueueByStacks(QueueByStacks* queue) 
{
    Stack* tempStack = CreateStack();
    cout << "Queue elements: ";

    while (!IsEmpty(queue->OutStack)) 
    {
        int element = Pop(queue->OutStack);
        std::cout << element << ' ';
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

//! \brief Prompts the user for input and retrieves an integer value.
//! \param prompt A string containing the text of the prompt to display to 
//! the user.
//! \return The integer value entered by the user.
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

//! \brief Clear any menu
void ClearScreen() 
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

int main() 
{
    Stack* stack = CreateStack();
    CircularBuffer* circularBuffer = CreateCircularBuffer();
    QueueByBuffer* queueByBuffer= CreateQueueByBuffer();
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
            while (true) 
            {
                ClearScreen();
                ShowStackMenu();
                PrintStack(stack);

                int stackChoice = GetInput("Your input: ");

                switch (stackChoice) 
                {
                case 1: 
                { 
                    int data = GetInput("Enter value to push: ");
                    Push(stack,data);
                    break;
                }
                case 2: 
                { 
                    int poppedValue = Pop(stack);
                    if (poppedValue != -1) 
                    {
                        cout << "Popped: " << poppedValue << endl;
                    }
                    break;
                }
                case 3: 
                {
                    int newSize = GetInput("Enter new size: ");
                    Resize(stack, newSize);
                    break;
                }
           
                case 0: 
                    goto mainMenuReturnStack;
                default:
                    cout << "Invalid choice! Try again." << endl;
                }

                cout << "Press Enter to continue...";
                cin.ignore();
                cin.get();
            }
        mainMenuReturnStack:;
            break;
        }
        case 2: 
        { 
            while (true) 
            {
                ClearScreen();
                ShowCircularBufferMenu();
                PrintCircularBuffer(circularBuffer);
                cout << "Free space: " << FreeSpace(circularBuffer) << endl;
                cout << "Used space: " << OccupiedSpace(circularBuffer) << endl;

                int cbChoice = GetInput("Your input: ");

                switch (cbChoice) 
                {
                case 1: 
                { 
                    int data = GetInput("Enter value to add: ");
                    AddElement(circularBuffer, data);
                    break;
                }
                case 2: 
                { 
                    int removedValue = GetElement(circularBuffer);
                    if (removedValue != -1)
                    {
                        cout << "Removed: " << removedValue << endl;
                    }
                    break;
                }
                case 0:
                    goto mainMenuReturnCB;
                default:
                    cout << "Invalid choice! Try again." << endl;
                }
                cout << "Press Enter to continue...";
                cin.ignore();
                cin.get();
            }
        mainMenuReturnCB:;
            break;
        }
        case 3: 
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
                    Enqueue(queueByBuffer, data);
                    break;
                }
                case 2: 
                {
                    if (FreeSpace(queueByBuffer->Buffer) == 0)
                    {
                        cout << "Queue is full, cannot enqueue element: " << endl;
                        
                    }
                    int dequeuedValue = Dequeue(queueByBuffer);
                    if (dequeuedValue != -1) 
                    {
                        cout << "Dequeued: " << dequeuedValue << endl;
                    }
                    break;
                }
               
                case 0:
                    goto mainMenuReturnQueueByBuffer;
                default:
                    cout << "Invalid choice! Try again." << endl;
                }
                cout << "Press Enter to continue...";
                cin.ignore();
                cin.get();
            }
        mainMenuReturnQueueByBuffer:;
            break;
        }
        case 4:
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
                    goto mainMenuReturnQueueByStacks;
                default:
                    cout << "Invalid choice! Try again." << endl;
                }
                cout << "Press Enter to continue...";
                cin.ignore();
                cin.get();
   
            }
        mainMenuReturnQueueByStacks:;
            break;
        }
        case 0: 
            Delete(stack);
            Delete(circularBuffer);
            DeleteQueue(queueByBuffer);
            ClearQueue(queueByStacks);
            return 0;
        default:
            cout << "Invalid choice! Try again." << endl;
        }

    }
}
