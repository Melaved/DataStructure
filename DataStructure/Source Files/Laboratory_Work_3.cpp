#include <iostream>
#include "..\header files\Stack.h";
#include "..\header files\CircularBuffer.h";
#include "..\header files\QueueByBuffer.h";
#include "..\header files\QueueByStacks.h";
#include <string>
using namespace std;

void ShowMainMenu() 
{
    cout << "Main Menu:\n";
    cout << "1. Stack\n";
    cout << "2. Circular Buffer\n";
    cout << "3. Queue from Circular Buffer\n";
    cout << "0. Exit\n";
}

void ShowStackMenu() 
{
    cout << "Stack Menu:\n";
    cout << "1. Push\n";
    cout << "2. Pop\n";
    cout << "3. Resize Stack\n";
    cout << "4. Check if Empty\n";
    cout << "5. Check if Full\n";
    cout << "0. Back to Main Menu\n";
}

void ShowCircularBufferMenu() 
{
    cout << "Circular Buffer Menu:\n";
    cout << "1. Add to Buffer\n";
    cout << "2. Remove from Buffer\n";
    cout << "3. Get Free Space\n";
    cout << "4. Get Used Space\n";
    cout << "0. Back to Main Menu\n";
}

void ShowQueueByBufferMenu() 
{
    cout << "Queue Menu:\n";
    cout << "1. Enqueue\n";
    cout << "2. Dequeue\n";
    cout << "3. Resize Queue\n";
    cout << "0. Back to Main Menu\n";
}

void ShowQueueByStacksMenu()
{
    cout << "Queue Menu:\n";
    cout << "1. Enqueue\n";
    cout << "2. Dequeue\n";
    cout << "3. Resize Queue\n";
    cout << "0. Back to Main Menu\n";
}

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

void PrintQueue(QueueByBuffer* queue) 
{
    if (!queue->Buffer)
    {
        cout << "Queue is empty.\n";
        return;
    }

    PrintCircularBuffer(queue->Buffer);
}

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
    QueueByBuffer* queue= CreateQueueByBuffer();

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
                    int newSize;
                    cout << "Enter new size: ";
                    cin >> newSize;
                    Resize(stack, newSize);
                    break;
                }
                case 4: 
                {
                    cout << (IsEmpty(stack) ? "Stack is empty." : "Stack is not empty.") << endl;
                    break;
                }
                case 5:
                {
                    cout << (IsFull(stack) ? "Stack is full." : "Stack is not full.") << endl;
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

                int cbChoice = GetInput("Your input: ");

                switch (cbChoice) 
                {
                case 1: 
                { 
                    int data;
                    cout << "Enter value to add: ";
                    cin >> data;
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
                case 3: 
                { 
                    cout << "Free space: " << FreeSpace(circularBuffer) << endl;
                    break;
                }
                case 4: 
                {
                    cout << "Used space: " << OccupiedSpace(circularBuffer) << endl;
                    break;
                }
                case 0:
                    goto mainMenuReturnCB;
                default:
                    std::cout << "Invalid choice! Try again." << std::endl;
                }

                std::cout << "Press Enter to continue...";
                std::cin.ignore();
                std::cin.get();
            }
        mainMenuReturnCB:;
            break;
        }
        case 3: 
        {
            while (true) 
            {
                ClearScreen();
                ShowQueueByBufferMenu();
                PrintQueue(queue);

                int queueChoice = GetInput("Your input: ");
 
                switch (queueChoice) 
                {
                case 1:
                { 
                    int data;
                    cout << "Enter value to enqueue: ";
                    cin >> data;
                    Enqueue(queue, data);
                    break;
                }
                case 2: 
                {
                    int dequeuedValue = Dequeue(queue);
                    if (dequeuedValue != -1) 
                    {
                        cout << "Dequeued: " << dequeuedValue << endl;
                    }
                    break;
                }
                case 3:
                {
                    int newSize;
                    cout << "Enter new size: ";
                    cin >> newSize;
                    //ResizeQueue(queue, newSize);
                    break;
                }
                case 0:
                    goto mainMenuReturnQueue;
                default:
                    cout << "Invalid choice! Try again." << endl;
                }

                cout << "Press Enter to continue...";
                cin.ignore();
                cin.get();
            }
        mainMenuReturnQueue:;
            break;
        }
        case 0: // Exit
            Delete(stack);
            Delete(circularBuffer);
            DeleteQueue(queue);
            return 0;
        default:
            cout << "Invalid choice! Try again." << endl;
        }

        cout << "Press Enter to continue...";
        cin.ignore();
        cin.get();
    }

    return 0;
}
