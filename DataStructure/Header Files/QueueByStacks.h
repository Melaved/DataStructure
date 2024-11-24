#include "../header files/Stack.h"

//! \brief Structure representing a queue implemented using two stacks
struct QueueByStacks
{ 
    Stack* InStack;

    Stack* OutStack;
};

//! \brief Function to create a new instance of QueueByStacks
//! \return Pointer to the newly created QueueByStacks instance.
QueueByStacks* CreateQueueByStacks();

//! \brief Initializes the input and output stacks for the queue.
//! param queue Pointer to the QueueByStacks instance to be initialized.
//! param size The size of the stacks.
void InitStackQueues(QueueByStacks* queue, int size);

//! \brief Checks if the queue is empty.
//! param queue Pointer to the QueueByStacks instance to check.
//! \return True if the queue is empty, false otherwise.
bool IsStackQueueEmpty(const QueueByStacks* queue);

//! \brief Adds an element to the end of the queue.
//! param queue Pointer to the QueueByStacks instance where the element will be added.
//! param data The value to be added to the queue.
void Enqueue(QueueByStacks* queue, int data);

//! \brief Removes and returns the first element from the queue.
//! param queue Pointer to the QueueByStacks instance from which the element will be removed.
//! \return Value of the removed element.
int Dequeue(QueueByStacks* queue);

//! \brief Clears the queue by deleting both stacks.
//! param queue Pointer to the QueueByStacks instance that needs to be cleared.
void ClearQueue(QueueByStacks* queue);