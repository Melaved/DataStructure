#include "../header files/Stack.h"

// Structure representing a queue implemented using two stacks
struct QueueByStacks
{
    // Pointer to the input stack
    Stack* InStack;

    // Pointer to the output stack
    Stack* OutStack;
};

// Function to create a new instance of QueueByStacks
QueueByStacks* CreateQueueByStacks();

// Function to add an element to the queue
void Enqueue(QueueByStacks* queue, int data);

// Function to remove and return the first element from the queue
int Dequeue(QueueByStacks* queue);

// Function to check if the queue is empty
//bool IsEmptyQueue(QueueByStacks* queue);

// Function to clear the queue by deleting both stacks
void ClearQueue(QueueByStacks* queue);


