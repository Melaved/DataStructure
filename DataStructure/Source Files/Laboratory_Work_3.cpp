#include "..\header files\Stack.h"
#include "..\header files\CircularBuffer.h"
#include "..\header files\QueueByBuffer.h"
#include "..\header files\QueueByStacks.h"
#include "..\header files\Stack_IO.h"
#include "..\header files\CircularBuffer_IO.h"
#include "..\header files\Queue_IO.h"
#include "..\header files\SupportMethods.h"
#include <iostream>
#include <string>
using namespace std;

int main() 
{
    Stack* stack = CreateStack();
    CircularBuffer* circularBuffer = CreateCircularBuffer();
    QueueByBuffer* queueByBuffer= CreateQueueByBuffer();
    QueueByStacks* queueByStacks = CreateQueueByStacks();
    bool running = true;

    while (running) 
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
                running = false;
                return 0;
            default:
                cout << "Invalid choice! Try again." << endl;
            }

    }
}
