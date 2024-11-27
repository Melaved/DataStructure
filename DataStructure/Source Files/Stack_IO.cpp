#include <iostream>
#include "..\header files\Stack.h"
#include "..\header files\SupportMethods.h"
using namespace std;


void ShowStackMenu()
{
    cout << "Stack Menu:\n";
    cout << "1. Push\n";
    cout << "2. Pop\n";
    cout << "3. Resize Stack\n";
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

void StackChoice(Stack* stack) 
{
    bool running = true;
    while (running) 
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
                Push(stack, data);
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
            {
                ClearScreen();
                ShowMainMenu();
                running = false;
                break;
            }

        default:
            cout << "Invalid choice! Try again." << endl;
        }
        //ContinueCheck();
    }
}
